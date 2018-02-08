#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QString>
#include "rack.h"


namespace Ui {
class MainWindows;
}

class MainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget *parent = 0);
    ~MainWindows();
    Rack *rack;

private slots:

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

private:
    Ui::MainWindows *ui;
};

#endif // MAINWINDOWS_H
