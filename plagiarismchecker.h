#ifndef PLAGIARISMCHECKER_H
#define PLAGIARISMCHECKER_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include "mainwindow.h"


class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TestModel(QObject *parent = 0);

    void populateData(const QList<QString> &contactName,const QList<QString> &contactPhone);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_contact_name;
    QList<QString> tm_contact_phone;

    QList<QString> document_name;
    QList<QString> similarity_percent;

};

namespace Ui {
class Plagiarismchecker;
}

class Plagiarismchecker : public QMainWindow
{
    Q_OBJECT

public:
    explicit Plagiarismchecker(QWidget *parent = nullptr);
    ~Plagiarismchecker();

private slots:
    void on_pushDir_clicked();

    void on_backtomain_clicked();

private:
    Ui::Plagiarismchecker *ui;

private:
    QList<QString> document_name;
    QList<QString> similarity_percent;
};

#endif // PLAGIARISMCHECKER_H
