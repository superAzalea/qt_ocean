#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class questionDialog;
}

class questionDialog : public QDialog
{
    Q_OBJECT
public:
    QTcpSocket *tcpSocket;
    QStringList datalist;
    int num;

public:
    explicit questionDialog(QWidget *parent = 0);
    ~questionDialog();
    void setInitial(QString &);
private slots:
    //void sendData();
    void displayError(QAbstractSocket::SocketError);
    void optionChecked();


private:
    Ui::questionDialog *ui;
};

#endif // QUESTIONDIALOG_H
