#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->currentDateTime->setText(QDateTime::currentDateTime().toString());

    m_updateTimer.setSingleShot(false);
    connect(&m_updateTimer, &QTimer::timeout, this, &MainWindow::updateDisplay);
    m_updateTimer.setInterval(1000);
    m_updateTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->currentDateTime->setText(now.toString());
}

