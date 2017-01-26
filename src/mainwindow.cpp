#include <QDockWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "serialsetup.h"
#include "console.h"

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

  Console *console = new Console(this);
  console->setEnabled(false);
  setCentralWidget(console);

  connect(ss->widget(), SIGNAL(serialConnected(QSerialPort *)), this, SLOT(serialConnected(QSerialPort *)));

  //http://doc.qt.io/qt-5/qtserialport-terminal-example.html
}

MainWindow::~MainWindow()
{
  delete ui;
}
