#include "dbaccess.h"
#include "ui_dbaccess.h"

DBAccess::DBAccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBAccess)
{
    ui->setupUi(this);
}

DBAccess::~DBAccess()
{
    delete ui;
}
