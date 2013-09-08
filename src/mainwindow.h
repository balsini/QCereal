#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

#include "aboutwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

    Ui::MainWindow * ui;

    AboutWindow * aboutWindow;
    
    void updateSerialDevicesList();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionAbout_triggered();
    void on_RefreshDevices_released();
    void on_DeviceComboBox_currentIndexChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
