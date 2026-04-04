const mongoose = require("mongoose");

const patientSchema = new mongoose.Schema({
    name: String,
    blood: String,
    location: String,
    urgency: Number
});

const Patient = mongoose.model("Patient", patientSchema);

module.exports = Patient;