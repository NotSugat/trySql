#include "database.h"


Database::Database(QObject *parent)
{

}

Database::~Database()
{

}

void Database::connectToDataBase()
{
    if(!QFile("/home/crux/coding/sqlite/" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool Database::restoreDataBase()
{
    if(this->openDataBase()){
        return (this->createTable()) ? true : false;
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

bool Database::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("/home/crux/coding/sqlite/" DATABASE_NAME);
    if(db.open()){
        qDebug() << "connected to db";
        return true;
    } else {
        qDebug() << "not connected";
        return false;
    }
}

bool Database::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_EMAIL     " VARCHAR(255)    NOT NULL,"
                            TABLE_PASSWORD     " VARCHAR(255)    NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;

    } else {
        return true;
    }
    return false;
}

void Database::closeDataBase()
{
    db.close();
}

bool Database::insertIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_EMAIL ", "
                                             TABLE_PASSWORD
                                             " ) "
                  "VALUES (:Email, :Password)");
    query.bindValue(":Email",       data[0].toString());
    query.bindValue(":Password",       data[1].toString());


    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool Database::insertIntoTable(const QString &email, const QString &password)
{
    QVariantList data;
    data.append(email);
    data.append(password);

    if(insertIntoTable(data))
        return true;
    else
        return false;
}


bool Database::validation(const QString &email, const QString &password)
{
    QSqlQuery query(QSqlDatabase::database(DATABASE_NAME));
    query.prepare(QString("SELECT * FROM authTable WHERE Email = :Email AND Password = :Password "));

    query.bindValue(":Email", email);
    query.bindValue(":Password", password);

    if(!query.exec()) {
        qDebug() << "failed to execute";
    } else {
        while (query.next()) {
            QString emailFromDb = query.value(1).toString();
            QString passwordFromDb = query.value(2).toString();

            if(email == emailFromDb  && password == passwordFromDb) {
                qDebug() << "success";
                return true;
            } else {
                qDebug() << "failed";
                return false;
            }

        }
    }
    return false;

}
