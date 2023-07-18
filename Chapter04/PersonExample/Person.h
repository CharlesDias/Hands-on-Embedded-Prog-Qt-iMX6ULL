#ifndef PERSON_H
#define PERSON_H

#include <QDate>
#include <QObject>

class Person : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString  name READ name WRITE setName)
    Q_PROPERTY(QDate    birthday READ birthday WRITE setBirthday)
    Q_PROPERTY(Sex      sex READ sex WRITE setSex)

public:
    explicit Person(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    enum Sex {male, female, other, unspecified};
    Q_ENUM(Sex)

    Sex sex() const;
    void setSex(const Sex &sex);

signals:

private:
    QString m_name;
    QDate m_birthday;
    Sex m_sex;
};

#endif // PERSON_H
