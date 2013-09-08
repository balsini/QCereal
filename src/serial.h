#ifndef SERIAL_H
#define SERIAL_H

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <QObject>
#include <QString>
#include <QList>

#include <termios.h>
#include <fcntl.h>

/**
 * This struct contains the basic serial connection
 * parameters.
 */

typedef struct SerialConfiguration_ {
    QString device;
    unsigned int baud_rate;
    unsigned char parity;
    unsigned char bits;
    unsigned char stop_bits;
} SerialConfiguration;

/**
 * This struct contains the basic serial device
 * information.
 */

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

    int tty_fd;
    SerialConfiguration serialConfig;  // Temporary configuration
    struct termios attribs; // Real configuration
    fd_set select_set;

public:
    Serial();
    ~Serial();

    /**
     * Retrieves the device information.
     * @param deviceName The name of the device.
     * @return The struct containing the info.
     */

    SerialDeviceInfo info(QString deviceName);

    /**
         * Writes a string to serial port.
         * @param str The string to be sent.
         * @param len The string length.
         * @return The bytes sent number.
         */

    int writeS(unsigned char * str, unsigned int len);

    /**
         * Writes a char to serial port.
         * @param c The character to be sent.
         * @return The bytes sent number.
         */

    int writeC(unsigned char c);

    /**
         * Reads a string from serial port. This function
         * has no timeout, so it may lock forever if no data
         * is received.
         * @param buffer Buffer in which the string will be
         * stored.
         * @param nbytes The desired string length.
         * @return The number of bytes received.
         */

    int readS(unsigned char * buffer, unsigned int nbytes);

    /**
         * Reads a character from serial port. This function
         * has no timeout, so it may lock forever if no data
         * is received.
         * @param buff Buffer in which the char will be
         * stored.
         * @return The number of bytes received.
         */

    int readC(unsigned char * buff);

    /**
         * Sets the serial configuration.
         * @param config The struct containing all the basic
         * configuration parameters.
         */

    void setConfig(SerialConfiguration config);

    /**
         * Establishes the serial connection.
         * @return The file descriptor associated to
         * the serial device.
         */

    int connect();

    /**
         * Closes the file descriptor associated to
         * the serial device.
         */

    void disconnect();

public slots:
    void updateSerialDevicesList();

signals:
    void newSerialDeviceFound(QString);
};

#endif // SERIAL_H
