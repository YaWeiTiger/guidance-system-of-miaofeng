#ifndef MYCONTROLS_H
#define MYCONTROLS_H
#include<QString>
#include<QPainter>
#include<QGraphicsView>
#include<QLabel>
#include<QMouseEvent>
#include<QPushButton>
#include<QLineEdit>
#include"class.h"
//基于QLabel自定义标签类,用来显示地图和实现路径显示及鼠标悬浮
class MyLabel : public QLabel
{

public:
    MyLabel(QWidget *parent);
    ~MyLabel();
    void paintEvent(QPaintEvent *e) override;//绘图事件响应
    virtual void mouseMoveEvent(QMouseEvent* ev) override;//鼠标移动事件响应

private:
    QPixmap m_Img;//label的图标，这里为景区平面图
    QPushButton* ql;//用于在图上展示鼠标所在的景点的信息
    QWidget *mw;//指向主窗口对象
};

//自定义按钮
class MyButton1:public QPushButton
{
public:
    MyButton1(QWidget* parent=nullptr);
    ~MyButton1();
    QString getTxt();
    void setTxt(QString txt);
private:
    QString txt;//按钮代表的景点名字
};
//
class MyButton2:public QPushButton
{
public:
    MyButton2(QWidget* parent=nullptr);
    ~MyButton2();
    void setP(Path p);
    Path getP();

private:
    Path p;//按钮代表的路线对象
};

//自定义文本域类
class MyTextField :public QLineEdit
{
    Q_OBJECT;
private:
   QString txt;//文本域接收的终点名字
public:
   MyTextField(QWidget *parent=nullptr);
   ~ MyTextField();
   QString getTxt();
   void setTxt(QString txt);

};
#endif // MYCONTROLS_H
