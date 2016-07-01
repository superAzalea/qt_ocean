#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>


namespace Ui {
class WeatherWidget;
}

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = 0);
    ~WeatherWidget();

public slots:
    //void slotReadyRead();
    void replyFinished();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
    void updateWeather();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::WeatherWidget *ui;
    QNetworkReply *reply;
    QTimer *timer;
    QNetworkAccessManager *manager;
    QNetworkRequest *request;
};

#endif // WEATHERWIDGET_H
