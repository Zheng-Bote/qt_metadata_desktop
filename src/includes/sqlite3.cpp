#include "sqlite3.hpp"

int SQLite3::openDb(QString &pathToFile)
{
    return (openSQLiteDatabase(pathToFile));
}

int SQLite3::closeDb()
{
    return (closeDatabase());
}

int SQLite3::createTable()
{
    return 0;
}

int SQLite3::createTable(QString tableName)
{
    QString query = "CREATE TABLE IF NOT EXISTS ";
    query.append(tableName);
    query.append(" (Id INTEGER PRIMARY KEY, Attribute TEXT UNIQUE, Value TEXT, Description TEXT, "
                 "Active INTEGER NOT NULL DEFAULT TRUE, "
                 "UNIQUE(Attribute));");

    return executeQuery(query);
}

int SQLite3::deleteTable()
{
    return 0;
}

int SQLite3::insertData()
{
    QString query = "INSERT INTO MyTable(Name, Age) VALUES('Bote', 60);";
    return executeQuery(query);
}

int SQLite3::insertData(QString query)
{
    return executeQuery(query);
}

int SQLite3::selectData()
{
    QString query = "SELECT * FROM MyTable;";
    return executeQuery(query);
}

int SQLite3::selectDataWithField()
{
    QString query = "SELECT * FROM MyTable;";
    return executeQueryWithFields(query);
}

int SQLite3::updateData()
{
    return 0;
}

int SQLite3::deleteData()
{
    return 0;
}
