#ifndef DATARTU_H
#define DATARTU_H
#include <QString>
#include <QMap>
#include <QList>
namespace MODEL {


class DataRTU
{
public:
    DataRTU();
    QStringList funcList(void);
    QStringList baudRate(void);
    QStringList dataBits(void);
    QStringList direction(void);
    void mapPortDefaultData(void);
    QString getPortName() { return portName; }


    virtual ~DataRTU();
private:
    QString portName;
    QMap<QString, QString> mapPort;
    QMap<QString, int> timePort;
    QList<int> devId;
    QMap<QString, int> funcMap;




};

} //namespace MODEL
#endif // DATARTU_H
