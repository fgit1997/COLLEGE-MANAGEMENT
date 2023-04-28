#include "classinformation.h"
#include "ui_classinformation.h"
#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>

//int rowtobedeleted;

ClassInformation::ClassInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassInformation)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("collegemanagement");
    db.setUserName("adminuser");
    db.setPassword("collegeadmin");
    if (!db.open())
    {
        qDebug() << "Database error occurred"<<db.lastError();
    }
    else
    {
        qDebug()<<"Database connected";
    }



          getdatabasedetails();
//        QTableView *view = new QTableView;
//        view->setModel(model);
//        view->show();


}

ClassInformation::~ClassInformation()
{
    delete ui;
}

void ClassInformation::getdatabasedetails()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT `Name`, `Number`, `Location`, `Time`, `listofstudents`FROM `classesinfo` WHERE 1");

    //model->setHeaderData(0, Qt::Horizontal, tr("Sno"));
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Number"));
    model->setHeaderData(2, Qt::Horizontal, tr("Location"));
    model->setHeaderData(3, Qt::Horizontal, tr("Timing"));
    model->setHeaderData(4, Qt::Horizontal, tr("Enrolled Students"));

   // ui->tableView->verticalHeader()->hide();
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void ClassInformation::on_deletebutton_clicked()
{    int row=0;
     int coloum=0;
    // int rowtobedeleted=0;
     QString cvalue;

    QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();

    //qDebug() << " CI:" << ui->tableView->selectionModel()->currentIndex();




    foreach (QModelIndex index, indexList) {
        row = index.row();
        coloum = index.column();
        cvalue= index.sibling(index.row(),index.column()).data().toString();
        qDebug() << row  << "," << coloum << cvalue;
    }

  //rowtobedeleted=row+1;
 //qDebug() << "ROW TO BE DELETED" <<  row;



QSqlQuery query;
//query.exec("UPDATE `classesinfo` SET `Number`=33 WHERE sno=2  ");
query.exec("DELETE FROM `classesinfo` WHERE `Name`='"+cvalue+"'");

getdatabasedetails();
}


void ClassInformation::on_addnewclassinfo_clicked()
{
    addnewclassesinfo *addclass= new addnewclassesinfo();
    addclass->show();
    this->close();
}


void ClassInformation::on_mainmenubutton_clicked()
{
    MainWindow *mainmenu= new MainWindow();
    mainmenu->show();
    this->close();
}

