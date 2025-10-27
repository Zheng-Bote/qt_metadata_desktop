#pragma once

#include "database.hpp"

class SQLite3 : public Database
{
public:
    int openDb(QString &pathToFile);

    int closeDb();

    int createTable() override;
    int createTable(QString tableName);
    int deleteTable() override;

    int insertData() override;
    int insertData(QString query);
    int selectData() override;
    int selectDataWithField() override;
    int updateData() override;
    int deleteData() override;
};
