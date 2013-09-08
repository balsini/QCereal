#include "mainwindow.h"

#include <solid/devicenotifier.h>
#include <solid/device.h>

void MainWindow::updateSerialDevicesList()
{
    QString tmp;
    ui->DeviceComboBox->clear();
    foreach (const Solid::Device &device, Solid::Device::allDevices()) {
        if (device.udi().contains("tty")) {
            tmp = device.udi();
            tmp.remove(0,tmp.indexOf("tty/tty"));
            ui->DeviceComboBox->addItem(tmp);
        }
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
