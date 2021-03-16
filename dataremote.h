#ifndef DATA_H
#define DATA_H

#include <QList>
#include "dataport.h"


namespace DATA {

class Data
{

public:
    Data();
    virtual ~Data();
    QStringList uploadListPort();
    int indexPortName(const QString &portName);
    int indexBaudRate(int indexPort);
    int indexDataBits(int indexPort);
    int indexFlowControl(int indexPort);
    int indexParity(int indexPort);
    int indexStopBits(int indexPort);

    int countData() {return data.count();}
    QStringList listPorts() {return uploadListPort();}

    QStringList getListBaudRate(void);
    QStringList getListDataBits(void);
    QStringList getListFlowControl(void);
    QStringList getListParity(void);
    QStringList getListStopBits(void);
private:
    void fillPortData(const QString &namePort);
    QList<DataPort> data;
    QList<QString> portsName;

};

}

#endif // DATA_H
