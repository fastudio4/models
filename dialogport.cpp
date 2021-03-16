#include "dialogport.h"

#include <QDebug>

namespace MODEL {

DialogPort::DialogPort(QWidget *parent)
    :QDialog(parent)
{
    port.setupUi(this);
    port.cbxPort->clear();
    port.cbxPort->addItems(dataPorts.listPorts());
}

DialogPort::~DialogPort()
{

}

}

void MODEL::DialogPort::on_btnScanPort_clicked()
{
    port.cbxPort->clear();
    port.cbxPort->addItems(dataPorts.listPorts());
}

void MODEL::DialogPort::on_cbxPort_currentIndexChanged(int index)
{
    port.cbxBaudRate->addItems(dataPorts.getListBaudRate());
    port.cbxBaudRate->setCurrentIndex(dataPorts.indexBaudRate(index));
    port.cbxDataBits->addItems(dataPorts.getListDataBits());
    port.cbxDataBits->setCurrentIndex(dataPorts.indexDataBits(index));
    port.cbxFlowControl->addItems(dataPorts.getListFlowControl());
    port.cbxFlowControl->setCurrentIndex(dataPorts.indexFlowControl(index));
    port.cbxParity->addItems(dataPorts.getListParity());
    port.cbxParity->setCurrentIndex(dataPorts.indexParity(index));
    port.cbxStopBits->addItems(dataPorts.getListStopBits());
    port.cbxStopBits->setCurrentIndex(dataPorts.indexStopBits(index));

}
