#ifndef CLASSINFORMATION_H
#define CLASSINFORMATION_H

#include <QMainWindow>
#include "addnewclassesinfo.h"
#include "mainwindow.h"

namespace Ui {
class ClassInformation;
}

class ClassInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClassInformation(QWidget *parent = nullptr);
    ~ClassInformation();

    void getdatabasedetails();

private slots:
    void on_deletebutton_clicked();

    void on_addnewclassinfo_clicked();

    void on_mainmenubutton_clicked();

private:
    Ui::ClassInformation *ui;
};

#endif // CLASSINFORMATION_H
