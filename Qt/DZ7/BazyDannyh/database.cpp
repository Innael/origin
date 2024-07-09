#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();

}

DataBase::~DataBase()
{
    delete dataBase;
    if (all_tab != nullptr) delete all_tab;    

}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());
    dataBase->open();    

    ///Тут должен быть код ДЗ


    bool status;
    status = dataBase->open( );



    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QTableView *tw , QString request)
{

    if (request == "Все"){
        all_tab = new QSqlTableModel(this, *dataBase);

        all_tab->setTable("film");
        all_tab->setEditStrategy(QSqlTableModel::OnManualSubmit);
        all_tab->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
        all_tab->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));

        tw->setModel(all_tab);        
        tw->hideColumn(0);
        for(int i = 3; i < 14 ; ++i){
            tw->hideColumn(i);
        }
        //tw->setColumnWidth(1,130);
        //tw->setColumnWidth(2,500);   // - оставлено для опциональной подгонки размеров столбцов, так как описания описания достаточно длинные
        tw->resizeColumnsToContents();

        all_tab->select();

        emit sig_SendDataFromDB();
    }
    else if (request == "Комедия"){
        choice_req = new QSqlQueryModel(this);
        choice_req->setQuery("SELECT title, description FROM film f JOIN film_category fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id WHERE c.name = 'Comedy'");
        choice_req->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
        choice_req->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));

        tw->setModel(choice_req);
        emit sig_SendDataFromDB();
    }
    else if (request == "Ужасы"){
        choice_req = new QSqlQueryModel(this);
        choice_req->setQuery("SELECT title, description FROM film f JOIN film_category fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id WHERE c.name = 'Horror'");
        choice_req->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
        choice_req->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));

        tw->setModel(choice_req);
        emit sig_SendDataFromDB();
    }

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

 void DataBase::table_clear(QTableView *tw)
 {
    all_tab->clear();
    all_tab->select();
    tw->setModel(all_tab);
    tw->show();
}
