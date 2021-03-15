#include "datartu.h"
namespace MODEL {


DataRTU::DataRTU()
{
    portName.clear();
    mapPort.clear();
    timePort.clear();
    devId.clear();
    funcMap.clear();
}

QStringList DataRTU::funcList()
{
    QStringList function = { "01 Read Coils",
                             "02 Read discrete inputs",
                             "03 Read holding registers",
                             "04 Read input registers",
                             "05 Write single coils",
                             "06 Write single registers",
                             "15 Write multiple coils",
                             "16 Write multiple registers"};
    return function;
}

QStringList DataRTU::baudRate()
{
    QStringList baudRate = {"1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200" };
    return baudRate;
}

QStringList DataRTU::dataBits()
{
    QStringList dataBits = {"5","6","7","8"};
    return dataBits;
}

void DataRTU::mapPortDefaultData()
{

}

DataRTU::~DataRTU()
{

}

} //namespace MODEL
