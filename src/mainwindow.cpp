#include "mainwindow.h"

#include <solid/devicenotifier.h>
#include <solid/device.h>

#include <QFile>

void MainWindow::updateSerialDevicesList()
{
    QString tmp;
    ui->DeviceComboBox->clear();
    foreach (const Solid::Device &device,
             Solid::Device::listFromType(Solid::DeviceInterface::SerialInterface,
                                         QString())) {
        tmp = device.udi();
        tmp.remove(0,tmp.indexOf("tty/tty"));
        ui->DeviceComboBox->addItem(tmp);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aboutWindow = new AboutWindow(this, Qt::Window);

    this->setWindowTitle("KSerial");

    updateSerialDevicesList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    aboutWindow->show();
}

void MainWindow::on_RefreshDevices_released()
{
    updateSerialDevicesList();
}

void MainWindow::on_DeviceComboBox_currentIndexChanged(const QString &arg1)
{
    foreach (const Solid::Device &device,
             Solid::Device::listFromType(Solid::DeviceInterface::SerialInterface,
                                         QString())) {
        if (device.udi().contains(arg1)) {
            // Prints the device information
            QString vendor = device.vendor();
            if (vendor.length() > 0)
                vendor.append(": ");
            ui->DeviceDescription->setText(vendor + device.product());

            // Checks device permissions
            QString dev_name = device.udi();
            dev_name.remove(0,dev_name.lastIndexOf("tty"));
            QFile dev("/dev/" + dev_name);
            if (dev.open(QIODevice::ReadOnly)) {
                ui->DeviceReadPermission->setText("Read: <span style=\"background-color:lightgreen\">YES</span>");
                dev.close();
            } else {
                ui->DeviceReadPermission->setText("Read: <span style=\"background-color:red\">NO</span>");
            }
            if (dev.open(QIODevice::WriteOnly)) {
                ui->DeviceWritePermission->setText("Write: <span style=\"background-color:lightgreen\">YES</span>");
                dev.close();
            } else {
                ui->DeviceWritePermission->setText("Write: <span style=\"background-color:red\">NO</span>");
            }
            return;
        }
    }
}
