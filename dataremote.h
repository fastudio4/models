#ifndef DATA_H
#define DATA_H

#include <QList>
#include "dataport.h"
//#include "datadevice.h"

namespace DATA {

class Data
{

public:
    Data();
    virtual ~Data();
    QStringList uploadListPort();
    int indexBaudRate();
    int indexDataBits();
    int indexFlowControl();
    int indexParity();
//    QString aliasPort();
    int indexStopBits();
private:
    void fillPortData(const QString &name);
    QList<DataPort> data;

};

}

#endif // DATA_H
