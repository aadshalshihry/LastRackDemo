#ifndef RACK_H
#define RACK_H

#include <QScrollArea>
#include <QVector>
#include <QString>

#include "device.h"


namespace Ui {
class Rack;
}

class Rack : public QScrollArea
{
    Q_OBJECT

public:
    explicit Rack(QWidget *parent = 0);
    void addDumyRecord();

    ~Rack();
    QVector<Device*> devices;
    int deviceSize;

private:
    Ui::Rack *ui;

};

#endif // RACK_H
