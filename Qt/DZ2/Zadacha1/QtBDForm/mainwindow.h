#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogbdform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mw_dialogButton_accepted();

    void on_mw_dialogButton_rejected();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DialogBDForm BDForm;
};
#endif // MAINWINDOW_H
