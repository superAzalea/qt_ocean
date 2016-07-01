#include "statisticdialog.h"
#include "ui_statisticdialog.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTableView>
#include "cylindermap.h"

statisticDialog::statisticDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statisticDialog)
{
    ui->setupUi(this);

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("answer");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("序号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("第一道题答案"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("第二道题答案"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("第三道题答案"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("第四道题答案"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("第五道题答案"));

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->label_2->setText(QString::number(model->rowCount()));
    ui->tableView->setModel(model);

    /*
    QSqlQuery query;
    QString tmp;
    int numRows;

    query.exec("SELECT * FROM answer");
    QSqlDatabase defaultDB = QSqlDatabase::database();
    if (defaultDB.driver()->hasFeature(QSqlDriver::QuerySize)) {
        numRows = query.size();
    } else {
        // this can be very slow
        query.last();
        numRows = query.at() + 1;
        query.exec("SELECT * FROM answer");
    }

    ui->tableWidget->setRowCount(numRows);
    ui->tableWidget->setColumnCount(query.record().count());
    ui->tableWidget->setHorizontalHeaderLabels(QStringList("序号")<< "第一道题答案" << "第二道题答案" << "第三道题答案" << "第四道题答案" << "第五道题答案");
    ui->label_2->setText(QString(QString::number(numRows)) += "份");

    int row = 0;
    while (query.next()) {
        int id = query.value(0).toInt();
        QTableWidgetItem *newItem = new QTableWidgetItem;
        newItem->setText(QString::number(id));
        ui->tableWidget->setItem(row, 0, newItem);

        int A1 = query.value(1).toInt();
        newItem = new QTableWidgetItem;
        newItem->setText(QString::number(A1));
        ui->tableWidget->setItem(row, 1, newItem);

        int A2 = query.value(2).toInt();
        newItem = new QTableWidgetItem;
        newItem->setText(QString::number(A2));
        ui->tableWidget->setItem(row, 2, newItem);

        int A3 = query.value(3).toInt();
        newItem = new QTableWidgetItem;
        newItem->setText(QString::number(A3));
        ui->tableWidget->setItem(row, 3, newItem);

        int A4 = query.value(4).toInt();
        newItem = new QTableWidgetItem;
        newItem->setText(QString::number(A4));
        ui->tableWidget->setItem(row, 4, newItem);

        int A5 = query.value(5).toInt();
        newItem = new QTableWidgetItem;
        newItem->setText(QString::number(A5));
        ui->tableWidget->setItem(row, 5, newItem);
        row++;
    }
    */

    /*
    query.exec("SELECT * FROM question");
    while (query.next()) {
        QString title = query.value(1).toString();
        QString opt1 = query.value(2).toString();
        QString opt2 = query.value(3).toString();
        QString opt3 = query.value(4).toString();
        QString opt4 = query.value(5).toString();
        QString opt5 = query.value(6).toString();

        tmp += QString("%1 %2 %3 %4 %5 %6\n").arg(title).arg(opt1).arg(opt2).arg(opt3).arg(opt4).arg(opt5);
    }
    */
}

statisticDialog::~statisticDialog()
{
    delete ui;
}

void statisticDialog::on_pushButton_8_clicked()
{
    this->close();
}

void statisticDialog::on_pushButton_2_clicked()
{
    CylinderMap *cylwidget = new CylinderMap(this);
    cylwidget->resize(600, 400);
    cylwidget->move(this->width()/4, this->height()/4);

    QSqlTableModel model;
    model.setTable("answer");
    model.select();

    int male = 0, female = 0;
    for (int i = 0; i < model.rowCount(); ++i) {
        if (1 == model.record(i).value("A1"))
        {
            male++;
        } else {
            female++;
        }
    }
    cylwidget->setPlotter(male, "男", female, "女");
    cylwidget->showFullScreen();
}
