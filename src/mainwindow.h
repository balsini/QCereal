#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include "serialsetup.h"

#include <QDebug>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  Ui::MainWindow *ui;
  QDockWidget *ss;
  QSerialPort *serial;


public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  public slots:
  void serialConnected(QSerialPort *p)
  {
    serial = p;
    serial->setParent(this);

    qDebug() << "Serial port connected to MainWindo";
  }
};

#endif // MAINWINDOW_H
