#ifndef COINBUTTTON_H
#define COINBUTTTON_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

class coinButtton : public QPushButton
{
    Q_OBJECT
public:
    explicit coinButtton(QWidget *parent = nullptr);

    int stat() const;
    void setStat(int stat);

    void setStatWithAnimation(int stat);//状态动画函数
    void filp(); //硬币翻转函数

signals:
protected:
    void paintEvent(QPaintEvent *event);
private:
    //0表示银币，1表示金币
    int mStat;
    int mFrame; //帧数
    QTimer mTimer; // 定时器
};


#endif // COINBUTTTON_H
