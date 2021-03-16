#include "dataport.h"
namespace DATA {


DataPort::DataPort()
{
    portName.clear();
    aliasPortName.clear();
    baudRate.clear();
    dataBits.clear();
    flowControl.clear();
    parity.clear();
    stopBits.clear();
    responseTimeout = 2000;
    deleyBetweenPull = 1000;
    listDevice.clear();
}


QList<int> DataPort::listSlaveId()
{
    if (!listDevice.isEmpty())
    {
        QList<int> listDevId;
        int count = listDevice.count();
        for (int i = 0; i < count; i++)
        {
            DATA::DataDevice dev = listDevice.at(i);
            listDevId.append(dev.getSlaveId());
        }
        return listDevId;
    }
    QList<int> listClear;
    listClear.clear();
    return listClear;
}


void DataPort::newSlaveDevice()
{
    if (listDevice.isEmpty())
    {
        DATA::DataDevice newDevice;
        newDevice.setFillDefaultDataDevice();
        listDevice.append(newDevice);
    }
    else
    {
        QList<int> listDevId = listSlaveId();
        DATA::DataDevice newDevice;
        newDevice.setFillDefaultDataDevice();
        newDevice.setSlaveId(listDevId.last() + 1);
        addDevice(&newDevice);
    }
}

void DataPort::addDevice(DATA::DataDevice *newDev)
{
    listDevice.append(*newDev);
}

void DataPort::editDevice(int slaveId, int newSlaveId, DATA::DataDevice *newDevData)
{
    int count = listDevice.count();
    for(int i = 0; i < count; i++)
    {
        if(listDevice[i].getSlaveId() == slaveId)
        {
            listDevice[i].setAliasDevice(newDevData->getAliasDevice());
            listDevice[i].setFunction(newDevData->getFunction());
            listDevice[i].setAddr(newDevData->getAddr());
            listDevice[i].setQuantity(newDevData->getQuantity());
            listDevice[i].setScanRate(newDevData->getScanRate());
            listDevice[i].setCountRows(newDevData->getCountRows());

            if(slaveId != newSlaveId)
            {
                listDevice[i].setSlaveId(newSlaveId);
            }
        }
    }
}


void DataPort::deleteDevice(QUuid Id)
{
    if(!listDevice.isEmpty())
    {
        int count = listDevice.count();
        for(int i = 0; i < count; i++)
        {
            if(listDevice[i].getUid() == Id)
            {
                listDevice.removeAt(i);
            }
        }
    }
}

DataPort::~DataPort()
{

}

}//namespace DATA
