#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include "questiondialog.h"

namespace Ui {
class QuestionWidget;
}

class QuestionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionWidget(QWidget *parent = 0);
    ~QuestionWidget();
protected slots:
    void on_pushButton_clicked();

private:
    Ui::QuestionWidget *ui;
    //questionDialog *questDialog;
};

#endif // QUESTIONWIDGET_H
