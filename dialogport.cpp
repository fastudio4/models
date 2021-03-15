#include "dialogport.h"

#include <QSerialPortInfo>
#include <QStringList>

#include <QDebug>
#include <QSerialPort>
namespace MODEL {

DialogPort::DialogPort(QWidget *parent)
    :QDialog(parent)
{
    port.setupUi(this);
    listPorts = QSerialPortInfo::availablePorts();
    port.cbxPort->insertItems(0, portName());


}

DialogPort::~DialogPort()
{

}

void DialogPort::defaultSettingPort()
{

}

QStringList DialogPort::portName()
{
    if(!listPorts.isEmpty())
    {
        QStringList port;
        int count =  listPorts.count();
        for(int i = 0; i < count; i++)
        {
            port.append(listPorts[i].portName());
        }
        return port;
    }
    QStringList portClear;
    portClear.clear();
    return portClear;

}

}

void MODEL::DialogPort::on_cbxPort_activated(const QString &arg1)
{
//    qDebug() << arg1;
    QSerialPort *dataPort = new QSerialPort(arg1, this);
    qDebug() << "_____________________________________";
    qDebug() << "Port Description:" <<  dataPort->portName();
    qDebug() << "Baud Rate:" <<  dataPort->baudRate();
    qDebug() << "Data Bits:" <<  dataPort->dataBits();
    qDebug() << "Stop Bits:" <<  dataPort->stopBits();
    qDebug() << "Parity:" <<  dataPort->parity();
    qDebug() << "Flow Control:" <<  dataPort->flowControl();
    qDebug() << "_____________________________________";
//    qDebug() << "Flow Control:" <<  dataPort->Direction();



}
