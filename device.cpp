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

Device::~Device()
{
    delete ui;
}
