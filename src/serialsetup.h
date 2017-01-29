#ifndef SERIALSETUP_H
#define SERIALSETUP_H

#include <QWidget>
#include <QSerialPort>

#include <QDebug>

namespace Ui {
  class SerialSetup;
}

class SerialSetup : public QWidget
{
    Q_OBJECT

    Ui::SerialSetup *ui;
    int refreshPortNames();
    bool portConnected;

    QString portName;
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QSerialPort::FlowControl flowControl;
    bool localEcho;

  public:
    explicit SerialSetup(QWidget *parent = 0);
    ~SerialSetup();

  signals:
    void serialConnected(QSerialPort *);
    void notifyLocalEchoChanged(bool val);

  private slots:
    void refreshButtonClicked();
    void connectButtonClicked();

    void serialPortChanged(QString s);
    void flowControlChanged(QString s);

    void baudRateChanged(QString s);
    void dataChanged(QString s);
    void stopBitsChanged(QString s);
    void parityChanged(QString s);
    void localEchoChanged(bool s);
};

#endif // SERIALSETUP_H
