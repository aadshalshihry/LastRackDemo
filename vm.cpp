#include "vm.h"
#include "ui_vm.h"

VM::VM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VM)
{
    ui->setupUi(this);
//    QSize size = ui->label->sizeHint();
//    this->setMaximumWidth(size.width() + 15);
}

VM::VM(QWidget *parent, QString name):
    QWidget(parent),
    ui(new Ui::VM)
{
    ui->setupUi(this);
    this->name = name;
    ui->label->setText(this->name);

//    QSize size = ui->label->sizeHint();
//    this->setMaximumWidth(size.width() + 25);
}
void VM::changeVmState(int state)
{
    switch(state)
    {
    case 1:{ui->label->setProperty("vmState", 1);
        style()->unpolish(ui->label);
        style()->polish(ui->label);}
    break;

    case 2:{ui->label->setProperty("vmState", 2);
        style()->unpolish(ui->label);
        style()->polish(ui->label);}
    break;

    case 3:{ui->label->setProperty("vmState", 3);
        style()->unpolish(ui->label);
        style()->polish(ui->label);}
    break;

    case 4:{ui->label->setProperty("vmState", 4);
        style()->unpolish(ui->label);
        style()->polish(ui->label);}
    break;

    case 5:{ui->label->setProperty("vmState", 5);
        style()->unpolish(ui->label);
        style()->polish(ui->label);}
    break;

    }
}

VM::~VM()
{
    delete ui;
}
