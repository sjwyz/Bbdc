#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sl=new QStringList();
    sl_base=new QStringList();
    slm=new QStringListModel(this);
    xl=new QStringList();
    xlm=new QStringListModel(this);
    xl_base=new QStringList();
    QFile file("eg.csv");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd())
    {
        QByteArray arr=file.readLine();
        int arrlen=arr.size();
        if(arr[arrlen-1]=='\n')
            arr[arrlen-1]='\0';
        /*int i=0;
        while(i<arrlen)
        {
            if(arr[i]==',')
                arr[i]='\n';
            i++;
        }*/
        *sl<<arr.data();
    }
    *sl_base=*sl;
    *xl_base=*xl;
    slm->setStringList(*sl);
    xlm->setStringList(*xl);
    ui->search->clear();
    ui->sheng->setModel(slm);
    ui->shu->setModel(xlm);
    ui->sheng->setEditTriggers(QAbstractItemView::NoEditTriggers/*|QAbstractItemView::SelectedClicked*/);
    ui->shu->setEditTriggers(QAbstractItemView::NoEditTriggers/*|QAbstractItemView::SelectedClicked*/);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sl;
    delete xl;
    delete slm;
    delete xlm;
    delete sl_base;
    delete xl_base;
}

void MainWindow::make_sl()
{
    sl_base->sort();
    *sl = sl_base->filter(ui->search->text());
    slm->setStringList(*sl);
}

void MainWindow::make_xl()
{
    xl_base->sort();
    *xl = xl_base->filter(ui->search->text());
    xlm->setStringList(*xl);
}

void MainWindow::on_sheng2shu_clicked()
{
    if(ui->sheng->selectionModel()->selectedIndexes().count()!=1)
    {
        return;
    }
    auto ap=ui->sheng->selectionModel()->selectedIndexes()[0];
    *xl_base<<ap.data().toString();
    int ibasecount = sl_base->count();
    int ii=0;
    while(ii<ibasecount)
    {
        if(sl_base->at(ii)==ap.data())
        {
            sl_base->removeAt(ii);
            break;
        }
        ii++;
    }
    make_sl();
    make_xl();
}

void MainWindow::on_shu2sheng_clicked()
{
    if(ui->shu->selectionModel()->selectedIndexes().count()!=1)
    {
        return;
    }
    auto ap=ui->shu->selectionModel()->selectedIndexes()[0];
    *sl_base<<ap.data().toString();
    int ibasecount = xl_base->count();
    int ii=0;
    while(ii<ibasecount)
    {
        if(xl_base->at(ii)==ap.data())
        {
            xl_base->removeAt(ii);
            break;
        }
        ii++;
    }
    make_xl();
    make_sl();
}

void MainWindow::on_sheng_clicked(const QModelIndex &index)
{
}

void MainWindow::on_shu_clicked(const QModelIndex &index)
{
}

void MainWindow::on_search_textChanged(const QString &arg1)
{
    make_sl();
    make_xl();
}

void MainWindow::on_clear_clicked()
{
    ui->search->clear();
}

