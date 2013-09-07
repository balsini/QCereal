#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent,f),
    ui(new Ui::AboutWindow)//ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("About");
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
