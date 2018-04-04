var seeder = require('mongoose-seed');
const mongoose = require('mongoose');
const { Types } = require('mongoose')

const {data} = require('./data.js');


// Connect to MongoDB via Mongoose
  seeder.connect('mongodb://localhost/rack-db', function() {

    // Load Mongoose models
    seeder.loadModels([
      './models/Rack.js',
      './models/Device.js',
      './models/VM.js',
      './models/Network_des.js',
    ]);

    // Clear specified collections
    seeder.clearModels(['Rack', 'Device', 'VM', 'NetworkDes'], function() {

      // Callback to populate DB once collections have been cleared
      seeder.populateModels(data, function() {
        seeder.disconnect();
      });

    });
  });

// Data array containing seed data - documents organized by Model
// var data =
