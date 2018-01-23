#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include <QString>
#include <QVector>

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

    void addVm(QString name);
    ~Device();
    QVector<VM*> vms;
    int vmsSize;

private:
    QString name;

    Ui::Device *ui;
};

#endif // DEVICE_H
