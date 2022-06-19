#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <mymainwindow.h>
#include "thirdwindow.h"

class secondWindow : public MyMainWindow
{
    Q_OBJECT
public:
    explicit secondWindow(QWidget *parent = nullptr);


//private slots:
//    void transwindow1();

signals:
    void mySignal();
private slots:
    void changSlot();
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SECONDWINDOW_H
