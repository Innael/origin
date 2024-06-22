#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::vector<QString> tl {"Forsaken Child of Ancient Times" , "Forlorn Child of Archaic Winds" ,
                            "Moon in One's Cup" , "Above the Sea of Clouds" ,
                            "Time to Say Farewell" , "The Land of Her Serenity",
                            "Caelestinum Finale Termini" , "Symphony of Boreal Wind",
                            "Never-Ending Performance" , "Wrath of Monoceros Caeli"};

    for (int i = 0; i < 10 ; ++i ){
        ui->treck_list->addItem(tl[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treck_list_currentIndexChanged(int index)
{
    ui->playing_treck->setText(ui->treck_list->currentText());
}


void MainWindow::on_pump_toggled(bool checked)
{
    if (ui->main_mode->isChecked()) {
    int di = ui->depot->value();
    ++di;
    ui->depot->setValue(di);

    if (di > 10) ui->depot->setValue(0);
    }
}

