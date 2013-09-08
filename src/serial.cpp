#include "serial.h"

#include <solid/device.h>

#include <QFile>

Serial::Serial() {}

Serial::~Serial() {}

void Serial::updateSerialDevicesList()
{
    QString tmp;

    foreach (const Solid::Device &device,
             Solid::Device::listFromType(Solid::DeviceInterface::SerialInterface,
                                         QString())) {
        tmp = device.udi();
        tmp.remove(0,tmp.indexOf("tty/tty"));
        emit newSerialDeviceFound(tmp);
    }
}

SerialDeviceInfo Serial::info(QString deviceName)
{
    SerialDeviceInfo ret;
    Solid::Device dev;

    ret.writePermission = false;
    ret.readPermission = false;

    foreach (const Solid::Device &device,
             Solid::Device::listFromType(Solid::DeviceInterface::SerialInterface,
                                         QString())) {
        if (device.udi().contains(deviceName)) {
            dev = device;
        }
    }

    ret.vendor = dev.vendor();
    ret.product = dev.product();

    QString dev_name = dev.udi();
    dev_name.remove(0,dev_name.lastIndexOf("tty"));
    QFile devFile("/dev/" + dev_name);
    if (devFile.open(QIODevice::ReadOnly)) {
        ret.readPermission = true;
        devFile.close();
    } else {
        ret.readPermission = false;
    }
    if (devFile.open(QIODevice::WriteOnly)) {
        ret.writePermission = true;
        devFile.close();
    } else {
        ret.writePermission = false;
    }

    return ret;
}
