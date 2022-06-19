#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QPainter>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    //this->setWindowTitle("翻金币");
    this->setFixedSize(320,588);
    //窗口Icon
    this->setWindowIcon(QIcon(":/_01/Coin0001.png"));
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    QPixmap pixmap(":/_01/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

