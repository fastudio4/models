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
    on_btnScanPort_clicked();
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
        QStringList  port;
        int count =  listPorts.count();
        for(int i = 0; i < count; i++)
        {
            port.append(listPorts[i].portName());
        }
        return port;
    }
    QList<QString> portClear;
    portClear.clear();
    return portClear;

}

}

void MODEL::DialogPort::on_cbxPort_activated(const QString &arg1)
{
    qDebug() << arg1 + "!!!";





}

void MODEL::DialogPort::on_btnScanPort_clicked()
{
    listPorts.clear();
    listPorts = QSerialPortInfo::availablePorts();
    if (!listPorts.isEmpty())
    {
        if(listPorts.count() == 1)
        {
            on_cbxPort_currentIndexChanged(listPorts[0].portName());
        }
        port.cbxPort->clear();
        port.cbxPort->setDisabled(false);
        port.cbxPort->insertItems(0, portName());
    }
    else
    {
        port.cbxPort->clear();
        port.cbxPort->insertItem(0, tr("Not found port!"));
        port.cbxPort->setDisabled(true);
    }


}

void MODEL::DialogPort::on_cbxPort_currentIndexChanged(const QString &arg1)
{
    if (portName().contains(arg1))
    {
        QSerialPort *dataPort = new QSerialPort(arg1, this);
        QString baudRate = QString::number(dataPort->baudRate());
        port.cbxBaudRate->insertItem(0,baudRate);
//        qDebug() << "_____________________________________";
//        qDebug() << "Port name:" <<  dataPort->portName();
        qDebug() << "Baud Rate:" <<  dataPort->baudRate();
//        qDebug() << "Data Bits:" <<  dataPort->dataBits();
//        qDebug() << "Stop Bits:" <<  dataPort->stopBits();
//        qDebug() << "Parity:" <<  dataPort->parity();
//        qDebug() << "Flow Control:" <<  dataPort->flowControl();
//        qDebug() << "_____________________________________";
//        qDeleteAll(dataPort) ;
    }
}
