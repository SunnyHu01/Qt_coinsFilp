#ifndef SECONDBUTTON_H
#define SECONDBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class secondButton : public QPushButton
{
    Q_OBJECT
public:
    enum secondButtonStat
    {
        Normal,
        Press
    };
public:
    secondButton(QString Normal, QString Press, QWidget *parent = nullptr);

signals:
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    //void movedown();
    //void movepop();

private:
    secondButtonStat mStat;

    QString mNormalImg;
    QString mPressedImg;
};

#endif // SECONDBUTTON_H
