#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant v;
    v.setValue(10);

    int y = 41 * v.toInt();

    qDebug() << v.toString() << " * 41 = " << y;
    qDebug() << "v as bool = " << v.toBool();
    qDebug() << "v as a list = " << v.toList();

    qDebug() << "----------------------------------";

    QList<QVariant> list;

    list << v;
    list << QVariant(1);
    list << QVariant(2.3);
    list << QVariant("Hello World!");

    qDebug() << "The List: " << list;

    return a.exec();
}
