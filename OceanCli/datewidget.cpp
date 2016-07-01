#include "datewidget.h"
#include "ui_datewidget.h"
#include <QDate>
#include <QString>

DateWidget::DateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateWidget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(500);
}

DateWidget::~DateWidget()
{
    delete ui;
    delete timer;
}

void DateWidget::update()
{
    static int flag = false;
    QDate curDate = QDate::currentDate();
    QString tmp = curDate.toString("M月dd日 dddd");
    ui->l_date->setText(tmp);
    if (flag) {
        QTime curTime = QTime::currentTime();
        tmp = curTime.toString("hh:mm");
        ui->l_time->setText(tmp);
        flag = false;
    } else {
        QTime curTime = QTime::currentTime();
        tmp = curTime.toString("hh mm");
        ui->l_time->setText(tmp);
        flag = true;
    }

}

void DateWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

