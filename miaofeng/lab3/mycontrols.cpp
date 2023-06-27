#include"mycontrols.h"
#include<QString>
#include<QDebug>
#include<QMouseEvent>
#include "class.h"
#include"algorithm.h"
#include"mywindow.h"
using namespace std;
extern Path p;
extern Graph *G;

MyLabel::MyLabel(QWidget *parent)
    :QLabel(parent)
{
      //设置景区平面图
      m_Img = QPixmap("map.JPG");
      setPixmap(m_Img);
      //设置地图大小
      setGeometry(0, 0, m_Img.width(), m_Img.height());
      ql=nullptr;
      //设置鼠标跟踪
      this->setMouseTracking(true);
      //指向主窗口用于调用主窗口成员
      mw=parent;

}
MyLabel::~MyLabel()
{

}
void MyLabel::paintEvent(QPaintEvent *e)
{
    QLabel::paintEvent(e);//调用基类的绘制方法，绘制图片背景
    QPainter painter(this);
    QPen pen(QColor(0, 255, 0), 3);
    painter.setPen(pen);
    //根据全局变量P绘出路径
    for(int i=0;i<p.pathLen.size();i++)
    {
        painter.drawLine(G->nodes[getIndex(p.names[i],G)].getX(),G->nodes[getIndex(p.names[i],G)].getY(),
                G->nodes[getIndex(p.names[i+1],G)].getX(),G->nodes[getIndex(p.names[i+1],G)].getY());
    }
    pen.setWidth(0);
    painter.setPen(pen);
    QBrush brush(QColor(0x00,0x00,0xFF));
    if(p.pathLen.size()>0)
    {

        //画起点（蓝色）
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(G->nodes[getIndex(p.names[0],G)].getX(),G->nodes[getIndex(p.names[0],G)].getY()),7,7);
        //画终点（红色）
        brush.setColor(QColor(0xFF,0x00,0x00));
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(G->nodes[getIndex(p.names[p.names.size()-1],G)].getX(),G->nodes[getIndex(p.names[p.names.size()-1],G)].getY()),7,7);
    }
    else
    {
        //画当前起点（蓝色）
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(G->nodes[getIndex(qstrTostr(((MyWindow*)mw)->getComboBox()->currentText()),G)].getX(),
                            G->nodes[getIndex(qstrTostr(((MyWindow*)mw)->getComboBox()->currentText()),G)].getY()),7,7);
    }

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    delete ql;
    ql=nullptr;
    int x= ev->x();
    int y=ev->y();
    int index=Find(G,x,y);

    if(index>-1)
    {
         ql=new QPushButton(this);
         ql->resize(150,80);
         string s1="";
         string s2="";
         string s3="";
         string s4="";
         string s5;
        if(index<=27&&index>0)
        {
            s1=qstrTostr("是否开放：");
            if(G->nodes[index].getIsOpen())
            {
                s2=qstrTostr("是\n");
                s3=qstrTostr("当前人数：")+to_string(G->nodes[index].getTouristsNumber())+"\n";
            }
            else
            {
                s2=qstrTostr("否\n");
            }
            s4=qstrTostr("历史热度排行：No.")+to_string(G->nodes[index].getRank());

        }
        else
        {
            if(index<=30&&index>27)
            {
                s1=qstrTostr("是否开放：");
                if(G->nodes[index].getIsOpen())
                {
                    s2=qstrTostr("是\n");
                    s3=qstrTostr("当前人数：")+to_string(G->nodes[index].getTouristsNumber())+"\n";
                }
                else
                {
                    s2=qstrTostr("否\n");
                }
            }
            else
            {
                s3=qstrTostr("当前人数：")+to_string(G->nodes[index].getTouristsNumber())+"\n";
            }

        }

         s5=s1+s2+s3+s4;
         ql->move(x,y);
         ql->setText(strToqstr(s5));
         ql->show();
   }

}

//

MyButton1::MyButton1(QWidget* parent)
    :QPushButton(parent)
{
    txt="";
}
MyButton1::~MyButton1()
{

}
QString MyButton1::getTxt()
{
    return txt;
}
void MyButton1::setTxt(QString txt)
{
    this->txt=txt;
}

//

MyButton2::MyButton2(QWidget* parent)
    :QPushButton(parent)
{
    p=Path();
}
MyButton2::~MyButton2()
{

}
void MyButton2::setP(Path p)
{
    this->p=p;
}
Path MyButton2::getP()
{
    return p;
}

//

MyTextField::MyTextField(QWidget *parent):
       QLineEdit(parent)
   {
       this->txt="\0";
   }
MyTextField::~MyTextField()
{

}
QString MyTextField::getTxt()
   {
       return this->txt;
   }
void MyTextField::setTxt(QString txt)
{
    this->txt=txt;
}
