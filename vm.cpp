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

VM::~VM()
{
    delete ui;
}
