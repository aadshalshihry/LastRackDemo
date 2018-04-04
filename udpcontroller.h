#ifndef udpcontroller_H
#define udpcontroller_H

#include <QUdpSocket>
#include <QObject>
#include <mainwindows.h>

class udpcontroller : public QObject
{
    Q_OBJECT
public:
    explicit udpcontroller(QObject *parent = nullptr);

private:
    QUdpSocket *socket;
    QObject * parentWindow = parent();
    int stateToInt(QString str);
    /*std::map< const char *, std::function<int(QString, QString, QString, QString)> > dispatchTable{
           {"changeVMState", [](QString rack, QString deviceName, QString VM, QString state){
                return changeVMState(rack, deviceName, VM, state);}},
           {"changeDeviceName", [](QString rack, QString device, QString VM, QString name){
                return changeDeviceName(rack, deviceName, VM, name);}}
    };
    //emit(interrupt_handler(handle_error(dispatchTable[arg[0]](split.reduce)));*/

signals:

public slots:
    //void connected();
    //void disconnected();
    //void error();
    void readyRead();
};

#endif // udpcontroller_H
