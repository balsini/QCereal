#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include "serialsetup.h"
#include "console.h"

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
    Console *console;

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void serialConnected(QSerialPort *p);
    void readData();
    void writeData(QByteArray data);
};

#endif // MAINWINDOW_H
