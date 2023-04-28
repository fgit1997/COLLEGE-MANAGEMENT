#include "addnewstudent.h"
#include "ui_addnewstudent.h"
#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>

addnewstudent::addnewstudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addnewstudent)
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

addnewstudent::~addnewstudent()
{
    delete ui;
}

void addnewstudent::on_InsertButton_clicked()
{
    QString sname=ui->nametext->toPlainText();
    QString saddress=ui->addresstext->toPlainText();


    qDebug() << "Namme:" << sname;
    qDebug() << "Address:" << saddress;

    QSqlQuery query;

    //INSERT INTO `studentdata`(`studentname`, `address`) VALUES ('[value-1]','[value-2]','[value-3]','[value-4]','[value-5]','[value-6]','[value-7]')
    query.exec("INSERT INTO `studentdata`(`studentname`, `address`) VALUES ('"+sname+"','"+saddress+"')");

    Studentinfo *sinfo= new Studentinfo();
    sinfo->show();
    this->close();
}

