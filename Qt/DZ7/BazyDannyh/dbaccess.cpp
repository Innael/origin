#include "dbaccess.h"
#include "ui_dbaccess.h"
#include "database.h"

DBAccess::DBAccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBAccess)
{
    ui->setupUi(this);
    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
}

DBAccess::~DBAccess()
{
    delete ui;
}


void DBAccess::on_buttonBox_accepted()
{

    data[hostName] = ui->Ed_host_name->text();
    data[dbName] = ui->Ed_BD_name->text();
    data[login] = ui->Ed_login->text();
    data[pass] = ui->db_lineEdit_pass->text();
    data[port] = ui->spin_port_number->text();

    emit sig_sendData(data);

}
