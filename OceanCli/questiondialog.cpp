#include "questiondialog.h"
#include "ui_questiondialog.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

QString sendMessage("$$$1");

questionDialog::questionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questionDialog)
{
    ui->setupUi(this);
    ui->opt1->hide();
    ui->opt2->hide();
    ui->opt3->hide();
    ui->opt4->hide();
    ui->opt5->hide();

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT(displayError(QAbstractSocket::SocketError)));

    QList<QRadioButton *> allPButtons =
            this->findChildren<QRadioButton *>();

    for (int i = 0; i < allPButtons.count(); ++i) {
        QObject::connect(allPButtons[i], SIGNAL(clicked()), this,
                             SLOT(optionChecked()));
    }
}

questionDialog::~questionDialog()
{
    delete ui;
}

void questionDialog::setInitial(QString &str)
{
    qDebug() << str;
    ui->l_count->setText(QString::number(num-2));

    QStringList tmplist = str.split("!");
    ui->title->setText(tmplist[0]);
    QString tmpstr = tmplist[1];
    tmplist = tmpstr.split(";");
    for (int i = 0; i <tmplist.count(); ++i) {
        if (i == 0) {
            if (tmplist[i] == "") continue;
            ui->opt1->setText(tmplist[i]);
            ui->opt1->show();
        } else if (i == 1) {
            if (tmplist[i] == "") continue;
            ui->opt2->setText(tmplist[i]);
            ui->opt2->show();
        } else if (i == 2) {
            if (tmplist[i] == "") continue;
            ui->opt3->setText(tmplist[i]);
            ui->opt3->show();
        } else if (i == 3) {
            if (tmplist[i] == "") continue;
            ui->opt4->setText(tmplist[i]);
            ui->opt4->show();
        } else if (i == 4) {
            if (tmplist[i] == "") continue;
            ui->opt5->setText(tmplist[i]);
            ui->opt5->show();
        }
    }
}

void questionDialog::optionChecked()
{
    QList<QRadioButton *> allRadioButton = this->findChildren<QRadioButton *>();
    for (int i = 0; i < allRadioButton.count(); ++i) {
        if (allRadioButton[i]->isChecked()) {
           QString tmpstr = allRadioButton[i]->objectName();
           tmpstr = tmpstr.remove(0,3);
           sendMessage += tmpstr;
           sendMessage += ";";
        }
    }
    //qDebug() << sendMessage;
    static int cnt = 1;
    if (num > 1) {
        setInitial(datalist[cnt++]);
        num--;
        ui->l_count->setText(QString::number(num-1));
    } else {
        sendMessage += "^^^";

        tcpSocket->connectToHost("127.0.0.1", 43211);
        tcpSocket->waitForConnected(30000);

        //qDebug() << "this is sendData";
        QByteArray temp;
        temp = sendMessage.toUtf8();
        //qDebug() << temp;
        int num1;
        if ((num1 = tcpSocket->write(temp)) == -1) {
            QMessageBox::critical(this,  tr("write error"),
                                  tr("when write to device, an error occured"));
        }
        tcpSocket->waitForReadyRead(30000);
        //qDebug() << "total bytes writen to devie is " << num;
        sendMessage.clear();
        datalist.clear();
        num = 0;
        cnt = 1;
        tcpSocket->abort();
        this->close();
    }
}


void questionDialog::displayError(QAbstractSocket::SocketError socketError)
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
}


