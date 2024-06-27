#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Stopwatch *stw;    

public slots:
    void stw_started();

private slots:


    void on_bt_clear_clicked();

    void on_bt_start_stop_clicked();

    void on_bt_circle_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
