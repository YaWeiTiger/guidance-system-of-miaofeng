#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include"mycontrols.h"
#include<QPushButton>
#include "class.h"
#include"recommendwindow.h"
#include"searchwindow.h"
#include"QComboBox"
QT_BEGIN_NAMESPACE
namespace Ui { class MyWindow; }
QT_END_NAMESPACE

//主窗口类
class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();
    MyTextField* getTextField();
    QComboBox* getComboBox();
    static QString endName;//终点名字  
public slots://槽函数
    void respond();
    void respond2();
    void respond3();
signals://信号函数
    void signal1();
private:
    Ui::MyWindow *ui;
    MyTextField *textField;//文本域
    QPushButton* flashButton;//刷新按钮
    QComboBox* comboBox;//选择框
    MyLabel *background;//景区平面图
    RecommendWindow* recommendWindow;//推荐窗口
    SearchWindow* searchWindow;//搜索窗口

};
#endif // MYWINDOW_H
