#include "cylindermap.h"
#include <QPainter>
#include <QPaintEngine>
#include <QDebug>
#include <QRect>

CylinderMap::CylinderMap(QDialog *parent) :
    QDialog(parent),
    m_cylinder1(0), m_cylinder2(0), m_cylinder3(0), m_cylinder4(0),
    m_cylinder5(0),m_amount(0), m_mode(0)
{
}

void CylinderMap::setMode(int mode)
{
    m_mode = mode;
}

void CylinderMap::setPlotter(int cylinder1, QString header1, int cylinder2, QString header2)
{
    m_cylinder1 = cylinder1;
    m_cylinder2 = cylinder2;
    m_header1 = header1;
    m_header2 = header2;
    m_amount = 2;

    update();
}
void CylinderMap::setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                 int cylinder3, QString header3)
{
    m_cylinder1 = cylinder1;
    m_cylinder2 = cylinder2;
    m_cylinder3 = cylinder3;

    m_header1 = header1;
    m_header2 = header2;
    m_header3 = header3;

    m_amount = 3;

    update();
}

void CylinderMap::setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                 int cylinder3, QString header3, int cylinder4, QString header4)
{
    m_cylinder1 = cylinder1;
    m_cylinder2 = cylinder2;
    m_cylinder3 = cylinder3;
    m_cylinder4 = cylinder4;

    m_header1 = header1;
    m_header2 = header2;
    m_header3 = header3;
    m_header4 = header4;

    m_amount = 4;

    update();
}

void CylinderMap::setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                 int cylinder3, QString header3, int cylinder4, QString header4,
                 int cylinder5, QString header5)
{
    m_cylinder1 = cylinder1;
    m_cylinder2 = cylinder2;
    m_cylinder3 = cylinder3;
    m_cylinder4 = cylinder4;
    m_cylinder5 = cylinder5;

    m_header1 = header1;
    m_header2 = header2;
    m_header3 = header3;
    m_header4 = header4;
    m_header5 = header5;

    m_amount = 5;

    update();
}

void CylinderMap::paintEvent(QPaintEvent *)
{
    int tmpWidth = width();
    int tmpHeight = height() * 80/100;


    switch (m_mode) {
    case 0:
        if (2 == m_amount) {
            tmpWidth = tmpWidth / 5;
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);

            painter.setPen(Qt::SolidLine);
            painter.setPen(Qt::black);

            painter.save();
            painter.setPen(Qt::NoPen);
            painter.setBrush(Qt::blue);
            painter.drawRect(tmpWidth, height()*0.9-tmpHeight*m_cylinder1/(m_cylinder1+m_cylinder2),
                             tmpWidth, tmpHeight*m_cylinder1/(m_cylinder1+m_cylinder2));
            painter.setBrush(Qt::red);
            painter.drawRect(3*tmpWidth, height()*0.9-tmpHeight*m_cylinder2/(m_cylinder1+m_cylinder2),
                                    tmpWidth, tmpHeight*m_cylinder2/(m_cylinder1+m_cylinder2));
            painter.restore();
\
            painter.drawText(QRect(tmpWidth, height()*0.9, tmpWidth, height()*0.1),
                             Qt::AlignCenter, QString("%1%").arg(100*m_cylinder1/(m_cylinder1+m_cylinder2)));
            painter.drawText(QRect(3*tmpWidth, height()*0.9, tmpWidth, height()*0.1),
                             Qt::AlignCenter,  QString("%1%").arg(100*m_cylinder2/(m_cylinder1+m_cylinder2)));

            painter.drawText(QRect(tmpWidth, 0.8 * height()-tmpHeight*m_cylinder1/(m_cylinder1+m_cylinder2), tmpWidth, height()*0.1),
                             Qt::AlignCenter, m_header1);
            painter.drawText(QRect(3*tmpWidth, 0.8 * height()-tmpHeight*m_cylinder2/(m_cylinder1+m_cylinder2), tmpWidth, height()*0.1),
                             Qt::AlignCenter,  m_header2);

        }
        break;
    case 1:

        break;
    default:
        break;
    }
}
