#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "rack.h"
#include <QDebug>
#include <iostream>
MainWindows::MainWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);


    rack = new Rack(this);
    rack->addDumyRecord();

}

MainWindows::~MainWindows()
{
    delete ui;
}


void MainWindows::on_pushButton_5_clicked()
{
    int vmId = ui->spinBox->text().toInt();
    QString str = ui->lineEdit->text();
    if(str != ""){
        this->rack->devices[vmId]->addVm(str);
    }



}

void MainWindows::on_btn1_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    auto cur = this->rack->devices[deviceId];
    cur->changeState(1);
}

void MainWindows::on_btn2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    auto cur = this->rack->devices[deviceId];
    cur->changeState(2);
}

void MainWindows::on_btn3_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    auto cur = this->rack->devices[deviceId];
    cur->changeState(3);
}

void MainWindows::on_btn4_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    auto cur = this->rack->devices[deviceId];
    cur->changeState(4);
}

// offline
void MainWindows::on_btn4_4_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    auto cur = this->rack->devices[deviceId];
    cur->changeState(5);
}


// Vm ----------
void MainWindows::on_btn1_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    auto cur2 = this->rack->devices[deviceId]->vms[vmId];
    cur2->changeVmState(1);
}

void MainWindows::on_btn2_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    auto cur2 = this->rack->devices[deviceId]->vms[vmId];
    cur2->changeVmState(2);
}

void MainWindows::on_btn3_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    auto cur2 = this->rack->devices[deviceId]->vms[vmId];
    cur2->changeVmState(3);
}

void MainWindows::on_btn4_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    auto cur2 = this->rack->devices[deviceId]->vms[vmId];
    cur2->changeVmState(4);
}


// offline
void MainWindows::on_btn4_3_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    auto cur2 = this->rack->devices[deviceId]->vms[vmId];
    cur2->changeVmState(5);
}


