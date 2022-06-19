#include "secondbutton.h"
#include <QPainter>
#include <QPropertyAnimation>

secondButton::secondButton(QString normalImg, QString pressImg, QWidget *parent)
    : QPushButton(parent)
    , mNormalImg(normalImg)
    , mPressedImg(pressImg)
{
    mStat = Normal;
}

void secondButton::paintEvent(QPaintEvent *event)
{
    //绘制按钮的图片
//    QPainter painter(this);
//    QPixmap pixmp(":/_01/BackButtonSelected.png");
//    painter.drawPixmap(0,0,this->width(),this->height(),pixmp);

    QPainter painter(this);
    QPixmap pix;
    if(mStat == Normal)
        pix.load(mNormalImg);
    if(mStat == Press)
        pix.load(mPressedImg);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制按钮文字
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter | Qt::AlignVCenter, this->text());
}

void secondButton::mousePressEvent(QMouseEvent *event)
{
    this->mStat = Press;
    this->update();
    QPushButton::mousePressEvent(event);
}

void secondButton::mouseReleaseEvent(QMouseEvent *event)
{
    this->mStat = Normal;
    this->update();
    QPushButton::mouseReleaseEvent(event);
}

////按钮按下动画，，跳跃
//void secondButton::movedown()
//{
//    QPropertyAnimation *animaton = new QPropertyAnimation(this,"geometry");
//    animaton->setStartValue(this->geometry()); //设置指定（当前）位置
//    animaton->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
//    animaton->setDuration(100); //设置动画时长100ms
//    animaton->start(QAbstractAnimation::DeleteWhenStopped);
//}

//void secondButton::movepop()
//{
//    QPropertyAnimation *animaton = new QPropertyAnimation(this,"geometry");
//    animaton->setStartValue(this->geometry()); //设置指定（当前）位置
//    animaton->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
//    animaton->setDuration(100); //设置动画时长100ms
//    animaton->start(QAbstractAnimation::DeleteWhenStopped);
//}
