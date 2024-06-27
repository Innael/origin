#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Stopwatch *stw = new Stopwatch(this);
    connect(stw, &Stopwatch::sig_time_send, this, &MainWindow::stw_started);
    //connect(this, &MainWindow::sig_start_stop(), stw, &Stopwatch::on_start);

}

MainWindow::~MainWindow()
{
    delete ui;   
}

void MainWindow::stw_started()
{
    ui->lb_time->setText(QString("afass"));
}


void MainWindow::on_bt_start_stop_clicked()
{
  stw->on_start();
}

void MainWindow::on_bt_circle_clicked()
{

}

void MainWindow::on_bt_clear_clicked()
{

}







