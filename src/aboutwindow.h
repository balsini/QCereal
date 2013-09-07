#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>

#include "ui_aboutwindow.h"

class AboutWindow : public QWidget, private Ui::AboutWindow
{
    Q_OBJECT
    
    Ui::AboutWindow * ui;

public:
    explicit AboutWindow(QWidget *parent = 0,  Qt::WindowFlags f = 0);
    ~AboutWindow();
};

#endif // ABOUTWINDOW_H
