#include "widget.h"
#include "ui_widget.h"
#include <QSqlError>
#include "statisticdialog.h"
#include "quesmdialog.h"
#include <QMessageBox>
#include <QTcpSocket>
#include <QSqlTableModel>
#include <QTableView>
#include <QString>
#include <QStringList>
#include <QSqlRecord>

QTcpSocket *tcpSocket;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ocean.db");
    bool ok = db.open();
    if (!ok) {
        db.lastError();
    }

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if (!tcpServer->listen( QHostAddress::Any,43211)) {
        QMessageBox::critical(this, tr("Ocean Server"),
              tr("Unable to start the server: %1.").arg(tcpServer->errorString()));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnection()
{
    qDebug() << "incoming new connection/";

    tcpSocket = tcpServer->nextPendingConnection();

    qDebug() << "connection has been established.";

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));    //wait for reading
}

void Widget::readData()
{
    QByteArray tmp;
    tmp = tcpSocket->readAll();
    QString str = QString::fromLatin1(tmp);
    //qDebug() << str;

    str.remove("$$$");
    str.remove("^^^");
    if (str.mid(0,1) == "1") {
        QSqlTableModel model;
        model.setTable("answer");
        model.insertRows(0,1);
        str.remove(0,1);
        QStringList strlist = str.split(";");
        for (int i = 0; i < strlist.count(); ++i) {
            model.setData(model.index(0, i+1), strlist[i]);
        }
        model.submitAll();
    } else if (str.mid(0,1) == "2") {
        QSqlTableModel model;
        model.setTable("question");
        model.select();

        QString tmp;
        //qDebug() << model.rowCount();
        for (int i = 0; i < model.rowCount(); ++i) {
            tmp += model.record(i).value("title").toString();
            tmp += "!";
            tmp += model.record(i).value("opt1").toString();
            tmp += ";";
            tmp += model.record(i).value("opt2").toString();
            tmp += ";";
            tmp += model.record(i).value("opt3").toString();
            tmp += ";";
            tmp += model.record(i).value("opt4").toString();
            tmp += ";";
            tmp += model.record(i).value("opt5").toString();
            tmp += "\n";
        }
        //qDebug() << tmp;
        tcpSocket->write(tmp.toLocal8Bit());
        tcpSocket->waitForBytesWritten(30000);
        tcpSocket->disconnect();

    }

    tcpSocket->close();
}

void Widget::on_pushButton_2_clicked()
{
    statisticDialog dg(this);
    dg.move(this->width()/2, this->height()/2);
    dg.setWindowFlags(Qt::Window);
    dg.showFullScreen();
    dg.show();
    dg.exec();

}

void Widget::on_pushButton_4_clicked()
{
    //this->hide();
    close();
}

void Widget::on_pushButton_clicked()
{
    QuesMDialog qdlg(this);
    qdlg.move(this->width()/2, this->height()/2);
    qdlg.setWindowFlags(Qt::Window);
    qdlg.showFullScreen();
    qdlg.exec();
}
