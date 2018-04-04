# ServerSocket tester


## You need to install & config the following:

1. [Mongodb](https://docs.mongodb.com/manual/installation/)
2. [Node.js](https://nodejs.org/en/download/)

## To Run the server
> The following command assume we are in the LastReackDemo derectory
```bash
cd ServerSocket
npm install

# you need to make sure that mongodb is running before you start the server
npm run seed
npm run start
```

## To Run the client
> The following command assume we are in the LastReackDemo derectory
```bash
cd ServerSocket/frontEnd
npm install
npm run start
```

## Available Socket Method
| Method String | Return Value |
| ------------- |:-------------:|
| loadData | return json object and create text file (Path: ./ServerSocket/data.txt) |
| changeDeviceName | changeDeviceName::${rackId}::${deviceId}::${deviceName} |
| changeDeviceState | changeDeviceState::${rackId}::${deviceId}::${state} |
| changeVMState | changeVMState::${rackId}::${deviceId}::${vmId}::${state}|
| filterName | return json object `see example 1 below`|
| showNetworkDes | return json object `see example 2 below` |


## Exmaple 1

```json
 [{"vmNum":0,"state":"Faulted","_id":"5a8b9146dd431bbbbef961db","deviceName":"device-0-2","rackId":0,"deviceId":2,"createdAt":"2018-02-20T03:08:54.901Z","updatedAt":"2018-02-20T03:08:54.901Z","__v":0}]
```

## Example 2

```json
{ "Processor": "Online",
  "LanA": "Online",
  "LanB": "Online",
  "PCOIP": "Online",
  "Host": "IFS",
  "DNS1": "NS1",
  "DNS2": "NS2",
  "PUD": "NOLIHJU.LI1",
  "rackId": 1,
  "deviceId": 0 }
```
