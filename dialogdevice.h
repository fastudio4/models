#ifndef DIALOGDEVICE_H
#define DIALOGDEVICE_H
#include <QDialog>
#include "ui_device.h"
namespace MODEL {


class DialogDevice : public QDialog
{
    Q_OBJECT
public:
    DialogDevice(QWidget *parent = nullptr);
    virtual ~DialogDevice();
private:
    Ui::DeviceSettingDialog device;

};

} //namespace MODEL
#endif // DIALOGDEVICE_H
