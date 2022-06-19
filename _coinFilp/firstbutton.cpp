#include "firstbutton.h"
#include <QPainter>
#include <QPropertyAnimation>

firstButton::firstButton(QWidget *parent) : QPushButton(parent)
{

}


void firstButton::paintEvent(QPaintEvent *event)
{
    //绘制按钮的图片
    QPainter painter(this);
    QPixmap pixmp(":/_01/MenuSceneStartButton.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmp);
}
//按钮按下动画，，跳跃
void firstButton::movedown()
{
    QPropertyAnimation *animaton = new QPropertyAnimation(this,"geometry");
    animaton->setStartValue(this->geometry()); //设置指定（当前）位置
    animaton->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animaton->setDuration(100); //设置动画时长100ms
    animaton->start(QAbstractAnimation::DeleteWhenStopped);
}

void firstButton::movepop()
{
    QPropertyAnimation *animaton = new QPropertyAnimation(this,"geometry");
    animaton->setStartValue(this->geometry()); //设置指定（当前）位置
    animaton->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animaton->setDuration(100); //设置动画时长100ms
    animaton->start(QAbstractAnimation::DeleteWhenStopped);
}

//void firstButton::mousePressEvent(QMouseEvent *event)
//{

//}

//void firstButton::mouseReleaseEvent(QMouseEvent *event)
//{

//}

