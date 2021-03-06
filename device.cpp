#include "device.h"
#include "ui_device.h"
#include <QHBoxLayout>
#include <QToolTip>


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
    this->deviceState = 1;
    vmsSize = 0;
    ui->label->setText(this->name);
    ui->horizontalLayout_2->setAlignment(Qt::AlignLeft);
    this->setToolTip("Host: IFS <br />DNS:ifs.r30.int.smmtt<br />Processor:<span style=\"color:green\">online</span><br />LAN A :<span style=\"color:green\">online</span><br />LAN B:<span style=\"color:green\">online</span><br />PCOIP:<span style=\"color:green\">online</span><br /><br />PDU: SER-1 PDU A<br />DNS:ser1pdua.r30.int.smtt<br />&nbsp;&nbsp;&nbsp;&nbsp;Outlet:<span style=\"color:green\">online</span><br />");
}

void Device::addVm(QString name)
{
    VM *vm = new VM(ui->widget, name);
    this->vms.append(vm);
    this->setMinimumHeight(60);
    ui->widget->setMinimumHeight(296);
    ui->horizontalLayout_2->addWidget(vm);
    this->vmsSize++;
}

//Changes the color of the machines to match the states
// "state" is as follows: 1 = Online, 2 = Faulted, 3 = Offline, 4 = Degraded, 5 = Disconnected
void Device::changeDevState(int state)
{
    this->deviceState = state;
    ui->horizontalLayoutWidget_2->setProperty("devState", state);
    ui->label->setProperty("devState", state);
    style()->unpolish(ui->label);
    style()->polish(ui->label);
    style()->unpolish(ui->horizontalLayoutWidget_2);
    style()->polish(ui->horizontalLayoutWidget_2);
    //if its disconnected, also disconnects VMs attatched to it
    if(state == 5)
    {
        for(int i=0; i<vms.size(); i++)
        {
            this->vms[i]->changeVmState(5);
            this->vms[i]->~VM();
        }
        this->vms = {};
        //resizes the device widget when Vms are removed
        this->setMinimumHeight(30);
    }
}
Device::~Device()
{
    delete ui;
}
