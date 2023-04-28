#include "addnewclassesinfo.h"
#include "ui_addnewclassesinfo.h"
#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>

addnewclassesinfo::addnewclassesinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addnewclassesinfo)
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

}

addnewclassesinfo::~addnewclassesinfo()
{
    delete ui;
}

void addnewclassesinfo::on_Insertbutton_clicked()
{


    QString classname=ui->Classtextedit->toPlainText();
    QString cnumber=ui->Numbetextedit->toPlainText();
    QString clocation=ui->locationtextedit->toPlainText();
    QString ctime=ui->timingtextedit->toPlainText();
    QString cnostudents=ui->studentsno->toPlainText();

    qDebug() << "CLass Namme:" << classname;
    qDebug() << "cnumber:" << cnumber;
    qDebug() << "clocation:" << clocation;
    qDebug() << "ctime:" << ctime;
    qDebug() << "cnostudents:" << cnostudents;

    QSqlQuery query;

    //INSERT INTO `classesinfo`(`sno`, `Name`, `Number`, `Location`, `Time`, `listofstudents`, `dtime`) VALUES ('[value-1]','[value-2]','[value-3]','[value-4]','[value-5]','[value-6]','[value-7]')
    query.exec("INSERT INTO `classesinfo`(`Name`, `Number`, `Location`, `Time`, `listofstudents`) VALUES ('"+classname+"','"+cnumber+"','"+clocation+"','"+ctime+"','"+cnostudents+"')");

    ClassInformation *classinfo= new ClassInformation();
    classinfo->show();
    this->close();

}

