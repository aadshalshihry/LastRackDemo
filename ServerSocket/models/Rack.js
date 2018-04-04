const mongoose = require('mongoose');
const Schema = mongoose.Schema;
const Device = require('./Device');
// const autoIncrement = require('mongoose-auto-increment');
 
// const connection = mongoose.createConnection("mongodb://localhost/rack-db");
 
// autoIncrement.initialize(connection);

const schema = new mongoose.Schema({
  rackName: {
    type: String,
    required: true
  },
  rackId: {
  	type: Number,
  },
  deviceNum: {
    type: Number,
    default: 0
  }
}, {timestamps: true});

// Post save
schema.post('save', function(doc) {
  console.log('%s has been saved', doc._id);
});


// schema.plugin(autoIncrement.plugin, { model: 'Rack', field: 'rackId'});
// schema.collection.dropIndex('rackId');

module.exports = mongoose.model('Rack', schema);