#include "dialogdevice.h"
namespace MODEL {


DialogDevice::DialogDevice(QWidget *parent)
    :QDialog(parent)
{
    device.setupUi(this);
}

DialogDevice::~DialogDevice()
{

}

} // namespace MODEL
