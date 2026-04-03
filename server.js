const express = require('express');
const path = require('path');
const { spawn } = require('child_process');
const rateLimit = require('express-rate-limit');
const mongoose = require('./ds');

const Patient = require('./models/patient');

const app = express();
const PORT = process.env.PORT || 3000;

// Configurable C++ binary path
const CPP_BINARY_PATH = process.env.CPP_BINARY_PATH
    ? path.resolve(process.env.CPP_BINARY_PATH)
    : path.join(__dirname, 'app');

const CPP_TIMEOUT_MS = 10000;

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

// Rate limiting for the find-donor route
const findDonorLimiter = rateLimit({
    windowMs: 60 * 1000,
    max: 20,
    standardHeaders: true,
    legacyHeaders: false,
    message: { error: 'Too many requests, please try again later.' }
});

app.post('/find-donor', findDonorLimiter, async (req, res) => {
    const { name, blood, location, urgency } = req.body;

    // Input validation
    if (!name || !blood || !location || urgency === undefined) {
        return res.status(400).json({ error: 'Missing required fields: name, blood, location, urgency' });
    }

    const urgencyInt = parseInt(urgency, 10);
    if (isNaN(urgencyInt) || urgencyInt < 1 || urgencyInt > 10) {
        return res.status(400).json({ error: 'urgency must be an integer between 1 and 10' });
    }

    try {
        // Save patient record
        const patient = new Patient({ name, blood, location, urgency: urgencyInt });
        await patient.save();

        // Spawn C++ binary with validated input
        const cppProcess = spawn(CPP_BINARY_PATH, []);

        let stdout = '';
        let stderr = '';
        let responded = false;

        // Enforce timeout by killing the process if it runs too long
        const timer = setTimeout(() => {
            cppProcess.kill();
            if (!responded) {
                responded = true;
                res.status(504).json({ error: 'Matching engine timed out' });
            }
        }, CPP_TIMEOUT_MS);

        cppProcess.stdin.write(`${name}\n${blood}\n${location}\n${urgencyInt}\n`);
        cppProcess.stdin.end();

        cppProcess.stdout.on('data', (data) => {
            stdout += data.toString();
        });

        cppProcess.stderr.on('data', (data) => {
            stderr += data.toString();
        });

        cppProcess.on('error', (err) => {
            clearTimeout(timer);
            if (!responded) {
                responded = true;
                res.status(500).json({ error: `Failed to start matching engine: ${err.message}` });
            }
        });

        cppProcess.on('close', (code) => {
            clearTimeout(timer);
            if (!responded) {
                responded = true;
                if (code !== 0) {
                    return res.status(500).json({ error: stderr || `Matching engine exited with code ${code}` });
                }
                return res.json({ result: stdout });
            }
        });
    } catch (err) {
        return res.status(500).json({ error: err.message });
    }
});

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
    console.log(`C++ binary path: ${CPP_BINARY_PATH}`);
});
