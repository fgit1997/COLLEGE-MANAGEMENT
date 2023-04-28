#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_classesinfobutton_clicked()
{
    qDebug() << " CLASS INFORMAION BUTTON CLICKED";

    ClassInformation *cinfo = new  ClassInformation();
    cinfo->show();
    this->close();

}


void MainWindow::on_plagcheckerbutton_clicked()
{
Plagiarismchecker *plagcheck= new Plagiarismchecker();
plagcheck->show();
this->close();

}


void MainWindow::on_studnetInfo_clicked()
{

    Studentinfo *studentui= new Studentinfo();
    studentui->show();
    this->close();
}

