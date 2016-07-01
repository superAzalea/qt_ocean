#include "infowidget.h"
#include "ui_infowidget.h"


InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    flags = true;
    timeout = new QTimer;
    ui->widget->hide();
    connect(timeout, SIGNAL(timeout()), this, SLOT(reset()));
}

InfoWidget::~InfoWidget()
{
    delete ui;
    delete timeout;
}


void InfoWidget::on_pushButton_clicked()
{
    if (flags) {
        ui->widget->show();
        flags = false;
        timeout->start(10000);
    } else {
        ui->widget->hide();
        flags = true;
    }
}

void InfoWidget::reset()
{
    if (!flags) {
        ui->widget->hide();
        flags = true;
        timeout->stop();
    }
}
