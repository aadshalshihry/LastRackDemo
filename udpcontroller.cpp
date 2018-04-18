#include "udpcontroller.h"

udpcontroller::udpcontroller(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);

    if(socket->bind(QHostAddress::LocalHost,4003,QUdpSocket::ShareAddress)) //even if local Host dont have static IP( on subnet expected 172.168.x.x),still it becomes true and enters if.
        {
        if( (socket->state() == QAbstractSocket::BoundState) && (((socket->localAddress()).protocol()) == QAbstractSocket::IPv4Protocol) ) //ignore protocol validation if not required.
            {

             }
     else
            {
                qDebug()<<"Socket not in bound state. address is: "<<QHostAddress::LocalHost<<" and the port "<<4003;
                //Return = false;
            }
        }
    else
        {
            qDebug()<<"Failed to bind socket to the address "<<QHostAddress::LocalHost<<" and the port "<<4003;
            //Return = false;
        }

    //socket->bind(QHostAddress::Any, 4003);
    qDebug() << "Connected!";
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    //qDebug() << socket->readAll();
}

void udpcontroller::onSocketError(QAbstractSocket::SocketError socketError){
    qDebug()<<"socket error occured and the error is : "<<socketError;
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
     QString *data = new QString(buffer);
     qDebug() << data;
     QStringList dataList;
     if(data->contains("serverinit", Qt::CaseInsensitive)){
        //write JSON parser
     }else if(data->contains("addVm", Qt::CaseInsensitive)){
        dataList = data->split("::");
        //RackId is 1
        //DeviceId is 2
        //vmId is 3
        //vmState is 4
        //vmName is 5
        //not implemented change

        int vmStateId = stateToInt(dataList[4]);
        emit addVmSignal(dataList[1], dataList[2], dataList[3], vmStateId, dataList[5] );
     }else if(data->contains("changeVMState", Qt::CaseInsensitive)){
         dataList = data->split("::");
         //RackId is 1
         //DeviceId is 2
         //vmId is 3
         //vmState is 4

         int vmStateId = stateToInt(dataList[4]);
         //((MainWindows *)parentWindow)->changeVMState(dataList[1], dataList[2], dataList[3], vmStateId);
         emit changeVMStateSignal(dataList[1], dataList[2], dataList[3], vmStateId);

     }else if(data->contains("changeDeviceState", Qt::CaseInsensitive)){
         dataList = data->split("::");
         //RackId is 1
         //DeviceId is 2
         //state is 3
         int deviceStateInt = stateToInt(dataList[3]);

         //((MainWindows *)parentWindow)->changeDeviceState(dataList[1], dataList[2], deviceStateInt);
         emit changeDeviceStateSignal(dataList[1], dataList[2], deviceStateInt);

     }else if(data->contains("changeDeviceName", Qt::CaseInsensitive)){
         dataList = data->split("::");
         //RackId is 1
         //deviceId is 2
         //deviceName is 3
         //((MainWindows *)parentWindow)->changeDeviceName(dataList[1], dataList[2], dataList[3]);
         emit changeDeviceNameSignal(dataList[1], dataList[2], dataList[3]);
     }
}


int udpcontroller::stateToInt(QString str){
    if(str.contains("operational", Qt::CaseInsensitive)) return 1;
    if(str.contains("faulted", Qt::CaseInsensitive)) return 2;
    if(str.contains("offline", Qt::CaseInsensitive)) return 3;
    if(str.contains("degraded", Qt::CaseInsensitive)) return 4;
    if(str.contains("disconnect", Qt::CaseInsensitive)) return 5;
    return 0;
}
