#include "udpcontroller.h"

udpcontroller::udpcontroller(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 4003);
    qDebug() << "Connected!";
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    qDebug() << socket->readAll();
}

/* Ready read is a slot which executes whenever a new datagram is found over udp
 * signals for device information need to be implemented.
 * */
void udpcontroller::readyRead(){
     QByteArray buffer;
     buffer.resize(socket->pendingDatagramSize());

     QHostAddress sender;
     quint16 senderPort;

     socket->readDatagram(buffer.data(), buffer.size(),
                              &sender, &senderPort);
     qDebug() << buffer.data();
     QString *data = new QString(buffer);
     QStringList dataList;
     if(data->contains("serverinit")){
        //write JSON parser
     }else if(data->contains("changeVMState")){
         dataList = data->split("::");
         //RackId is 1
         //DeviceId is 2
         //vmId is 3
         //vmState is 4

         int vmStateId = stateToInt(dataList[4]);
         ((MainWindows *)parentWindow)->changeVMState(dataList[1], dataList[2], dataList[3], vmStateId);

     }else if(data->contains("changeDeviceState")){
         dataList = data->split("::");
         //RackId is 1
         //DeviceId is 2
         //state is 3
         int deviceStateInt = stateToInt(dataList[3]);

         ((MainWindows *)parentWindow)->changeDeviceState(dataList[1], dataList[2], deviceStateInt);

     }else if(data->contains("changeDeviceName")){
         dataList = data->split("::");
         //RackId is 1
         //deviceId is 2
         //deviceName is 3
         //((MainWindows *)parentWindow)->changeDeviceName(dataList[1], dataList[2], dataList[3]);
     }
}


int udpcontroller::stateToInt(QString str){
    if(str.contains("operational")) return 1;
    if(str.contains("faulted")) return 2;
    if(str.contains("offline")) return 3;
    if(str.contains("degraded")) return 4;
    if(str.contains("disconnect")) return 5;
    return 0;
}
