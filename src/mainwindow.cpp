#include <QDockWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "serialsetup.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ss = new QDockWidget(this);
  //ss->setFeatures(QDockWidget::NoDockWidgetFeatures);
  //pc->setAllowedAreas(Qt::RightDockWidgetArea);
  ss->setWidget(new SerialSetup(this));
  addDockWidget(Qt::LeftDockWidgetArea, ss);

  console = new Console(this);
  console->setEnabled(false);
  setCentralWidget(console);

  connect(ss->widget(), SIGNAL(serialConnected(QSerialPort *)), this, SLOT(serialConnected(QSerialPort *)));

  connect(ss->widget(), SIGNAL(notifyLocalEchoChanged(bool)), console, SLOT(setLocalEchoEnabled(bool)));

  connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
  //http://doc.qt.io/qt-5/qtserialport-terminal-example.html
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::serialConnected(QSerialPort *p)
{
  serial = p;
  serial->setParent(this);

  qDebug() << "Serial port connected to MainWindow";

  console->setEnabled(true);
  connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
  /*
  console->setLocalEchoEnabled(p.localEchoEnabled);
  ui->actionConnect->setEnabled(false);
  ui->actionDisconnect->setEnabled(true);
  ui->actionConfigure->setEnabled(false);
  showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                    .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                    .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
                    */
}

void MainWindow::readData()
{
  QByteArray data = serial->readAll();
  console->putData(data);
}

void MainWindow::writeData(QByteArray data)
{
  qDebug() << "written: " << data;
  serial->write(data);
}
