#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    connect(udpWorker, &UDPworker::sig_sendTextToGUI, this, &MainWindow::DisplayText);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        udpWorker->SendDatagram(dataToSend, 1);
        timer->start(TIMER_DELAY);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}


void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}

void MainWindow::DisplayText(QString data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append(data);


}


void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}


void MainWindow::on_pushButton_clicked()
{
    QString text_to_send = ui->text_field->toPlainText();
    QByteArray textArr;
    QDataStream textStream(&textArr, QIODevice::WriteOnly);

    textStream << text_to_send;


    udpWorker->SendDatagram(textArr, 2);

    //ui->te_result->append(text_to_send);
}

