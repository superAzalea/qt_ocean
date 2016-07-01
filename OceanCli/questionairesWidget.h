#ifndef QUESTIONAIRESWIDGET_H
#define QUESTIONAIRESWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class questionairesWidget;
}

class questionairesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit questionairesWidget(QWidget *parent = 0);
    ~questionairesWidget();
    QTcpSocket *tcpSocket;

private slots:
    void on_b_submit_clicked();
    //void sendData();
    void displayError(QAbstractSocket::SocketError);


private:
    Ui::questionairesWidget *ui;
    QString data;    
};

#endif // QUESTIONAIRESWIDGET_H
