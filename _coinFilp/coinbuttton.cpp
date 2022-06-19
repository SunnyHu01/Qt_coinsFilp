#include "coinbuttton.h"
#include <QPainter>

coinButtton::coinButtton(QWidget *parent) : QPushButton(parent)
{
    //this->setStat(0);
}

int coinButtton::stat() const
{
    return mStat;
}

void coinButtton::setStat(int stat)
{
    mStat = stat;
    if(mStat)
    {
        this->setIcon(QIcon(":/_01/Coin0001.png"));
    }
    else
    {
        this->setIcon(QIcon(":/_01/Coin0008.png"));
    }
    //设置icon大小
    this->setIconSize(this->size());
    //按钮不规则样式 setStyleSheet("QPushButton{border:0px;}");
    this->setStyleSheet("QPushButton{border:0px;}"); //去边框

    //动画的定时器信号和槽的实现
    connect(&this->mTimer,&QTimer::timeout,[=](){
        if(this->mStat)
        {
            this->mFrame--;
        }
        else
        {
            this->mFrame++;
        }
        //加载相应帧数的图片
        QString franmeName = QString(":/_01/Coin000%1.png").arg(this->mFrame);
        this->setIcon(QIcon(franmeName));
        if(this->mFrame == 8 | this->mFrame == 1)
        {
            this->mTimer.stop();
        }
    });
}

void coinButtton::setStatWithAnimation(int stat)
{
    this->mStat = stat;
    if(this->mStat)
    {
        //银币转金币  //为什么出现这种情况，是因为int stat是  反值  return this->setStatWithAnimation(!this->stat());
        this->mFrame = 8;
    }
    else
    {
        //金币转银币
        this->mFrame = 1;
    }
    this->mTimer.start(30); //30ms
}

void coinButtton::filp()
{
    //this->setStat(!this->stat());
    this->setStatWithAnimation(!this->stat());
}

void coinButtton::paintEvent(QPaintEvent *event)
{
    //添加背景框图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/_01/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //调用父类QPushButton事件，，显示金币图
    QPushButton::paintEvent(event);
}
