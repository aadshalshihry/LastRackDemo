#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "rack.h"
#include <QDebug>
#include <iostream>
#include "QScrollArea"
#include <memory>

MainWindows::MainWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);
    racks = {};
    racknum = 3;
    sizeW = 400*racknum;

    ui->scrollAreaWidgetContents->resize(sizeW,ui->scrollAreaWidgetContents->height());
    //resize based on num racks which allows for scaleability, currently being hard set to 3 racks, verticle will need to be dynamicaly built based on racks size as well, nSure why resize
    //isn't functioning correctly.
    QHBoxLayout *scrollLayout = new QHBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(scrollLayout);
    this->racks.append(addRacks(scrollLayout));
    this->racks.append(addRacks(scrollLayout));
    this->racks.append(addRacks(scrollLayout));

}


MainWindows::~MainWindows()
{
    delete ui;
}


Rack* MainWindows::addRacks(QHBoxLayout *scrollLayout)
{
    rack = new Rack(this);
    scrollLayout->addWidget(rack);
    rack->addDumyRecord();
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
