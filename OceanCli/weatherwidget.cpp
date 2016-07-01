#include "weatherwidget.h"
#include "ui_weatherwidget.h"
#include <QDebug>
#include <QPainter>
#include <QStringList>
#include <QString>


WeatherWidget::WeatherWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWidget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    //High Level Network Operations for HTTP and FTP
    request = new QNetworkRequest;
 //  request->setUrl(QUrl("file:///home/ShanghaiWeather.xml"));
    //从网页上获取天气信息
    request->setUrl(QUrl("http://www.webxml.com.cn/WebServices/WeatherWebService.asmx/getWeatherbyCityName?theCityName=58367"));

    reply = manager->get(*request);

   // connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(replyFinished()));

    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWeather()));
    timer->start(1000*60*30);
}

void WeatherWidget::updateWeather()
{
    static int count = 0;
    count++;
    qDebug() << "updateWeather:" << count;
    reply = manager->get(*request);
}
WeatherWidget::~WeatherWidget()
{
    delete ui;
    delete request;
    delete manager;
    delete timer;
}


void WeatherWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void WeatherWidget::replyFinished()
{
    static int cnt = 0;
    cnt++;
    qDebug() << "updateWeather:" << cnt;

    QString tmpstr=reply->readAll();
    qDebug() << tmpstr;
    QDomDocument doc("mydocument");
    if (!doc.setContent(tmpstr)) {
        return;
    }

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    QStringList tmpstrlist;
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            tmpstrlist<<e.text();
            qDebug()<<e.text(); // the node really is an element.
        }
        n = n.nextSibling();
    }
    QStringList tmpstrlist2=tmpstrlist[6].split(" ");
    if(tmpstrlist2.count()>1)
        ui->label->setText(tmpstrlist2[1]);
    //根据获取到的天气信息，从本地查找图片
    //ui->label->setPixmap(QPixmap("/home/du/images/cloudy_night000.png"));
    ui->label->setPixmap(QPixmap("/Users/davis/Downloads/images/cloudy_night000.png"));

    tmpstrlist2=tmpstrlist[10].split("：");
    if(tmpstrlist2.count()>6)
    {
        tmpstrlist2=tmpstrlist2[2].split("；");
        if(tmpstrlist2.count()>1)
            ui->label_2->setText(tmpstrlist2[0]);
    }
}

void WeatherWidget::slotError(QNetworkReply::NetworkError)
{
   qDebug() << "network error";

}

void WeatherWidget::slotSslErrors(QList<QSslError>)
{
    qDebug() << "ssl error";
}


