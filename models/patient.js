const mongoose = require('../ds');

const patientSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
        trim: true
    },
    blood: {
        type: String,
        required: true,
        trim: true
    },
    location: {
        type: String,
        required: true,
        trim: true
    },
    urgency: {
        type: Number,
        required: true,
        min: 1,
        max: 10
    }
}, { timestamps: true });

module.exports = mongoose.model('Patient', patientSchema);
