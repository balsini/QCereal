#include <cstdlib>

#include <KApplication>
#include <KAboutData>
#include <KCmdLineArgs>
#include <KMessageBox>
#include <KLocale>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    KAboutData aboutData(
                // The program name used internally.
                "KSerial",
                // The message catalog name
                // If null, program name is used instead.
                0,
                // A displayable program name string.
                ki18n("KSerial"),
                // The program version string.
                "0.01",
                // Short description of what the app does.
                ki18n("Serial port communication tool"),
                // The license this code is released under
                KAboutData::License_GPL,
                // Copyright Statement
                ki18n("(c) 2013"),
                // Optional text shown in the About box.
                // Can contain any information desired.
                ki18n("Some text..."),
                // The program homepage string.
                "https://github.com/balsini/KSerial",
                // The bug report email address
                "alessio.balsini@gmail.com");

    KCmdLineArgs::init( argc, argv, &aboutData );

    KApplication app;

    MainWindow * window = new MainWindow();
    window->show();
    
    return app.exec();
}
