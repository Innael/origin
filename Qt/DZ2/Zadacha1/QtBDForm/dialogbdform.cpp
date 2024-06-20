#include "dialogbdform.h"
#include "ui_dialogbdform.h"

DialogBDForm::DialogBDForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBDForm)
{
    ui->setupUi(this);
}

DialogBDForm::~DialogBDForm()
{
    delete ui;
}
