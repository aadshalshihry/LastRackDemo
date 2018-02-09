#include "vm.h"
#include "ui_vm.h"

VM::VM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VM)
{
    ui->setupUi(this);
}

VM::VM(QWidget *parent, QString name):
    QWidget(parent),
    ui(new Ui::VM)
{
    ui->setupUi(this);
    this->name = name;
    ui->label->setText(this->name);
}

//Changes the color of the Vms to match the states
//as follows: 1 = Online, 2 = Faulted, 3 = Offline, 4 = Degraded, 5 = Disconnected
void VM::changeVmState(int state)
{
    ui->label->setProperty("vmState", state);
    style()->unpolish(ui->label);
    style()->polish(ui->label);
}

VM::~VM()
{
    delete ui;
}
