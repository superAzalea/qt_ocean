#include "questionwidget.h"
#include "ui_questionwidget.h"

QuestionWidget::QuestionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionWidget)
{
    ui->setupUi(this);
    //questDialog = new questionDialog(this);
}

QuestionWidget::~QuestionWidget()
{
    delete ui;
}

void QuestionWidget::on_pushButton_clicked()
{
    questionDialog *questDialog = new questionDialog(this);

    QString request = QString("$$$2") + "^^^";
    //qDebug() << request;
    questDialog->tcpSocket->connectToHost("127.0.0.1", 43211);
    if (!questDialog->tcpSocket->waitForConnected(30000)) {
        return;
    }

    questDialog->tcpSocket->write(request.toLocal8Bit());
    questDialog->tcpSocket->waitForReadyRead(3000);

    QString tmp = questDialog->tcpSocket->readAll();
    qDebug() << tmp;
    questDialog->datalist = tmp.split("\n");
    questDialog->num = questDialog->datalist.count();

    questDialog->tcpSocket->abort();
    questDialog->setInitial(questDialog->datalist[0]);
    questDialog->num--;
    //questDialog->showFullScreen();
    questDialog->show();

}

