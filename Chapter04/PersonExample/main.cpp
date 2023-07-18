#include <QCoreApplication>
#include "Person.h"
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p;
    p.setProperty("name", "John");
    p.setProperty("birthday", QDate(2000,9,24));
    p.setProperty("sex","male");

    p.setProperty("haircolor", "brown");

    qDebug() << "--- Get via Properties ---";
    qDebug() << p.property("name") << " : " << p.property("birthday") << " : " << p.property("sex") << p.property("haircolor");

    qDebug() << "--- Get attributes directly ---";
    qDebug() << p.name() << " : " << p.birthday() << " : " << p.sex();

    qDebug() << "--- Get all properties of p via iteration --- ";
    qDebug() << "- static -"; // Print only the static properties
    for (int i = 0; i < p.staticMetaObject.propertyCount(); ++i)
    {
        auto prop = p.staticMetaObject.property(i);
        qDebug() << prop.name() << " = " << prop.read(&p);
    }

    qDebug() << "- dynamic -"; // Print only the dynamics properties
    for (const auto i : p.dynamicPropertyNames())
    {
        qDebug() << i << " = " << p.property(i);
    }

    return a.exec();
}
