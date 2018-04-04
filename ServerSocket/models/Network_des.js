const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const schema = new mongoose.Schema({
  Host: {
    type: String,
    required: true
  },
  DNS1: {
    type: String,
    required: true
  },
  DNS2: {
    type: String,
    required: true
  },
  Processor: {
    type: String,
    enum: ['Online','Offline'],
    default: 'Online'
  },
  LanA: {
    type: String,
    enum: ['Online','Offline'],
    default: 'Online'
  },
  LanB: {
    type: String,
    enum: ['Online','Offline'],
    default: 'Online'
  },
  PUD: {
    type: String,
    required: true
  },
  PCOIP: {
    type: String,
    enum: ['Online','Offline'],
    default: 'Online'
  },
  Outline: {
    type: String,
    enum: ['Online','Offline'],
    default: 'Online'
  },

  rackId: {
    type: Number,
  },
  deviceId: {
    type: Number,
  }
}, {timestamps: true});


module.exports = mongoose.model('NetworkDes', schema);
