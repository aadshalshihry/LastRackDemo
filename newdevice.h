#ifndef NEWDEVICE_H
#define NEWDEVICE_H

#include <QGroupBox>
#include "vm.h"
#include <QString>

namespace Ui {
class NewDevice;
}

class NewDevice : public QGroupBox
{
    Q_OBJECT

public:
    explicit NewDevice(QWidget *parent = 0);
    explicit NewDevice(QWidget *parent = 0, QString name = "");
    ~NewDevice();

    void addVm(QString name);
    QVector<VM*> vms;
    int vmsSize;
    QString name;

private:
    Ui::NewDevice *ui;
};

#endif // NEWDEVICE_H
