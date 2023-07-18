#include "TimerCatcher.h"

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TimerCatcher tc;

    QTextStream aCout(stdout);  // Create a strem to stdout
    QTimer tocTimer;
    tocTimer.setInterval(1000);
    tocTimer.setSingleShot(false);

    // connect to the lambda function
    QObject::connect(&tocTimer, &QTimer::timeout, [&aCout] () {
        aCout << "tic " << Qt::endl;
    });

    tocTimer.start();   // start the timer

    return a.exec();
}
