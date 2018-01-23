#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "rack.h"
#include <QDebug>

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
    this->rack->devices[deviceId]->setStyleSheet("background: #223344; ");
}

void MainWindows::on_btn2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    this->rack->devices[deviceId]->setStyleSheet("background: #223366; ");
}

void MainWindows::on_btn3_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    this->rack->devices[deviceId]->setStyleSheet("background: #2233aa; ");
}

void MainWindows::on_btn4_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    this->rack->devices[deviceId]->setStyleSheet("background: #2233ff; ");
}

// offline
void MainWindows::on_btn4_4_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    this->rack->devices[deviceId]->setStyleSheet("background: #223300; ");
}


// Vm ----------
void MainWindows::on_btn1_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    QString style = "background: #223344; border-radius: 3px;padding: 0px;margin-left: 5px;";
    this->rack->devices[deviceId]->vms[vmId]->setStyleSheet(style);
}

void MainWindows::on_btn2_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    QString style = "background: #223366; border-radius: 3px;padding: 0px;margin-left: 5px;";
    this->rack->devices[deviceId]->vms[vmId]->setStyleSheet(style);
}

void MainWindows::on_btn3_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    QString style = "background: #2233aa; border-radius: 3px;padding: 0px;margin-left: 5px;";
    this->rack->devices[deviceId]->vms[vmId]->setStyleSheet(style);
}

void MainWindows::on_btn4_2_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    QString style = "background: #2233ff; border-radius: 3px;padding: 0px;margin-left: 5px;";
    this->rack->devices[deviceId]->vms[vmId]->setStyleSheet(style);
}


// offline
void MainWindows::on_btn4_3_clicked()
{
    int deviceId = ui->spinBox->text().toInt();
    int vmId = ui->spinBox_2->text().toInt();
    QString style = "background: #223300; border-radius: 3px;padding: 0px;margin-left: 5px;";
    this->rack->devices[deviceId]->vms[vmId]->setStyleSheet(style);
}
