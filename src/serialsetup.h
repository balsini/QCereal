#ifndef SERIALSETUP_H
#define SERIALSETUP_H

#include <QWidget>

namespace Ui {
  class SerialSetup;
}

class SerialSetup : public QWidget
{
  Q_OBJECT

  Ui::SerialSetup *ui;
  void refreshPortNames();

public:
  explicit SerialSetup(QWidget *parent = 0);
  ~SerialSetup();

private slots:
  void refreshButtonClicked() {
    refreshPortNames();
  }
  void on_buttonConnect_clicked();
};

#endif // SERIALSETUP_H
