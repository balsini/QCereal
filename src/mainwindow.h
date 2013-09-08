#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

#include "aboutwindow.h"
#include "serial.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

    Ui::MainWindow * ui;

    AboutWindow * aboutWindow;

    Serial serial;

private slots:
    void on_actionAbout_triggered();
    void on_RefreshDevices_released();
    void on_DeviceComboBox_currentIndexChanged(const QString &deviceName);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void newSerialDeviceFound(QString deviceName);

signals:
    void updateSerialDevicesList();
};

#endif // MAINWINDOW_H
