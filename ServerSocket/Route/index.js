const express = require('express')
const mongoose = require('mongoose')
const Rack = require('../models/Rack')
const Device = require('../models/Device')
const VM = require('../models/VM')

const data = require('../seeds/data');
const fs = require('fs');

module.exports = function(app) {
	app.get('/racks', function(req, res) {
		Rack.find({}).exec(function(err, rack) {
			res.json({
				rack
			})
		});
	})

	app.get('/devices', function(req, res) {
		Device.find({}).exec(function(err, device) {
			res.json({
				device
			})
		});
	})

	app.get('/vms', function(req, res) {
		VM.find({}).exec(function(err, vm) {

			res.json({
				vm
			})
		});
	});

	app.get('/load_data', function (req, res) {
		fs.writeFile('data.txt', JSON.stringify(data), function (err) {
		  if (err) throw err;
		  console.log('Saved!');
		});
		res.json({
			data
		})
	})
}
