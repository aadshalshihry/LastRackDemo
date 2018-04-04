const mongoose = require('mongoose');
const Schema = mongoose.Schema;
const Rack = require('./Rack');

// const autoIncrement = require('mongoose-auto-increment');

// const connection = mongoose.createConnection("mongodb://localhost/rack-db");

// autoIncrement.initialize(connection);

const schema = new mongoose.Schema({
  deviceName: {
    type: String,
    required: true
  },
  vmNum: {
    type: Number,
    default: 0
  },
  state: {
    type: String,
    enum: ['Faulted','Offline', 'Degraded', 'Not Connected'],
    default: 'Faulted'
  },
  rackId: {
    type: Number,
  },
  deviceId: {
    type: Number,
  }
}, {timestamps: true});

// console.log(schema.collection);
// schema.collection.dropIndex('rackId');
// schema.plugin(autoIncrement.plugin, { model: 'Device', field: 'deviceId'});

module.exports = mongoose.model('Device', schema);
