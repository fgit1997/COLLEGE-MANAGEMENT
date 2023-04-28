#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H

#include <QWidget>
#include "studentinfo.h"

namespace Ui {
class addnewstudent;
}

class addnewstudent : public QWidget
{
    Q_OBJECT

public:
    explicit addnewstudent(QWidget *parent = nullptr);
    ~addnewstudent();

private slots:
    void on_InsertButton_clicked();

private:
    Ui::addnewstudent *ui;
};

#endif // ADDNEWSTUDENT_H
