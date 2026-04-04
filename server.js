const express = require("express");
const { spawn } = require("child_process");

// ✅ Connect DB
require("./db");

// ✅ Models
const Patient = require("./models/patient");
const Donor = require("./models/donor");

const app = express();

app.use(express.json());
app.use(express.static("public"));

// ================= PATIENT ROUTES =================
// Create Patient
app.post("/patients", async (req, res) => {
    try {
        const patient = await Patient.create(req.body);
        res.status(201).json(patient);
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
});

// Get all Patients
app.get("/patients", async (req, res) => {
    try {
        const patients = await Patient.find();
        res.json(patients);
    } catch (err) {
        res.status(500).json({ error: err.message });
    }
});

// ================= DONOR ROUTES =================
// Create Donor
app.post("/donors", async (req, res) => {
    try {
        const donor = await Donor.create(req.body);
        res.status(201).json(donor);
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
});

// Get all Donors
app.get("/donors", async (req, res) => {
    try {
        const donors = await Donor.find();
        res.json(donors);
    } catch (err) {
        res.status(500).json({ error: err.message });
    }
});

// ================= RUN MATCH =================
app.post("/run", async (req, res) => {
    try {
        const { name, blood, location, urgency } = req.body;

        // ✅ Save patient to MongoDB
        await Patient.create({ name, blood, location, urgency });

        // ✅ Run C++ program
        const child = spawn("./app");

        let output = "";
        let errorOutput = "";

        child.stdout.on("data", (data) => {
            output += data.toString();
        });

        child.stderr.on("data", (data) => {
            errorOutput += data.toString();
        });

        child.on("close", () => {
            if (errorOutput) {
                console.error(errorOutput);
                return res.send("Error:\n" + errorOutput);
            }
            res.send(output);
        });

        // ✅ Send input to C++
        child.stdin.write(name + "\n");
        child.stdin.write(blood + "\n");
        child.stdin.write(location + "\n");
        child.stdin.write(urgency + "\n");
        child.stdin.end();

    } catch (err) {
        console.error("FULL ERROR:", err);
        res.send("ERROR:\n" + err.message);
    }
});

// ================= START SERVER =================
app.listen(3000, () => {
    console.log("🚀 Server running at http://localhost:3000");
});