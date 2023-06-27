#ifndef RECOMMENDWINDOW_H
#define RECOMMENDWINDOW_H
#include <QMainWindow>
#include<QWidget>
#include<QPushButton>
#include "class.h"
#include"mycontrols.h"

class RecommendWindow : public QMainWindow
{

    Q_OBJECT

public:
    RecommendWindow(QWidget* parent=nullptr);
    ~RecommendWindow();

public slots:
    void respond1();
    void respond2();
    void respond3();
    void respond4();
    void respond5();
    void respond6();
    void respond7();
    void respond8();
    void respond9();
private:
    QPushButton* btn1;//按热度推荐
    QPushButton* btn2;//人数↓
    QPushButton* btn3;//人数↑
    MyButton1* btns[6];//对应推荐的景点
    void (RecommendWindow::*r[6])(void);//对应respond4-9
    QWidget* mw;//指向主窗口对象

};
#endif // RECOMMENDWINDOW_H
