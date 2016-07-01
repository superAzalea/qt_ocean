#include "quesmdialog.h"
#include "ui_quesmdialog.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>

QSqlTableModel *model;
QString data;

QuesMDialog::QuesMDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuesMDialog)
{
    ui->setupUi(this);

    model = new QSqlTableModel;
    model->setTable("question");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("序号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("题目"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("选项1"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("选项2"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("选项3"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("选项4"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("选项5"));


    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();


}

QuesMDialog::~QuesMDialog()
{
    delete ui;
}

void QuesMDialog::on_pushButton_2_clicked()
{
    QString *title;
    if (ui->le_title->isModified()) {
        title = new QString;
        *title = ui->le_title->displayText();
    } else {
        return;
    }
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), row+1);
    model->setData(model->index(row, 1), *title);
    //model->setData(model->index(row, 2), "满意");
    //model->setData(model->index(row, 3), "不满意");
    model->submitAll();
}




void QuesMDialog::on_pushButton_3_clicked()
{
    close();
}
