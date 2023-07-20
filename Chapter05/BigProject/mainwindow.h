#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "TemperatureSensorIF.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TemperatureSensorIF *tempSensor, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateDisplay();
    void updateTempDisplay(QDateTime timestamp, float temperature);

private:
    Ui::MainWindow *ui;
    QTimer m_updateTimer;
    TemperatureSensorIF *m_tempSensor;
};
#endif // MAINWINDOW_H
