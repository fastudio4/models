#ifndef DATADEVICE_H
#define DATADEVICE_H
#include <QString>
#include <QStringList>
#include <QUuid>

namespace DATA {

class DataDevice
{
public:
    DataDevice();
    QUuid getUid(void) { return uID; }

    int getSlaveId(void) { return slaveId; }
    void setSlaveId (const int &data) { slaveId = data; }

    QString getAliasDevice(void) { return alias; }
    void setAliasDevice(const QString &data) { alias = data; }

    QString getFunction(void) { return function; }
    void setFunction(const QString &data) { function = data; }

    int getAddr(void) { return addr; }
    void setAddr (const int &data) { addr = data; }

    int getQuantity(void) { return quantity; }
    void setQuantity (const int &data) { quantity = data; }

    int getScanRate(void) { return scanRate; }
    void setScanRate (const int &data) { scanRate = data; }

    int getCountRows(void) { return countRows; }
    void setCountRows (const int &data) { countRows = data; }

    void setFillDefaultDataDevice(void);
    QStringList getListFunction(void);

    virtual ~DataDevice();
private:

    QUuid uID;
    int slaveId;
    QString alias;
    QString function;
    int addr;
    int quantity;
    int scanRate;
    int countRows;
};
}//namespace DATA
#endif // DATADEVICE_H
