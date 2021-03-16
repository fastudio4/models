#ifndef DIALOGPORT_H
#define DIALOGPORT_H
#include <QDialog>
#include "ui_port.h"
#include "dataremote.h"

namespace MODEL {

class DialogPort : public QDialog
{
    Q_OBJECT
public:
    DialogPort(QWidget *parent = nullptr);
    virtual ~DialogPort();
private slots:
    void on_btnScanPort_clicked();
    void on_cbxPort_currentIndexChanged(int index);

private:
    Ui::PortSettingDialog port;
    DATA::Data dataPorts;


};
} //namespace MODEL
#endif // DIALOGPORT_H
