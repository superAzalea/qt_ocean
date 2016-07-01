#ifndef CYLINDERMAP_H
#define CYLINDERMAP_H

#include <QDialog>

class CylinderMap : public QDialog
{
    Q_OBJECT
public:
    explicit CylinderMap(QDialog *parent = 0);
    void setPlotter(int cylinder1, QString header1, int cylinder2, QString header2);
    void setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                     int cylinder3, QString header3);

    void setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                     int cylinder3, QString header3, int cylinder4, QString header4);

    void setPlotter(int cylinder1, QString header1, int cylinder2, QString header2,
                     int cylinder3, QString header3, int cylinder4, QString header4,
                     int cylinder5, QString header5);
    void setMode(int mode);

protected:
      void paintEvent(QPaintEvent *);

private:
    int m_cylinder1;
    int m_cylinder2;
    int m_cylinder3;
    int m_cylinder4;
    int m_cylinder5;
    int m_amount;

    QString m_header1;
    QString m_header2;
    QString m_header3;
    QString m_header4;
    QString m_header5;

    int m_mode;
};

#endif // CYLINDERMAP_H
