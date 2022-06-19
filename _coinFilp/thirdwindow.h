#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "coinbuttton.h"

class thirdWindow : public MyMainWindow
{
    Q_OBJECT
public:
    thirdWindow(int level, QWidget *parent = nullptr);

signals:
    void mySignal1();
private slots:
    void changSlot1();
protected:
    void paintEvent(QPaintEvent *event);
    void flip(int i, int j);
    void winnerPlay();
private:
    //硬币按钮数组
    coinButtton *mCoins[4][4];
    int Iswin; //用来判断是否胜利
};

#endif // THIRDWINDOW_H
