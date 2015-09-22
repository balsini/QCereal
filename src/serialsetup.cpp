#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QList>

#include "ui_serialsetup.h"
#include "serialsetup.h"

void SerialSetup::refreshPortNames()
{
  /*
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    ui->comboPort->clear();
    for (int i=0; i<ports.count(); ++i)
        ui->comboPort->addItem(ports.at(i).portName());

    bool portSettingsEnabled = ports.count() > 0;

    ui->comboBaud->setEnabled(portSettingsEnabled);
    ui->comboData->setEnabled(portSettingsEnabled);
    ui->comboParity->setEnabled(portSettingsEnabled);
    ui->comboStop->setEnabled(portSettingsEnabled);
    ui->comboPort->setEnabled(portSettingsEnabled);
    ui->buttonConnect->setEnabled(portSettingsEnabled);
    */
}

SerialSetup::SerialSetup(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SerialSetup)
{
  ui->setupUi(this);

  refreshPortNames();
}

SerialSetup::~SerialSetup()
{
  delete ui;
}

void SerialSetup::on_buttonConnect_clicked()
{
  static bool portConnected = false;

  if (portConnected) {
      //message_manager->disconnect_from_serial();
    } else {
      qDebug() << "Connecting to serial with the following parameters:";
      qDebug() << "name: " << ui->comboBaud->itemText(ui->comboBaud->currentIndex());
      qDebug() << "baud: " << ui->comboBaud->itemText(ui->comboBaud->currentIndex()).toInt();
      qDebug() << "data: " << ui->comboData->itemText(ui->comboData->currentIndex());
      qDebug() << "parity: " << ui->comboParity->itemText(ui->comboParity->currentIndex());
      qDebug() << "stop: " << ui->comboStop->itemText(ui->comboStop->currentIndex());

      /*
        message_manager->connect_to_serial(ui->comboPort->itemText(ui->comboPort->currentIndex()),
                                          ui->comboBaud->itemText(ui->comboBaud->currentIndex()),
                                          ui->comboData->itemText(ui->comboData->currentIndex()),
                                          ui->comboParity->itemText(ui->comboParity->currentIndex()),
                                          ui->comboStop->itemText(ui->comboStop->currentIndex()));
                                          */
    }

  portConnected = !portConnected;

  ui->buttonRefresh->setEnabled(!portConnected);
  ui->comboBaud->setEnabled(!portConnected);
  ui->comboData->setEnabled(!portConnected);
  ui->comboParity->setEnabled(!portConnected);
  ui->comboStop->setEnabled(!portConnected);
  ui->comboPort->setEnabled(!portConnected);

  if (portConnected)
    ui->buttonConnect->setText("Disconnect");
  else
    ui->buttonConnect->setText("Connect");

}
