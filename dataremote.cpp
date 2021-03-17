#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include "dataremote.h"
namespace DATA {


Data::Data()
{
    data.clear();
    portsName.clear();
}

Data::~Data()
{

}

QStringList Data::uploadListPort()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    if (!ports.isEmpty())
    {
        QStringList portName;
        portName.clear();
        portsName.clear();
        for(int i = 0; i < ports.count(); i ++)
        {
            portName.append(ports[i].portName());
            portsName.append(ports[i].portName());
            fillPortData(ports[i].portName());
        }
        return portName;
    }
    else
    {
        QStringList emptyPort;
        emptyPort.clear();
        return emptyPort;
    }
}

int Data::indexPortName(const QString &portName)
{
    return portsName.indexOf(portName);
}

int Data::indexBaudRate(int indexPort)
{
    QString baudRate = data[indexPort].getBaudRate();
    QList<QString> listBaudRate = {"1200", "2400", "4800",
                                   "9600", "19200", "38400",
                                   "57600", "115200" };
    return listBaudRate.indexOf(baudRate);
}

int Data::indexDataBits(int indexPort)
{
    QString dataBits = data[indexPort].getDataBits();
    QList<QString> listDataBits = {"5","6","7","8"};
    return listDataBits.indexOf(dataBits);

}

int Data::indexFlowControl(int indexPort)
{
    QString flowControl = data[indexPort].getFlowControl();
    QList<QString> listFlowControl = {"NoFlowControl", "HardwareControl",
                                      "SoftwareControl", "UnknownFlowControl"};
    return listFlowControl.indexOf(flowControl);
}

int Data::indexParity(int indexPort)
{
    QString parity = data[indexPort].getParity();
    QList<QString> listParity = {"No Parity", "Even Parity", "Odd Parity",
                                 "Space Parity", "Mark Parity", "Unknown Parity"};
    return listParity.indexOf(parity);
}

int Data::indexStopBits(int indexPort)
{
    QString stopBits = data[indexPort].getStopBits();
    QList<QString> listStopBits = {"1","1.5", "2"};
    return listStopBits.indexOf(stopBits);
}

void Data::fillPortData(const QString &namePort)
{
    QSerialPort *dataPort = new QSerialPort(namePort);
    DataPort onePort;
    onePort.setBaudRate(QString::number(dataPort->baudRate()));
    onePort.setDataBits(QString::number(dataPort->dataBits()));
    onePort.setFlowControl(QString::number(dataPort->flowControl()));
    onePort.setParity(QString::number(dataPort->parity()));
    onePort.setStopBits(QString::number(dataPort->stopBits()));
    data.append(onePort);
    delete dataPort;
}

QStringList Data::getListBaudRate()
{
    QStringList baudRate = {"1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200" };
    return baudRate;
}

QStringList Data::getListDataBits()
{
    QStringList dataBits = {"5","6","7","8"};
    return dataBits;
}

QStringList Data::getListFlowControl()
{
    QStringList flowControl = {"No Flow Control", "Hardware Control",
                               "Software Control", "Unknown Flow Control"};
    return flowControl;
}

QStringList Data::getListParity()
{
    QStringList parity = {"No Parity", "Even Parity", "Odd Parity",
                          "Space Parity", "Mark Parity", "Unknown Parity"};
    return parity;
}

QStringList Data::getListStopBits()
{
    QStringList stopBits = {"1","1.5", "2"};
    return stopBits;
}

}
