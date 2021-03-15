#include "datadevice.h"
namespace DATA {

DataDevice::DataDevice()
{
    uID = QUuid::createUuid();
    slaveId = 0;
    alias.clear();
    function.clear();
    addr = 0;
    quantity = 0;
    scanRate = 0;
    countRows = 0;
}

void DataDevice::setFillDefaultDataDevice()
{
    slaveId = 2;
    function = "03 Read holding registers";
    addr = 0;
    quantity = 10;
    scanRate = 1000;
    countRows = 10;
}

QStringList DataDevice::getListFunction()
{
    QStringList function = {     "01 Read Coils",
                                 "02 Read discrete inputs",
                                 "03 Read holding registers",
                                 "04 Read input registers",
                                 "05 Write single coils",
                                 "06 Write single registers",
                                 "15 Write multiple coils",
                                 "16 Write multiple registers"};
        return function;
}

DataDevice::~DataDevice()
{

}

}//namespace DATA
