#ifndef DIALOGPORT_H
#define DIALOGPORT_H
#include <QDialog>
#include "ui_port.h"
#include <QSerialPortInfo>
namespace MODEL {

class DialogPort : public QDialog
{
    Q_OBJECT
public:
    DialogPort(QWidget *parent = nullptr);
    virtual ~DialogPort();
    void defaultSettingPort(void);
private slots:
    void on_cbxPort_activated(const QString &arg1);
    void on_btnScanPort_clicked();
    void on_cbxPort_currentIndexChanged(const QString &arg1);

private:
    QStringList portName(void);
    Ui::PortSettingDialog port;
    QList<QSerialPortInfo> listPorts;

};
} //namespace MODEL
#endif // DIALOGPORT_H
