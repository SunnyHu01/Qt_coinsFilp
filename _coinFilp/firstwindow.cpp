#include "firstwindow.h"
#include <QPushButton>
#include "firstbutton.h"
#include <QTimer>
#include <QSound>

firstWindow::firstWindow(QWidget *parent) : MyMainWindow(parent)
{
    //共用一个窗口，故继承MyMainWindow
    this->setWindowTitle("翻金币");
    //创建按钮
    firstButton *btn = new firstButton(this);
    btn->resize(114,114);
    //按钮水平居中，垂直方向在3/4的位置上
    /*
    计算方式：x = 窗口宽度/2-按钮宽度/2  y = 窗口高度*（3/4）- 按钮高度/2
    */
    btn->move((this->width()/2 - btn->width()/2),(this->height()*3/4 - btn->height()/2));

    //自定义按钮
    //按钮动画
    connect(btn,&firstButton::clicked,[=](){
       btn->setEnabled(false);
       btn->movedown();
       //按钮向上动画覆盖了向下的动画,,QTimer::singleShot,,但发现快速点击，按钮会移动，故设置在按钮动画结束前，按钮无效；
       QTimer::singleShot(150,[=](){
           btn->movepop();
       });
       QTimer::singleShot(150,[=](){
           btn->setEnabled(true);
       });
       QTimer::singleShot(150,[=](){
           QSound::play(":/_01/TapButtonSound.wav");
           this->hide();
           sewindow.show();
           sewindow.move(this->pos());
           sewindow.setWindowTitle("开始场景");
       });
    });

    //跳转界面
//    connect(btn,&firstButton::clicked,[=](){
//          this->hide();
//          sewindow.show();
//          sewindow.setWindowTitle("开始场景");
//    });

    //开始界面点击返回按钮后，触发事件
    connect(&sewindow,SIGNAL(mySignal()),this,SLOT(transwindow()));

}


void firstWindow::transwindow()
{
    QSound::play(":/_01/BackButtonSound.wav");
    sewindow.hide();
    this->show();
    this->move(sewindow.pos());
}
