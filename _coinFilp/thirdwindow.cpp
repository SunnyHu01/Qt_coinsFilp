#include "thirdwindow.h"
#include <QPainter>
#include <QLabel>
#include "secondbutton.h"
#include "coinbuttton.h"
#include "dataconfig.h"
#include <QTimer>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSound>

thirdWindow::thirdWindow(int level, QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始游戏");
    Iswin = 0;
    //创建按钮
    secondButton *btn = new secondButton(":/_01/BackButton.png",":/_01/BackButtonSelected.png",this);
    btn->resize(72,32);

    btn->move((this->width() - btn->width()),(this->height() - btn->height()));

    //跳转界面
    connect(btn,SIGNAL(clicked()),this,SLOT(changSlot1()));

    //取出第几关的二维数组的数据
    dataConfig data;
    QVector< QVector<int> > dataArry = data.mData[level];

    //金币布局设置
    //4*4
    const int colWidth = 50;
    const int rowHeight = 50;
    //原点偏移  57,200
    const int colx = 57;
    const int rowy = 200;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            coinButtton *pushbtn = new coinButtton(this);
            //将按钮存到数组第几行第几列
            this->mCoins[i][j] = pushbtn;
            /*
             坐标：
             x: 列数 * 列宽
             y: 行数 * 行高
             */
            int x = j * colWidth + colx;
            int y = i * rowHeight + rowy;
            pushbtn->setGeometry(x,y,50,50);
            //pushbtn->setStat(1);
            pushbtn->setStat(dataArry[i][j]);

            //每次点击硬币，都将其状态置反
            connect(pushbtn,&coinButtton::clicked,[=](){
                //pushbtn->filp(); //硬币翻转函数
                if(Iswin) //如果胜利，直接return，否则就调用翻转函数
                    return;
                QSound::play(":/_01/ConFlipSound.wav");
                this->flip(i,j);
            });
        }

    }



    //添加Label
    QLabel *label = new QLabel(this);
    label->setText(QString("Level: %1").arg(level));
    //设置Label大小
    label->resize(150,50);
    //移动至左下角
    label->move(30,this->height() - 50);
    //字体：华文新魏  20
    label->setFont(QFont("华文新魏", 20));
}
void thirdWindow::changSlot1()
{
    emit this->mySignal1();
}

void thirdWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    //整体移动画
    //painter.translate(0,this->menuBar()->height());

    QPixmap pixmap(":/_01/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    pixmap.load(":/_01/Title.png");
    //painter.drawPixmap(0,0,pixmap);
    //将标题缩小一半
    pixmap = pixmap.scaled(pixmap.width()/2,pixmap.height()/2);
    painter.drawPixmap(0,30,pixmap);
}

void thirdWindow::flip(int i, int j)
{
    this->mCoins[i][j]->filp();

    //添加延迟效果，即中间的按钮先翻，周围的按钮后翻
    QTimer::singleShot(200,[=](){
        //分别翻动前后左右的金币；
        if(i-1 >= 0)
        {
            this->mCoins[i-1][j]->filp();
        }
        if(i+1 < 4)
        {
            this->mCoins[i+1][j]->filp();
        }
        if(j-1 >= 0)
        {
            this->mCoins[i][j-1]->filp();
        }
        if(j+1 < 4)
        {
            this->mCoins[i][j+1]->filp();
        }
        //判断是否胜利
        winnerPlay();
    });
}

void thirdWindow::winnerPlay()
{
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(!this->mCoins[i][j]->stat())
                return;
        }
    }
    //QMessageBox::information(this,"恭喜","你已经胜利了！");
    QSound::play(":/_01/LevelWinSound.wav");
    //胜利动画实现
    QLabel *labelPicture = new QLabel(this);
    QPixmap pix = QPixmap(":/_01/LevelCompletedDialogBg.png");
    labelPicture->setPixmap(pix);
    labelPicture->resize(pix.size());
    //居中,从上往下移
    labelPicture->move((this->width()-labelPicture->width())/2, -labelPicture->height());
    //移动动画
    QPropertyAnimation *animation = new QPropertyAnimation(labelPicture, "geometry");
    animation->setStartValue(labelPicture->geometry()); //将当前位置作为开始位置
    animation->setDuration(1000); //动画时长800ms
    animation->setEndValue(QRect(labelPicture->x(),(labelPicture->y()+(this->height()-labelPicture->height())/2),labelPicture->width(),labelPicture->height()));
    //设置动画运动曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);//结束删除动画对象
    //labelPicture->setScaledContents(true); //自适应大小
    labelPicture->show();
    Iswin = 1;

}
