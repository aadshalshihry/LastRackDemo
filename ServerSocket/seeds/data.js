module.exports = {
  "data" :[
    {
        "model": "Rack",
        "documents": [
            {
                "rackName": "rack-0",
                "rackId": 0,
            },
            {
                "rackName": "rack-1",
                "rackId": 1,
            },
            {
                "rackName": "rack-2",
                "rackId": 2,
            }
        ]
    },
    {
        "model": "Device",
        "documents": [
          // Device for RackId = 0
            {
                "deviceName": "SER-2 SW-1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 0,
            },
            {
                "deviceName": "SER-2 SW-2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 1,
            },
            {
                "deviceName": "TC-MTX-1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 2,
            },
            {
                "deviceName": "TC-MTX-2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 3,
            },
            {
                "deviceName": "VMH1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 4,
            },
            {
                "deviceName": "VMH2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 5,
            },
            {
                "deviceName": "VMH3",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 6,
            },
            {
                "deviceName": "VMH4",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 7,
            },
            {
                "deviceName": "VMH5",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 8,
            },
            {
                "deviceName": "VMH6",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 9,
            },
            {
                "deviceName": "VMH7",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 10,
            },{
                "deviceName": "VMH8",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 11,
            },{
                "deviceName": "VMHost-1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 12,
            },{
                "deviceName": "VMHost-2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 13,
            },{
                "deviceName": "VMHost-3",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 0,
                "deviceId": 14,
            },
          // Device for RackId = 1
            {
                "deviceName": "SER-1 RC1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 1,
                "deviceId": 0,
            },
            {
                "deviceName": "SER-2 RC1",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 1,
                "deviceId": 1,
            },
            

          // Device for RackId = 2
            {
                "deviceName": "SER-1 RC2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 2,
                "deviceId": 0,
            },
            {
                "deviceName": "SER-2 RC2",
                "vmNum": 0,
                "state": "Faulted",
                "rackId": 2,
                "deviceId": 1,
            },
            

        ]
    },
    {
        "model": "VM",
        "documents": [
          // device = 0, RackId = 0
          {
              "vmName": "VmHdx",
              "state": "Faulted",
              "rackId": 0,
              "deviceId": 0,
              "vmId": 0,
          },

          // device = 3, RackId = 0
          {
              "vmName": "HTx",
              "state": "Faulted",
              "rackId": 0,
              "deviceId": 3,
              "vmId": 0,
          },

          {
              "vmName": "KDe",
              "state": "Faulted",
              "rackId": 0,
              "deviceId": 3,
              "vmId": 1,
          },

          // device = 0, rackId = 1
          {
              "vmName": "VmHdx",
              "state": "Faulted",
              "rackId": 1,
              "deviceId": 0,
              "vmId": 0,
          },

          // device = 1, rackId = 2
          {
              "vmName": "VmDD3",
              "state": "Faulted",
              "rackId": 2,
              "deviceId": 1,
              "vmId": 0,
          },

          
        ]
    },


    // NetworkDes
    {
        "model": "NetworkDes",
        "documents": [
          // Rack = 0
          {
            "Host": "IFS",
            "DNS1": "NS1",
            "DNS2": "NS2",
            "Processor": "Online",
            "LanA": "Online",
            "LanB": "Online",
            "PUD": "NOLIHJU.LI1",
            "PCOIP": "Online",
            "Outline": "Online",
            "rackId": 0,
            "deviceId": 0
          },
          
        ]
    },
]}
