#include <QSerialPortInfo>
#include <QList>

#include <QDebug>

#include "ui_serialsetup.h"
#include "serialsetup.h"

#include <assert.h>

int SerialSetup::refreshPortNames()
{
  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
  ui->portCombo->clear();
  for (int i=0; i<ports.count(); ++i)
    ui->portCombo->addItem(ports.at(i).portName());

  portConnected = false;

  return ports.count();
}

SerialSetup::SerialSetup(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SerialSetup)
{
  ui->setupUi(this);

  if (refreshPortNames() > 0)
    ui->portCombo->setCurrentIndex(0);
  ui->baudCombo->setCurrentIndex(7);
  ui->dataCombo->setCurrentIndex(3);
  ui->stopCombo->setCurrentIndex(0);
  ui->parityCombo->setCurrentIndex(0);
  ui->flowCombo->setCurrentIndex(0);

  ui->echoCheckBox->setChecked(true);
}

SerialSetup::~SerialSetup()
{
  delete ui;
}

void SerialSetup::connectButtonClicked()
{
  if (portConnected) {
    //message_manager->disconnect_from_serial();
  } else {
    qDebug() << "Connecting to serial with the following parameters:";
    qDebug() << "name: " << portName;
    qDebug() << "baud: " << baudRate;
    qDebug() << "data: " << dataBits;
    qDebug() << "parity bits: " << parityBits;
    qDebug() << "stop: " << stopBits;
    qDebug() << "parity: " << parity;
    qDebug() << "flow: " << flowControl;
    qDebug() << "echo: " << localEcho;

    QSerialPort *serial = new QSerialPort();
/*
    serial->setPortName(ui->comboBaud->itemText(ui->comboBaud->currentIndex()));
    serial->setBaudRate(ui->comboBaud->itemText(ui->comboBaud->currentIndex()).toInt());
    serial->setDataBits(ui->comboData->itemText(ui->comboData->currentIndex()));
    serial->setParity(ui->comboParity->itemText(ui->comboParity->currentIndex()));
    serial->setStopBits(ui->comboStop->itemText(ui->comboStop->currentIndex()));
    //serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

        emit serialConnected(p);
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
*/
    /*
        message_manager->connect_to_serial(ui->comboPort->itemText(ui->comboPort->currentIndex()),
                                          ui->comboBaud->itemText(ui->comboBaud->currentIndex()),
                                          ui->comboData->itemText(ui->comboData->currentIndex()),
                                          ui->comboParity->itemText(ui->comboParity->currentIndex()),
                                          ui->comboStop->itemText(ui->comboStop->currentIndex()));
                                          */
  }

  portConnected = !portConnected;

  ui->refreshButton->setEnabled(!portConnected);
  ui->baudCombo->setEnabled(!portConnected);
  ui->dataCombo->setEnabled(!portConnected);
  ui->parityCombo->setEnabled(!portConnected);
  ui->stopCombo->setEnabled(!portConnected);
  ui->portCombo->setEnabled(!portConnected);
  ui->flowCombo->setEnabled(!portConnected);

  if (portConnected)
    ui->connectButton->setText("Disconnect");
  else
    ui->connectButton->setText("Connect");

}

void SerialSetup::refreshButtonClicked()
{
  refreshPortNames();
}

void SerialSetup::serialPortChanged(QString s)
{
  qDebug() << "serialPortChanged to " << s;

  QSerialPortInfo portInfo(s);

  qDebug() << portInfo.description();

  portName = s;

  ui->connectButton->setEnabled(true);
}

void SerialSetup::flowControlChanged(QString s)
{
  qDebug() << "flowControlChanged to" << s;

  if (s == "None") {
    flowControl = QSerialPort::NoFlowControl;
    return;
  }
  if (s == "HW") {
    flowControl = QSerialPort::HardwareControl;
    return;
  }
  if (s == "SW") {
    flowControl = QSerialPort::SoftwareControl;
    return;
  }
}

void SerialSetup::baudRateChanged(QString s) {
  qDebug() << "baudRateChanged to " << s;

  switch (s.toInt()) {
    case QSerialPort::Baud1200:
      baudRate = QSerialPort::Baud1200;
      break;
    case QSerialPort::Baud2400:
      baudRate = QSerialPort::Baud2400;
      break;
    case QSerialPort::Baud4800:
      baudRate = QSerialPort::Baud4800;
      break;
    case QSerialPort::Baud9600:
      baudRate = QSerialPort::Baud9600;
      break;
    case QSerialPort::Baud19200:
      baudRate = QSerialPort::Baud19200;
      break;
    case QSerialPort::Baud38400:
      baudRate = QSerialPort::Baud38400;
      break;
    case QSerialPort::Baud57600:
      baudRate = QSerialPort::Baud57600;
      break;
    case QSerialPort::Baud115200:
      baudRate = QSerialPort::Baud115200;
      break;
    default:
      qDebug() << "Unknown baud rate";
      assert(false);
      break;
  }
}

void SerialSetup::dataChanged(QString s)
{
  qDebug() << "dataChanged to " << s;

  switch (s.toInt()) {
    case QSerialPort::Data5:
      dataBits = QSerialPort::Data5;
      break;
    case QSerialPort::Data6:
      dataBits = QSerialPort::Data6;
      break;
    case QSerialPort::Data7:
      dataBits = QSerialPort::Data7;
      break;
    case QSerialPort::Data8:
      dataBits = QSerialPort::Data8;
      break;
    default:
      qDebug() << "Unknown data bits";
      assert(false);
      break;
  }
}

void SerialSetup::stopBitsChanged(QString s)
{
  qDebug() << "stopBitsChanged to " << s;

  if (s == "1") {
      stopBits = QSerialPort::OneStop;
      return;
  }
  if (s == "1.5") {
      stopBits = QSerialPort::OneAndHalfStop;
      return;
  }
  if (s == "2") {
      stopBits = QSerialPort::TwoStop;
      return;
  }
}

void SerialSetup::parityChanged(QString s) {
  qDebug() << "parityChanged to " << s;

  if (s == "None") {
      parity = QSerialPort::NoParity;
      return;
  }
  if (s == "Even") {
      parity = QSerialPort::EvenParity;
      return;
  }
  if (s == "Odd") {
      parity = QSerialPort::OddParity;
      return;
  }
  if (s == "Space") {
      parity = QSerialPort::SpaceParity;
      return;
  }
  if (s == "Mark") {
      parity = QSerialPort::MarkParity;
      return;
  }
}

void SerialSetup::localEchoChanged(bool s) {
  qDebug() << "localEchoChanged to" << s;

  localEcho = s;
}
