const mongoose = require("mongoose");

const donorSchema = new mongoose.Schema({
    name: String,
    blood: String,
    location: String,
    available: Boolean
});

const Donor = mongoose.model("Donor", donorSchema);

module.exports = Donor;