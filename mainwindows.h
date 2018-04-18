#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QString>
#include "rack.h"
#include "QHBoxLayout"


namespace Ui {
class MainWindows;
}

class MainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget *parent = 0);
    ~MainWindows();
    Rack* addRacks(QHBoxLayout* scrollLayout);
    QVector<Rack*> racks;

    void addVm(QString rackIdstr,QString deviceIdstr, QString vmIdstr, int vmStatestr, QString vmName);
    void changeDeviceState(QString rackIdstr, QString deviceIdstr, int devStatestr);
    void changeVMState(QString rackIdstr, QString deviceIdstr, QString vmIdstr, int vmStatestr);
    void changeDeviceName(QString rackIdstr, QString deviceIdstr, QString devNamestr);




    Rack *rack;
    int racknum=0;
    int sizeW;

private slots:

    void addVmSlot(QString rackIdstr,QString deviceIdstr, QString vmIdstr, int vmStatestr, QString vmName);
    void changeDeviceStateSlot(QString rackIdstr, QString deviceIdstr, int devStatestr);
    void changeVMStateSlot(QString rackIdstr, QString deviceIdstr, QString vmIdstr, int vmStatestr);
    void changeDeviceNameSlot(QString rackIdstr, QString deviceIdstr, QString devNamestr);

    void on_pushButton_5_clicked();


    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn1_2_clicked();

    void on_btn2_2_clicked();

    void on_btn3_2_clicked();

    void on_btn4_2_clicked();

    void on_btn4_4_clicked();

    void on_btn4_3_clicked();

   // void on_lineEdit_2_returnPressed();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::MainWindows *ui;
};

#endif // MAINWINDOWS_H
