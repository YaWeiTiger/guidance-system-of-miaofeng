#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H
#include <QMainWindow>
#include<QWidget>
#include<QPushButton>
#include "class.h"
#include"mycontrols.h"
class SearchWindow : public QMainWindow
{

    Q_OBJECT

public:
    SearchWindow(QWidget* parent=nullptr);
    ~SearchWindow();

public slots:
    void respond1();
    void respond2();
    void respond3();
    void respond4();
    void respond5();
    void respond6();
    void respond7();
private:
    QWidget* mw;//指向主窗口
    QPushButton* closeWindow;//关闭按钮
    MyButton2* btns[6];//对应推荐路线
    void (SearchWindow ::*r[6])(void);//对应respond2-7
};
#endif // SEARCHWINDOW_H
