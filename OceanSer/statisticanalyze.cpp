#include "statisticanalyze.h"
#include "ui_statisticanalyze.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

statisticAnalyze::statisticAnalyze(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statisticAnalyze)
{
    ui->setupUi(this);


    QSqlQuery query;
    QString tmp;
    query.exec("SELECT * FROM question");
    while (query.next()) {
        QString title = query.value(1).toString();
        QString opt1 = query.value(2).toString();
        QString opt2 = query.value(3).toString();
        QString opt3 = query.value(4).toString();
        QString opt4 = query.value(5).toString();
        QString opt5 = query.value(6).toString();

        tmp += QString("%1 %2 %3 %4 %5 %6\n").arg(title).arg(opt1).arg(opt2).arg(opt3).arg(opt4).arg(opt5);
        //qDebug() << id << title << opt1;
        ui->plainTextEdit->setPlainText(tmp);
    }
}

statisticAnalyze::~statisticAnalyze()
{
    delete ui;
}

void statisticAnalyze::on_pushButton_8_clicked()
{
    this->close();
}
