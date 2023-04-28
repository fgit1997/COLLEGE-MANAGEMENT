#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QMainWindow>

#include <QtSql/QSqlError>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QDateTime>
#include "mainwindow.h"
#include "addnewstudent.h"

namespace Ui {
class Studentinfo;
}

class Studentinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Studentinfo(QWidget *parent = nullptr);
    ~Studentinfo();

private slots:
    void on_addstudentbtn_clicked();

    void on_deletebtn_clicked();

    void on_mainmenubtn_clicked();

    void updatestudentdetails();
    void on_higestscorebtn_clicked();

    void on_lowestscorebutton_clicked();

    void on_averagebtn_clicked();

private:
    Ui::Studentinfo *ui;
    QSqlTableModel *tableModel;
};

#endif // STUDENTINFO_H
