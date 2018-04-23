const mongoose = require('mongoose')

// const autoIncrement = require('mongoose-auto-increment');

// const connection = mongoose.createConnection("mongodb://localhost/rack-db");

// autoIncrement.initialize(connection);

const schema = new mongoose.Schema({
  vmName: {
    type: String,
    required: true
  },
  vmNum: {
    type: Number,
    default: 0
  },
  state: {
    type: String,
    enum: ['Faulted','Offline', 'Degraded', 'Disconnected', 'Operational'],
    default: 'Faulted'
  },
  rackId: {
    type: Number,
  },
  deviceId: {
    type: Number
  },
  vmId: {
    type: Number
  }
}, {timestamps: true});

// schema.plugin(autoIncrement.plugin, { model: 'VM', field: 'vmId'});

module.exports = mongoose.model('VM', schema);
