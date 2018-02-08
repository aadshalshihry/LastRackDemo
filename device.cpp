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

void Device::changeState(int state)
{
    switch(state)
    {
    case 1:{ui->horizontalLayoutWidget_2->setProperty("devState", 1);
        ui->label->setProperty("devState", 1);
        style()->unpolish(ui->label);
        style()->polish(ui->label);
        style()->unpolish(ui->horizontalLayoutWidget_2);
        style()->polish(ui->horizontalLayoutWidget_2);}
    break;
    case 2:{ui->horizontalLayoutWidget_2->setProperty("devState", 2);
        ui->label->setProperty("devState", 2);
        style()->unpolish(ui->label);
        style()->polish(ui->label);
        style()->unpolish(ui->horizontalLayoutWidget_2);
        style()->polish(ui->horizontalLayoutWidget_2);}
    break;
     case 3:{ui->horizontalLayoutWidget_2->setProperty("devState", 3);
        ui->label->setProperty("devState", 3);
        style()->unpolish(ui->label);
        style()->polish(ui->label);
        style()->unpolish(ui->horizontalLayoutWidget_2);
        style()->polish(ui->horizontalLayoutWidget_2);}
    break;
     case 4:{ui->horizontalLayoutWidget_2->setProperty("devState", 4);
        ui->label->setProperty("devState", 4);
        style()->unpolish(ui->label);
        style()->polish(ui->label);
        style()->unpolish(ui->horizontalLayoutWidget_2);
        style()->polish(ui->horizontalLayoutWidget_2);}
     break;
    case 5:{ui->horizontalLayoutWidget_2->setProperty("devState", 5);
       ui->label->setProperty("devState", 5);
       style()->unpolish(ui->label);
       style()->polish(ui->label);
       style()->unpolish(ui->horizontalLayoutWidget_2);
       style()->polish(ui->horizontalLayoutWidget_2);}
     break;
    }




  //  this->setStyleSheet("background: green; margin-top: 2px; border-radius: 3px;border: 1px solid black;");
}
Device::~Device()
{
    delete ui;
}
