#include "plagiarismchecker.h"
#include "ui_plagiarismchecker.h"
#include "QFileDialog"
#include "QString"
#include "QFile"
#include <QDebug>
#include <QDir>
#include <iostream>


Plagiarismchecker::Plagiarismchecker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Plagiarismchecker)
{
    ui->setupUi(this);
    ui->selecttext->clear();
}

Plagiarismchecker::~Plagiarismchecker()
{
    delete ui;
}

TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TestModel::populateData(const QList<QString> &documentName,const QList<QString> &similarityvalue)
{
    tm_contact_name.clear();
    tm_contact_name = documentName;
    tm_contact_phone.clear();
    tm_contact_phone = similarityvalue;
    return;
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_contact_name.length();
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_contact_name[index.row()];
    } else if (index.column() == 1) {
        return tm_contact_phone[index.row()];
    }
    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Document");
        } else if (section == 1) {
            return QString("Similarity(%)");
        }
    }
    return QVariant();
}

void Plagiarismchecker::on_pushDir_clicked()

{
    QString currentdirectory=QDir::currentPath();
    //qDebug() << "CURRENT DIRECTORY:" << currentdirectory;

  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),currentdirectory,tr("Images (*.txt *.doc *.docx)"));

    if (fileName.size() > 0)
        ui->pushDir->setText(fileName);
  // print(currentdirectory);
    qDebug() << "FILE NAME:" << fileName;

    QFile rfile(fileName);
       if (!rfile.open(QIODevice::ReadOnly | QIODevice::Text))
           return;
       QTextStream rin(&rfile);
       while (!rin.atEnd()) {
           QString alldata = rin.readAll();
           qDebug() << "FILED DATA:" <<alldata;
           ui->selecttext->setText(alldata);
       }



    QString filerun="python C:\\pythonplagrisim\\plagcheck.py "+ fileName;
    qDebug() << filerun;


      QByteArray ba = filerun.toLocal8Bit();
      const char *c_str2 = ba.data();
      qDebug() <<  c_str2;
      system(c_str2);


    QFile file("plagresult.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;
       QTextStream in(&file);
       while (!in.atEnd()) {
           QString line = in.readLine();
           qDebug() << line;
           QStringList data = line.split(":");

           qDebug() << "LIST DATA:" << data;

           document_name.append(data[0]);
           similarity_percent.append(data[1]);

            qDebug() << "document_name" << document_name;

             qDebug() << "similarity_percent:" << similarity_percent;

           //QStringList list1 = str.split('.');
           //It worked using List = String.Split(QRegularExpression("\\."))
       }

       TestModel *plagModel = new TestModel(this);
        plagModel->populateData(document_name,similarity_percent);
       ui->tableView->setModel(plagModel);
       ui->tableView->horizontalHeader()->setVisible(true);
        ui->tableView->show();

}


void Plagiarismchecker::on_backtomain_clicked()
{
    MainWindow *mainmenu= new MainWindow();
    mainmenu->show();
    this->close();
}

