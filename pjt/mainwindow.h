#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstringlistmodel.h"
#include "qabstractitemview.h"
#include "qbytearray.h"
#include "qstring.h"
#include "qfile.h"

#include "sqlitetool.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sheng2shu_clicked();
    void on_sheng_clicked(const QModelIndex &index);
    void on_shu2sheng_clicked();
    void on_shu_clicked(const QModelIndex &index);
    void on_search_textChanged(const QString &arg1);
    void on_clear_clicked();

private:
    void make_sl();
    void make_xl();

private:
    Ui::MainWindow *ui;
    sqlitetool *sqlitedb;

    QStringList *sl_base;
    QStringList *sl;
    QStringListModel *slm;

    QStringList *xl_base;
    QStringList *xl;
    QStringListModel *xlm;

};
#endif // MAINWINDOW_H
