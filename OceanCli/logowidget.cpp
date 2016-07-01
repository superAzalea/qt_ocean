#include "logowidget.h"
#include "ui_logowidget.h"
#include <QPainter>

LogoWidget::LogoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoWidget)
{
    ui->setupUi(this);
}

LogoWidget::~LogoWidget()
{
    delete ui;
}

void LogoWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
