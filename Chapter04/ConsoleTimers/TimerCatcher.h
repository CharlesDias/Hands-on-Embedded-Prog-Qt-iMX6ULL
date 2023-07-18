#ifndef TIMERCATCHER_H
#define TIMERCATCHER_H

#include <QObject>
#include <QTimer>

class TimerCatcher : public QObject
{
    Q_OBJECT
public:
    explicit TimerCatcher(QObject *parent = nullptr);

signals:
    void newCount(int count);

public slots:
    void catchExpiredTimer();   ///< called when m_timer timesout
    void printCountDirect(int count);
    void printCountQueued(int count);

private:
    QTimer m_timer;              ///< my timer
    int m_count;
};

#endif // TIMERCATCHER_H
