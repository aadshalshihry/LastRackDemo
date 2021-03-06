#include "rack.h"
#include "ui_rack.h"


Rack::Rack(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::Rack)
{
    ui->setupUi(this);
    this->devices = {};
    this->deviceSize = 0;

    ui->scrollAreaWidgetContents->layout()->setAlignment(Qt::AlignTop);
}

void Rack::addDumyRecordForRackOne()
{
    this->rakcId = 0;

    Device *d = new Device(this, "SER-2 SW-1");
    this->devices.append(d);
    this->deviceSize++;
    this->devices[0]->addVm("VmHdx");
    ui->scrollAreaWidgetContents->layout()->addWidget(d);

    Device *d1 = new Device(this, "SER-2 SW-2");
    this->devices.append(d1);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d1);

    Device *d2 = new Device(this, "TC-MTX-1");
    this->devices.append(d2);
    ui->scrollAreaWidgetContents->layout()->addWidget(d2);

    Device *d3 = new Device(this, "TC-MTX-2");
    this->devices.append(d3);
    this->deviceSize++;
    this->devices[3]->addVm("HTx");
    this->devices[3]->addVm("KDe");
    ui->scrollAreaWidgetContents->layout()->addWidget(d3);

    Device *d4= new Device(this, "VMH1");
    this->devices.append(d4);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d4);

    Device *d5 = new Device(this, "VMH-2");
    this->devices.append(d5);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d5);

    Device *d6 = new Device(this, "VMH-3");
    this->devices.append(d6);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d6);

    Device *d7 = new Device(this, "VMH-4");
    this->devices.append(d7);
    ui->scrollAreaWidgetContents->layout()->addWidget(d7);

    Device *d8 = new Device(this, "VMH-5");
    this->devices.append(d8);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d8);

    Device *d9 = new Device(this, "VMH-6");
    this->devices.append(d9);
    ui->scrollAreaWidgetContents->layout()->addWidget(d9);

    Device *d10 = new Device(this, "VMH-7");
    this->devices.append(d10);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d10);

    Device *d11 = new Device(this, "VMH-8");
    this->devices.append(d11);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d11);

    Device *d12 = new Device(this, "VMHost-1");
    this->devices.append(d12);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d12);

    Device *d13 = new Device(this, "VMHost-2");
    this->devices.append(d13);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d13);

    Device *d14 = new Device(this, "VMHost-2");
    this->devices.append(d14);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d14);
}

void Rack::addDumyRecordForRackTow()
{
    this->rakcId = 1;

    Device *d = new Device(this, "SER-2 RC1");
    this->devices.append(d);
    this->deviceSize++;
    this->devices[0]->addVm("VmHdx");
    ui->scrollAreaWidgetContents->layout()->addWidget(d);

    Device *d1 = new Device(this, "SER-2 RC1");
    this->devices.append(d1);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d1);
}

void Rack::addDumyRecordForRackThree()
{
    this->rakcId = 2;

    Device *d = new Device(this, "SER-1 RC2");
    this->devices.append(d);
    this->deviceSize++;
    ui->scrollAreaWidgetContents->layout()->addWidget(d);

    Device *d1 = new Device(this, "SER-2 RC2");
    this->devices.append(d1);
    this->deviceSize++;
    this->devices[1]->addVm("VmDD3");
    ui->scrollAreaWidgetContents->layout()->addWidget(d1);
}

Rack::~Rack()
{
    delete ui;
}
