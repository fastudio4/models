#ifndef DATAPORT_H
#define DATAPORT_H
#include <QString>
#include <QStringList>
#include <QUuid>
#include "datadevice.h"

namespace DATA {

class DataPort
{
public:
    DataPort();

    QString getPortName(void) { return portName; }
    void setPortName(const QString &data) { portName = data; }

    QString getAliasPortName(void) { return aliasPortName; }
    void setAliasPortName(const QString &data) { aliasPortName = data; }

    QString getBaudRate(void) { return baudRate; }
    void setBaudRate(const QString &data) { baudRate = data; }

    QString getDataBits(void) { return dataBits; }
    void setDataBits(const QString &data) { dataBits = data; }

    QString getFlowControl(void) { return flowControl; }
    void setFlowControl(const QString &data) { flowControl = data; }

    QString getParity(void) { return parity; }
    void setParity(const QString &data) { parity = data; }

    QString getStopBits(void) { return stopBits; }
    void setStopBits(const QString &data) { stopBits = data; }

    int getResponseTimeout(void) { return responseTimeout; }
    void setResponseTimeout (const int &data) { stopBits = data; }

    int getDeleyBetweenPull(void) { return deleyBetweenPull; }
    void setDeleyBetweenPull (const int &data) { deleyBetweenPull = data; }

    void newSlaveDevice(void);
    QList<int> listSlaveId(void);

    void addDevice(DATA::DataDevice *newDev);
    void editDevice(int slaveId, int newSlaveId, DATA::DataDevice *newDevData);
    void deleteDevice(QUuid Id);

    virtual ~DataPort();

private:

    QString portName;
    QString aliasPortName;
    QString baudRate;
    QString dataBits;
    QString flowControl;
    QString parity;
    QString stopBits;
    int responseTimeout;
    int deleyBetweenPull;

    QList<DATA::DataDevice> listDevice;
//    QUuid uID;
//    int slaveId;
//    QString alias;
//    QString function;
//    int addr;
//    int quantity;
//    int scanRate;
//    int countRows;

};

}//namespace DATA
#endif // DATAPORT_H
