#ifndef ADDNEWCLASSESINFO_H
#define ADDNEWCLASSESINFO_H

#include <QWidget>
#include "classinformation.h"

namespace Ui {
class addnewclassesinfo;
}

class addnewclassesinfo : public QWidget
{
    Q_OBJECT

public:
    explicit addnewclassesinfo(QWidget *parent = nullptr);
    ~addnewclassesinfo();

private slots:
    void on_Insertbutton_clicked();

private:
    Ui::addnewclassesinfo *ui;
};

#endif // ADDNEWCLASSESINFO_H
