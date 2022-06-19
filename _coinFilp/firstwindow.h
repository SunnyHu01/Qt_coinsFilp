#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "secondwindow.h"

class firstWindow : public MyMainWindow
{
    Q_OBJECT
public:
    explicit firstWindow(QWidget *parent = nullptr);

signals:

private:
    secondWindow sewindow;

private slots:
    void transwindow();
};

#endif // FIRSTWINDOW_H
