#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <iostream>
#include "vm.h"


namespace Ui {
class Device;
}

class Device : public QWidget
{
    Q_OBJECT

public:
    explicit Device(QWidget *parent = 0);
    explicit Device(QWidget *parent = 0, QString name = "");
    Ui::Device *ui;
    void addVm(QString name);
    void changeDevState(int state);
    ~Device();
    QVector<VM*> vms;
    int vmsSize;
    int deviceState;


private:
    QString name;

};


#endif // DEVICE_H
