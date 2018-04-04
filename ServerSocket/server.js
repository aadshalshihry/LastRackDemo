const express = require('express')
const http = require('http')
const socketIO = require('socket.io')
const mongoose = require('mongoose')
const cors = require('cors');
const Promise = require('bluebird');
const data = require('./seeds/data');
const fs = require('fs');


// our localhost port
const port = 4001

const app = express()

// our server instance
const server = http.createServer(app)

// This creates our socket using the instance of the server
const io = socketIO(server)

mongoose.Promise = Promise;
mongoose.connect("mongodb://localhost/rack-db");

app.use(cors())

// const seed = require('./seeds/seeder');
// seed();

// import all model (db)
const Rack = require('./models/Rack')
const Device = require('./models/Device')
const VM = require('./models/VM')
const NetworkDes = require('./models/Network_des')

require('./Route/index')(app);
// route for getting rack device, vm
// route add them
// route of updating

// This is what the socket.io syntax is like, we will work this later
io.on('connection', socket => {
  console.log('User connected: ', socket.id)
  // fn("User Connected")
  socket.broadcast.emit('cn');

  // Later
  socket.on('addNewRack', (a) => {
  	socket.broadcast.emit('addNewRackRes', a);
  })

  // ShowNetworkDes
  socket.on('showNetworkDes', (data) => {
    const name = data.split("::");
    const rackId = name[1];
    const deviceId = name[2];

    NetworkDes.find({ rackId: name[1], deviceId: name[2] }, (err, device) => {
      if(err) return err;
      let result = {};
      result.Processor = device[0].Processor;
      result.LanA = device[0].LanA;
      result.LanB = device[0].LanB;
      result.PCOIP = device[0].PCOIP;
      result.Host = device[0].Host;
      result.DNS1 = device[0].DNS1;
      result.DNS2 = device[0].DNS2;
      result.PUD = device[0].PUD;
      result.rackId = device[0].rackId;
      result.deviceId = device[0].deviceId;

      socket.broadcast.emit('showNetworkDes', result);
    })
  });

  // change the state of device by rackId & deviceId
  socket.on('changeDeviceState', (data) => {
  	Device.findOneAndUpdate({ rackId: data.rackId, deviceId: data.deviceId},
     {state: data.state}, {new: true}, function(err, device) {
  		if(err){
  			socket.broadcast.emit('Error user connected', err);
  		} else {
        if(!device){
          console.log("Not found");
        } else {
          const {rackId, deviceId, state} = device;
          const result = `changeDeviceState::${rackId}::${deviceId}::${state}`;
          socket.broadcast.emit('changeDeviceState', result);
        }
  		}
  	})
  })

  // change the state of vm by deviceId & vmId
  socket.on('changeVMState', (data) => {
	 VM.findOneAndUpdate({ deviceId: data.deviceId, vmId: data.vmId},
     {state: data.state}, {new: true}, function(err, vm) {
      if(err){
        socket.broadcast.emit('Error user connected', err);
      } else {
        if(!vm){
          console.log("Not found");
        } else {
          const {deviceId, vmId, state} = vm;
          const result = `changeVMState::${data.rackId}::${deviceId}::${vmId}::${state}`;
          socket.broadcast.emit('changeVMState', result);
        }
      }
    })
  })


  socket.on('changeDeviceName', (data) => {
    Device.findOneAndUpdate({
      rackId: data.rackId || 0,
      deviceId: data.deviceId || 0
    }, {deviceName: data.deviceName}, {new: true}, function(err, newDevice) {
      if (err) {
        return err;
      } else {
        const { rackId, deviceId } = data;
        const { deviceName } = newDevice;


        const result = `changeDeviceName::${rackId}::${deviceId}::${deviceName}`;
        socket.broadcast.emit('changeDeviceName', result);

      }
    })
  })

  socket.on('loadData', (d) => {
    const result = JSON.stringify(data);
		fs.writeFile('data.js', data, function (err) {
		  if (err) throw err;
		});
    socket.broadcast.emit('loadData', data);
  })

  socket.on('filterName', (data) => {
    const name = data.split("::");

    VM.find({vmName: {$regex : `.*${name[1]}.*`}}).exec((err, vm) => {
      if(err){
        return err;
      } else {
        // getting the device id from each vm
        let deviceIds = [];
        vm.forEach(val => {
          if(deviceIds.indexOf(val.deviceId) === -1) {
            deviceIds.push(val.deviceId);
          }
        })
        // console.log("[1]:", vm);
        Device.find({$or: [
          {deviceName: {$regex : `.*${name[1]}.*`}},
          {deviceId: {$in: deviceIds}}
        ]}).exec((err, device) => {
          if(err){
            return err;
          } else {
            // console.log("[2]:", device);

            // get all rack ids
            let rackIds = []
            device.forEach(val => {
              if(rackIds.indexOf(val.rackId) === -1)
                rackIds.push(val.rackId)
            })

            Rack.find({$or: [
              {rackName: {$regex : `.*${name[1]}.*`}},
              {rackId: {$in: rackIds}}
            ]})
            .sort('rackId')
            .exec((err, rack) => {
              if(err){
                return err;
              } else {
                let result = formatFilter(rack, device, vm);
                socket.broadcast.emit('filterName', result);

              }
            });
          }
        });
      }
    });
  });


  socket.on('disconnect', () => {
    console.log('user disconnected')
  })
})

// Hellper function

const formatFilter = (racks, devices, vms) => {
  let data = []

  racks.forEach(val => {
    data.push(popluateFormatedJson(val, devices, vms));
  })


  console.log(data);
  return data;
}

const rackFormatJson = (rack) => {
  let tempJson = {};
  tempJson.rackId = rack.rackId;
  tempJson.rackName = rack.rackName;
  tempJson.deviceList = []
  return tempJson;
}

const deviceFormatJson = (device, vms) => {
  let tempJson = {};
  tempJson.deviceId = device.deviceId;
  tempJson.deviceName = device.deviceName;
  tempJson.vmList = vms
  return tempJson;
}

const vmFormatJson = (vm) => {
  let tempJson = {};
  tempJson.vmId = vm.vmId;
  tempJson.vmName = vm.vmName;
  return tempJson;
}


const popluateFormatedJson = (rack, devices, vms) => {
  let rackJson = rackFormatJson(rack);
  let deviceJson = [];
  devices.forEach(deviceVal => {
    if(deviceVal.rackId === rack.rackId){
      let vmJson = [];
      vms.forEach(vmVal => {
        if(vmVal.deviceId === deviceVal.deviceId){
          vmJson.push(vmFormatJson(vmVal));
        }
      })

      deviceJson.push(deviceFormatJson(deviceVal, vmJson));
    }
  });
  rackJson.deviceList = deviceJson;

  return rackJson;

}

server.listen(port, () => console.log(`Listening on port ${port}`))
