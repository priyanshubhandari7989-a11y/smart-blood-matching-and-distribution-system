const mongoose = require('../ds');

const donorSchema = new mongoose.Schema({
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
    available: {
        type: Boolean,
        required: true,
        default: true
    }
}, { timestamps: true });

module.exports = mongoose.model('Donor', donorSchema);
