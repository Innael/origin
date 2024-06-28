#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stw = new Stopwatch(this);
    connect(stw, &Stopwatch::sig_time_send, this, &MainWindow::stw_started);
    connect(stw, &Stopwatch::sig_send_res, this, &MainWindow::circle_stat);
    connect(stw, &Stopwatch::sig_reset, this, &MainWindow::full_restart);
    ui->bt_circle->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;   
}

void MainWindow::stw_started(double time_pass)
{
    ui->lb_time->setText(QString("%1c").arg(time_pass));
}

void MainWindow::circle_stat(int circle_number, double res_time, double best_time)
{
    ui->circle_Browser->append(QString("Круг: %1 \n Время: %2").arg(circle_number).arg(res_time));
    ui->lb_record->setText(QString("%1c").arg(best_time));
}

void MainWindow::full_restart()
{
    ui->circle_Browser->clear();
    ui->lb_time->setText("0.0c");
}


void MainWindow::on_bt_start_stop_clicked()
{
  if (stw->check_time_on() == false){
  stw->on_start();  
  ui->bt_start_stop->setText("Стоп");
  ui->bt_circle->setEnabled(true);
  }
  else
  {
    stw->on_start();
    ui->bt_start_stop->setText("Стaрт");
    ui->bt_circle->setEnabled(false);
  }
}

void MainWindow::on_bt_circle_clicked()
{
   stw->circle_res();
}

void MainWindow::on_bt_clear_clicked()
{

   stw->reset();
}







