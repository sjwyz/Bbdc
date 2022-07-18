#include "sqlitetool.h"

sqlitetool::sqlitetool()
{
    insertcmd.clear();
    QFile filedb(DBNAME);
    if(filedb.exists())
    {
        dbexist = true;
        sqlite3_open(DBNAME,&db);
    }
    else
    {
        dbexist = false;
        craetedb();
    }
}

sqlitetool::~sqlitetool()
{
    sqlite3_close(db);
}

bool sqlitetool::isdbexist()
{
    return dbexist;
}

void sqlitetool::updatedbexist()
{
    dbexist = true;
}

int sqlitetool::craetedb()
{
    int iRet = 0;
    sqlite3_open(DBNAME,&db);
    sqlite3_exec(db, CREATE_SQL, NULL, 0, &zErrMsg);
    return iRet;
}

int sqlitetool::updatedb()
{
    int iRet = 0;

    return iRet;
}

int sqlitetool::selectdb()
{
    int iRet = 0;

    return iRet;
}

int sqlitetool::pushinsertcmd(char *data)
{
    int iRet = 0;
    char sql[1024];
    sprintf(sql,INSERT_SQL,data);
    insertcmd.append(sql);
    return iRet;
}

int sqlitetool::insertexec()
{
    int iRet = 0;
    //qDebug()<<insertcmd;
    sqlite3_exec(db, insertcmd.data(), NULL, 0, &zErrMsg);
    insertcmd.clear();
    return iRet;
}
