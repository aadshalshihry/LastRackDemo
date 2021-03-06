#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "rack.h"
#include <QDebug>
#include <iostream>
#include "QScrollArea"
#include <memory>
#include <QThread>

MainWindows::MainWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);
    racks = {};
    racknum = 3;
//    sizeW = 400*racknum;

    ui->scrollAreaWidgetContents->resize(sizeW,ui->scrollAreaWidgetContents->height());
    //resize based on num racks which allows for scaleability, currently being hard set to 3 racks, verticle will need to be dynamicaly built based on racks size as well, nSure why resize
    //isn't functioning correctly.
    QHBoxLayout *scrollLayout = new QHBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(scrollLayout);
    this->racks.append(addRacks(scrollLayout, 0));
    this->racks.append(addRacks(scrollLayout, 1));
    this->racks.append(addRacks(scrollLayout, 2));
    udpcontroller mycontroller;

    QThread *myThread = new QThread;
    mycontroller.moveToThread(myThread);
    connect(&mycontroller, SIGNAL(changeDeviceStateSignal(QString, QString, int)),
            this, SLOT(changeDeviceStateSlot(QString,QString,int)));
    connect(&mycontroller, SIGNAL(changeDeviceNameSignal(QString,QString,QString)),
            this, SLOT(changeDeviceNameSlot(QString,QString,QString)));
    myThread->start();


}


MainWindows::~MainWindows()
{
    delete ui;
}


Rack* MainWindows::addRacks(QHBoxLayout *scrollLayout, int rackId)
{
    rack = new Rack(this);
    scrollLayout->addWidget(rack);
    if(rackId == 0) {
        rack->addDumyRecordForRackOne();
    } else if(rackId == 1) {
        rack->addDumyRecordForRackTow();
    } else {
        rack->addDumyRecordForRackThree();
    }

    return rack;

}

void MainWindows::on_pushButton_5_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int vmId = ui->spinBox->text().toInt();
    QString str = ui->lineEdit->text();
    if(str != ""){
        this->racks[rackId]->devices[vmId]->addVm(str);
    }

}

void MainWindows::addVm(QString rackIdstr,QString deviceIdstr, QString vmIdstr, int vmStatestr, QString vmName){
    int rackId = rackIdstr.toInt();
    int vmId = vmIdstr.toInt();
    if(vmName != ""){
        this->racks[rackId]->devices[vmId]->addVm(vmName);
    }
}

void MainWindows::addVmSlot(QString rackIdstr,QString deviceIdstr, QString vmIdstr, int vmStatestr, QString vmName){
    addVm(rackIdstr, deviceIdstr, vmIdstr, vmStatestr, vmName);
}

void MainWindows::changeDeviceState(QString rackIdstr, QString deviceIdstr, int devStatestr){
    int rackId = rackIdstr.toInt();
    int deviceId = deviceIdstr.toInt();
    int devState = devStatestr;

    if(devState<0 || devState>5) return;

    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(devState);
        }
}

void MainWindows::changeDeviceStateSlot(QString rackIdstr, QString deviceIdstr, int devStatestr){
    qDebug()<<"We reached mainwindows slot";
    changeDeviceState(rackIdstr,deviceIdstr,devStatestr);
}
void MainWindows::changeDeviceName(QString rackIdstr, QString deviceIdstr, QString devNamestr){
    int rackId = rackIdstr.toInt();
    int deviceId = deviceIdstr.toInt();

    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->name = devNamestr;
        }
}
void MainWindows::changeDeviceNameSlot(QString rackIdstr, QString deviceIdstr, QString devNamestr){
    changeDeviceName(rackIdstr, deviceIdstr, devNamestr);
}

//changeVMState
void MainWindows::changeVMState(QString rackIdstr, QString deviceIdstr, QString vmIdstr, int vmStatestr){
    int rackId = rackIdstr.toInt();
    int deviceId = deviceIdstr.toInt();
    int vmId = vmIdstr.toInt();
    int vmState = vmStatestr;

    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(vmState);
            }
}

void MainWindows::changeVMStateSlot(QString rackIdstr, QString deviceIdstr, QString vmIdstr, int vmStatestr){
    changeVMState(rackIdstr, deviceIdstr, vmIdstr, vmStatestr);
}

//Buttons that control the color of the devices
void MainWindows::on_btn1_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(1);
        }
}

void MainWindows::on_btn2_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(2);
        }
}

void MainWindows::on_btn3_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(3);
        }
}

void MainWindows::on_btn4_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(4);
        }
}

// offline
void MainWindows::on_btn4_4_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
        {
            auto cur = this->racks[rackId]->devices[deviceId];
            cur->changeDevState(5);
        }
}


// Buttons that control the color of the Vms
void MainWindows::on_btn1_2_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(1);
            }
}

void MainWindows::on_btn2_2_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(2);
            }
}

void MainWindows::on_btn3_2_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(3);
            }
}

void MainWindows::on_btn4_2_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(4);
            }
}

// offline
void MainWindows::on_btn4_3_clicked()
{
    int rackId = ui->spinBox_3->text().toInt();
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    if(rackId < this->racks.size())
        if(deviceId < this->racks[rackId]->devices.size())
            if(vmId < this->racks[rackId]->devices[deviceId]->vms.size())
            {
                auto cur2 = this->racks[rackId]->devices[deviceId]->vms[vmId];
                cur2->changeVmState(5);
            }
}
//This code is to use the enter button to filter.
/*void MainWindows::on_lineEdit_2_returnPressed()
{
     QString temp1 = ui->lineEdit_2->text();
     if(temp1.isEmpty())
         for(int i=0; i<racks.size();i++)
             for(int j=0;j< racks[i]->devices.size();j++)
                  racks[i]->devices[j]->show();

     else
        for(int i=0; i<racks.size();i++)
            for(int j=0;j< racks[i]->devices.size();j++)
            {
                QString temp2 = racks[i]->devices[j]->name;
                if(!(temp2.contains(temp1, Qt::CaseInsensitive)))
                    racks[i]->devices[j]->hide();
            }
}*/

void MainWindows::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString temp1 = ui->lineEdit_2->text();
    if(temp1.isEmpty())
        for(int i=0; i<racks.size();i++)
            for(int j=0;j< racks[i]->devices.size();j++)
                 racks[i]->devices[j]->show();

    else
    {
        for(int i=0; i<racks.size();i++)
            for(int j=0;j< racks[i]->devices.size();j++)
                 racks[i]->devices[j]->hide();

       for(int i=0; i<racks.size();i++)
           for(int j=0;j< racks[i]->devices.size();j++)
           {
               QString temp2 = racks[i]->devices[j]->name;
               if((temp2.contains(temp1, Qt::CaseInsensitive)))
                   racks[i]->devices[j]->show();
           }
    }
}

void MainWindows::connect_socket(udpcontroller &mycontroller)
{
    connect(&mycontroller, SIGNAL(changeDeviceStateSignal(QString, QString, int)),
            this, SLOT(changeDeviceStateSlot(QString,QString,int)));
    connect(&mycontroller, SIGNAL(changeVMStateSignal(QString, QString, QString, int)),
            this, SLOT(changeVMStateSlot(QString,QString,QString, int)));
    connect(&mycontroller, SIGNAL(changeDeviceNameSignal(QString,QString,QString)),
            this, SLOT(changeDeviceNameSlot(QString,QString,QString)));
}
