#include "secondwindow.h"
#include "secondbutton.h"
#include <QTimer>
#include <QPainter>
#include <QMenuBar>
#include "thirdwindow.h"
#include <QSound>

secondWindow::secondWindow(QWidget *parent) : MyMainWindow(parent)
{
    //创建按钮
    secondButton *btn = new secondButton(":/_01/BackButton.png",":/_01/BackButtonSelected.png",this);
    btn->resize(72,32);
    //按钮水平居中，垂直方向在3/4的位置上
    /*
    计算方式：x = 窗口宽度/2-按钮宽度/2  y = 窗口高度*（3/4）- 按钮高度/2
    */
    btn->move((this->width() - btn->width()),(this->height() - btn->height()));

    //自定义按钮
    //按钮动画
//    connect(btn,&secondButton::clicked,[=](){
//       btn->setEnabled(false);
//       btn->movedown();
//       //按钮向上动画覆盖了向下的动画,,QTimer::singleShot,,但发现快速点击，按钮会移动，故设置在按钮动画结束前，按钮无效；
//       QTimer::singleShot(150,[=](){
//           btn->movepop();
//       });
//       QTimer::singleShot(150,[=](){
//           btn->setEnabled(true);
//       });
//       QTimer::singleShot(150,[=](){
//           this->changSlot();
//       });
//    });

    //跳转界面
    connect(btn,SIGNAL(clicked()),this,SLOT(changSlot()));

    //创建关卡按钮20个
    const int colWidth = 70;
    const int rowHeight = 70;
    //原点偏移  25,130
    const int colx = 25;
    const int rowy = 135;
    for(int i=0;i<20;++i)
    {
        secondButton *pushbtn = new secondButton(":/_01/LevelIcon.png",":/_01/BoardNode.png",this);
        pushbtn->setText(QString::number(i+1));
        /*
         排列：
         行：i/4
         列：i%4
         坐标：
         x: 列数 * 列宽
         y: 行数 * 行高
         */
        int col = i%4;
        int row = i/4;
        int x = col * colWidth + colx;
        int y = row * rowHeight + rowy;
        pushbtn->resize(57,57);
        pushbtn->move(x,y);
        //创建第三个场景
        connect(pushbtn,&secondButton::clicked,[=](){
            QSound::play(":/_01/TapButtonSound.wav");
            thirdWindow *thirdwin = new thirdWindow(i+1);
            //设置thirdWindow关闭的时候自动释放
            thirdwin->setAttribute(Qt::WA_DeleteOnClose);

            this->hide();
            thirdwin->show();

            //窗口自适应位置
            thirdwin->move(this->pos());

            //关卡点击返回按钮后，触发事件
            //connect(thirdwin,SIGNAL(mySignal1()),this,SLOT(transwindow1()));
            connect(thirdwin,&thirdWindow::mySignal1,[=](){
                QSound::play(":/_01/BackButtonSound.wav");
                //thirdwin->hide();
                thirdwin->close();//这里将不能使用hide，应close
                this->show();

                this->move(thirdwin->pos()); //窗口自适应位置
            });
        });
    }    

}

//void secondWindow::transwindow1()
//{
//    thirdWindow.hide();
//    this->show();
//}

void secondWindow::changSlot()
{
    emit this->mySignal();
}

void secondWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    //整体移动画
    //painter.translate(0,this->menuBar()->height());

    QPixmap pixmap(":/_01/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    pixmap.load(":/_01/Title.png");
    //painter.drawPixmap(0,0,pixmap);
    painter.drawPixmap(25,30,pixmap);
}
