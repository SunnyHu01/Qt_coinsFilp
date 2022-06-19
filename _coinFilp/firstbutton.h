#ifndef FIRSTBUTTON_H
#define FIRSTBUTTON_H

#include <QWidget>
#include <QPushButton>

class firstButton : public QPushButton
{
    Q_OBJECT
public:
    explicit firstButton(QWidget *parent = nullptr);
public:
    void movedown();
    void movepop();

//protected:
//    void mousePressEvent(QMouseEvent *event); //鼠标按下
//    void mouseReleaseEvent(QMouseEvent *event); //鼠标松开

//public:
//    enum MyPushButtonStat
//    {
//        Nomal,
//        Press
//    };
//private:
//    MyPushButtonStat mSat;
signals:
protected:
    void paintEvent(QPaintEvent *event);

};


#endif // FIRSTBUTTON_H
