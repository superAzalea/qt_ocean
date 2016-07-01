#include "contactorwidget.h"
#include "ui_contactorwidget.h"

contactorWidget::contactorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactorWidget)
{
    ui->setupUi(this);
    setVisible(false);
}

contactorWidget::~contactorWidget()
{
    delete ui;
}

void hiden()
{

}

