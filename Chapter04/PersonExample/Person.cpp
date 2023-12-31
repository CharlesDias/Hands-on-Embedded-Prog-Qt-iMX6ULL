#include "Person.h"

Person::Person(QObject *parent)
    : QObject{parent}
{

}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &name)
{
    m_name = name;
}

QDate Person::birthday() const
{
    return m_birthday;
}

void Person::setBirthday(const QDate &birthday)
{
    m_birthday = birthday;
}

Person::Sex Person::sex() const
{
    return m_sex;
}

void Person::setSex(const Sex &sex)
{
    m_sex = sex;
}
