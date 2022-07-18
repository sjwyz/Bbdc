#ifndef SQLITETOOL_H
#define SQLITETOOL_H

#include "qfile.h"
#include "qstring.h"
#include "qbytearray.h"
#include "QDebug"

#include "sqlite3.h"

#define DBNAME "eg.db"
#define CREATE_SQL "CREATE TABLE EG(\
ID INTEGER PRIMARY KEY AUTOINCREMENT,\
BUF CHAR(256) NOT NULL,\
SHENGSHU INT DEFAULT 0,\
COUNT INT DEFAULT 0\
);"

#define INSERT_SQL "INSERT INTO \
EG(BUF) \
VALUES(\"%s\")\
;"

#define SELECT_SQL "SELECT ID,BUF,SHENGSHU,COUNT FROM EG;"

class sqlitetool
{
private:
    sqlite3 *db;
    bool dbexist;
    char *zErrMsg;
    QByteArray insertcmd;

public:
    sqlitetool();
    ~sqlitetool();
    bool isdbexist();
    void updatedbexist();
    int craetedb();
    int pushinsertcmd(char *sql);
    int insertexec();
    int selectdb();
    int updatedb();

};

#endif // SQLITETOOL_H
