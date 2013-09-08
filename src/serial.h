#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QString>
#include <QList>

typedef struct SerialDeviceInfo_ {
    QString name;
    QString vendor;
    QString product;
    bool writePermission;
    bool readPermission;
} SerialDeviceInfo;

class Serial : public QObject
{
    Q_OBJECT

    QList<QString> serialDevicesList;

public:
    Serial();
    ~Serial();

    SerialDeviceInfo info(QString deviceName);

public slots:
    void updateSerialDevicesList();

signals:
    void newSerialDeviceFound(QString);
};

#endif // SERIAL_H
