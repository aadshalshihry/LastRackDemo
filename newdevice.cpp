#include "newdevice.h"
#include "ui_newdevice.h"

NewDevice::NewDevice(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::NewDevice)
{
    ui->setupUi(this);
}

NewDevice::NewDevice(QWidget *parent, QString name) :
    QGroupBox(parent),
    ui(new Ui::NewDevice)
{
    ui->setupUi(this);
    this->name = name;
    this->vms = {};
    vmsSize = 0;
    this->setTitle(this->name);

//    ui->label->setText(this->name);

    ui->horizontalLayout->setAlignment(Qt::AlignLeft);

}

NewDevice::~NewDevice()
{
    delete ui;
}

void NewDevice::addVm(QString name)
{
    VM *vm = new VM(this, name);
    this->vms.append(vm);

    ui->horizontalLayout->addWidget(vm);
//    this->setMinimumHeight(60);

//    ui->widget->setMinimumHeight(148);
//    ui->horizontalLayout_2->addWidget(vm);
    this->vmsSize++;
}
