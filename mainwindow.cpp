#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QAudioOutput>
#include <QTimer>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    slotIsRunning_ = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (slotIsRunning_)
        qDebug() << "HMMM";

    slotIsRunning_ = true;
    QAudioFormat format;
    //QAudioOutput* audioPlayer_ = new QAudioOutput(format, this);
    qDebug() << "QAudioOutput created";

    sleep(1); // some work

    //delete audioPlayer_;
    qDebug() << "QAudioOutput deleted";
    slotIsRunning_ = false;
    QTimer::singleShot(std::rand()%50, this, &MainWindow::on_pushButton_clicked);
}
