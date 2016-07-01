#include "showwidget.h"
#include "ui_showwidget.h"
#include <QPainter>
#include "videowidget.h"

videoWidget *video_widget;

ShowWidget::ShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidget)
{
    ui->setupUi(this);
    video_widget = new videoWidget;
}

ShowWidget::~ShowWidget()
{
    delete ui;
}

void ShowWidget::paintEvent(QPaintEvent *)
{
    QStyleOption op;
    op.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &op, &p, this);
}

void ShowWidget::on_pushButton_clicked()
{
    video_widget->showFullScreen();
    //video_widget->play("/home/du/movies/上海海洋水族馆随拍.flv");
    video_widget->play("/Users/davis/Downloads/movies/上海海洋水族馆随拍.flv");


}
