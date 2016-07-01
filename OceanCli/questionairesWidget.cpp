#include "questionairesWidget.h"
#include "ui_questionairesWidget.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>


questionairesWidget::questionairesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionairesWidget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT(displayError(QAbstractSocket::SocketError)));
}

questionairesWidget::~questionairesWidget()
{
    delete ui;
    delete tcpSocket;
}

void questionairesWidget::on_b_submit_clicked()
{
    //connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendData()));

    ui->b_submit->setEnabled(false);
    data += "$$$1";

    QList<QRadioButton *> allRadioButton = this->findChildren<QRadioButton *>();
    int count = 0;
    for (int i = 0; i < allRadioButton.count(); ++i) {
        if (allRadioButton[i]->isChecked()) {
           count++;
           QString tmpstr = allRadioButton[i]->objectName();
           tmpstr = tmpstr.remove(0,3);
           data += tmpstr;
           data += ";";
        }
    }
    data += "^^^";

    if (count != 3) {
        QMessageBox::critical(this, tr("Blank"),
                              tr("at lest one item left.Please check you choice."));
        data.clear();
        ui->b_submit->setEnabled(true);
        return;
    }

    qDebug() << data;
    //tcpSocket->abort();

    tcpSocket->connectToHost("127.0.0.1", 43211);
    tcpSocket->waitForConnected(30000);

    //qDebug() << "this is sendData";
    QByteArray temp;
    temp = data.toUtf8();
    //qDebug() << temp;
    int num;
    if ((num = tcpSocket->write(temp)) == -1) {
        QMessageBox::critical(this,  tr("write error"),
                              tr("when write to device, an error occured"));
    }
    tcpSocket->waitForReadyRead(30000);
    //qDebug() << "total bytes writen to devie is " << num;
    data.clear();
    ui->b_submit->setEnabled(true);
    tcpSocket->abort();
    this->close();
    //tcpSocket->disconnect();
    //tcpSocket->waitForDisconnected(30000);
}
/*
void questionairesWidget::sendData()
{
    qDebug() << "this is sendData";
    QByteArray temp;
    temp = data.toUtf8();
    //qDebug() << temp;
    int num;
    if ((num = tcpSocket->write(temp)) == -1) {
        QMessageBox::critical(this,  tr("write error"),
                              tr("when write to device, an error occured"));
    }
    tcpSocket->waitForReadyRead(30000);
    //qDebug() << "total bytes writen to devie is " << num;
    data.clear();
    ui->b_submit->setEnabled(true);
    tcpSocket->abort();
    //tcpSocket->disconnect();
    //tcpSocket->waitForDisconnected(30000);

    this->close();
}

*/
void questionairesWidget::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Ocean Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Ocean Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the Ocean server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Ocean Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }
    ui->b_submit->setEnabled(true);
}
