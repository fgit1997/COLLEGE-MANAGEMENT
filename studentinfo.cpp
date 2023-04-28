#include "studentinfo.h"
#include "ui_studentinfo.h"
#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

Studentinfo::Studentinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Studentinfo)
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


    tableModel = new QSqlTableModel();
    tableModel->setTable("studentdata");
    tableModel->select();

    ui->tableView->setModel(tableModel);
    ui->tableView->hideColumn(0); // don't show the ID
    ui->tableView->show();

}

Studentinfo::~Studentinfo()
{
    delete ui;
}

void Studentinfo::on_addstudentbtn_clicked()
{

        addnewstudent *sadd= new addnewstudent();
        sadd->show();
        this->close();
}


void Studentinfo::on_deletebtn_clicked()
{
    int row=0;
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
    query.exec("DELETE FROM `studentdata` WHERE `studentname`='"+cvalue+"'");

    updatestudentdetails();
}


void Studentinfo::on_mainmenubtn_clicked()
{
    MainWindow *mainmenu= new MainWindow();
    mainmenu->show();
    this->close();
}

void Studentinfo::updatestudentdetails()
{
    tableModel = new QSqlTableModel();
    tableModel->setTable("studentdata");
    tableModel->select();

    ui->tableView->setModel(tableModel);
    ui->tableView->hideColumn(0); // don't show the ID
    ui->tableView->show();
}


void Studentinfo::on_higestscorebtn_clicked()
{


    QString nameofstudent;
    QString totalscorevalue;

    QSqlQuery query;
    query.exec("SELECT `studentname`, `totalscore` FROM `studentdata` WHERE `totalscore` = (SELECT MAX(`totalscore`)FROM `studentdata`)");

        if (!query.isActive())
            QMessageBox::warning(this, tr("Database Error"),query.lastError().text());

        while(query.next())
        {
            nameofstudent=query.value(0).toString();
            totalscorevalue=query.value(1).toString();
//            qDebug() << "Student Name: " << query.value(0).toString()
//                     <<"Total Score:  "<<query.value(1).toString();
        }

       QMessageBox msgBox;
       msgBox.setText("Student Name: " +nameofstudent+" has Secured Highest Total Score of " + totalscorevalue);
       msgBox.exec();

}


void Studentinfo::on_lowestscorebutton_clicked()
{
    QString nameofstudent;
    QString totalscorevalue;

    QSqlQuery query;
    query.exec("SELECT `studentname`, `totalscore` FROM `studentdata` WHERE `totalscore` = (SELECT MIN(`totalscore`)FROM `studentdata`)");

        if (!query.isActive())
            QMessageBox::warning(this, tr("Database Error"),query.lastError().text());

        while(query.next())
        {
            nameofstudent=query.value(0).toString();
            totalscorevalue=query.value(1).toString();
//            qDebug() << "Student Name: " << query.value(0).toString()
//                     <<"Total Score:  "<<query.value(1).toString();
        }

       QMessageBox msgBox;
       msgBox.setText("Student Name: " +nameofstudent+" has Lowest Total Score of " + totalscorevalue);
       msgBox.exec();
}


void Studentinfo::on_averagebtn_clicked()
{
    QString averagescore;
    QSqlQuery query;
    query.exec("SELECT AVG(`totalscore`) FROM `studentdata`");

    if (!query.isActive())
        QMessageBox::warning(this, tr("Database Error"),query.lastError().text());

    while(query.next())
    {
        averagescore=query.value(0).toString();
         //totalscorevalue=query.value(1).toString();
         //  qDebug() << "avg: " << query.value(0).toString();
    }
    QMessageBox msgBox;
    msgBox.setText("Average Score:" +averagescore);
    msgBox.exec();
}

