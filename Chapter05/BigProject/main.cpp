#include "MockTempSensor.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MockTempSensor mockTemp;
    MainWindow w(&mockTemp);

    w.show();
    return a.exec();
}
