#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aboutWindow = new AboutWindow(this, Qt::Window);

    this->setWindowTitle("KSerial");

    connect(&serial, SIGNAL(newSerialDeviceFound(QString)), this, SLOT(newSerialDeviceFound(QString)));
    connect(this, SIGNAL(updateSerialDevicesList()), &serial, SLOT(updateSerialDevicesList()));

    on_RefreshDevices_released();
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
    ui->DeviceComboBox->clear();
    emit updateSerialDevicesList();
}

void MainWindow::newSerialDeviceFound(QString deviceName)
{
    ui->DeviceComboBox->addItem(deviceName);
}

void MainWindow::on_DeviceComboBox_currentIndexChanged(const QString &deviceName)
{
    SerialDeviceInfo deviceInfo = serial.info(deviceName);

    if (deviceInfo.readPermission)
        ui->DeviceReadPermission->setText("Read: <span style=\"background-color:lightgreen\">YES</span>");
    else
        ui->DeviceReadPermission->setText("Read: <span style=\"background-color:red\">NO</span>");

    if (deviceInfo.writePermission)
        ui->DeviceWritePermission->setText("Write: <span style=\"background-color:lightgreen\">YES</span>");
    else
        ui->DeviceWritePermission->setText("Write: <span style=\"background-color:red\">NO</span>");

    if (deviceInfo.vendor.length() > 0)
        ui->DeviceDescription->setText(deviceInfo.vendor + ": " + deviceInfo.product);
    else
        ui->DeviceDescription->setText(deviceInfo.vendor + deviceInfo.product);
}
