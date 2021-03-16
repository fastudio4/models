#include <QSerialPortInfo>
#include <QSerialPort>
#include "dataremote.h"
namespace DATA {


Data::Data()
{
    data.clear();
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
        for(int i = 0; i < ports.count(); i ++)
        {
            portName.append(ports[i].portName());
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

void Data::fillPortData(const QString &name)
{
    QSerialPort *dataPort = new QSerialPort(name);

}

}
