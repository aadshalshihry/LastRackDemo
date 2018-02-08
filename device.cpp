#include "device.h"
#include "ui_device.h"
#include <QHBoxLayout>



Device::Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Device)
{
    ui->setupUi(this);

}

Device::Device(QWidget *parent, QString name):
    QWidget(parent),
    ui(new Ui::Device)
{

    ui->setupUi(this);
    this->name = name;
    this->vms = {};
    vmsSize = 0;
    ui->label->setText(this->name);
    ui->horizontalLayout_2->setAlignment(Qt::AlignLeft);


}

void Device::addVm(QString name)
{
    VM *vm = new VM(ui->widget, name);
    this->vms.append(vm);
    this->setMinimumHeight(60);
    ui->widget->setMinimumHeight(148);
    ui->horizontalLayout_2->addWidget(vm);
    this->vmsSize++;
}
//Changes the color of the machines to match the states
// "state" is as follows: 1 = Online, 2 = Faulted, 3 = Offline, 4 = Degraded, 5 = Disconnected
void Device::changeDevState(int state)
{

        ui->horizontalLayoutWidget_2->setProperty("devState", state);
        ui->label->setProperty("devState", state);
        style()->unpolish(ui->label);
        style()->polish(ui->label);
        style()->unpolish(ui->horizontalLayoutWidget_2);
        style()->polish(ui->horizontalLayoutWidget_2);

}
Device::~Device()
{
    delete ui;
}
