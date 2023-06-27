#include"recommendwindow.h"
#include"algorithm.h"
#include"mywindow.h"
#include"flashdata.h"
extern Path p;
extern Graph* G;
RecommendWindow::RecommendWindow(QWidget* parent)
    : QMainWindow(parent)
{
   this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
   this->hide();
   this->move(1280,0);
   this->setFixedSize(280,720);
   //推荐框顶部3个按钮
   //热度从高到低
   btn1=new QPushButton("热度↓",this);
   btn1->resize(93,30);
   btn1->move(0,0);
   connect(btn1,&QPushButton::clicked,this,&RecommendWindow::respond1);
   //人数从高到低
   btn2=new QPushButton("人数↓",this);
   btn2->resize(93,30);
   btn2->move(93,0);
   connect(btn2,&QPushButton::clicked,this,&RecommendWindow::respond2);

   //人数从低到高
   btn3=new QPushButton("人数↑",this);
   btn3->resize(93,30);
   btn3->move(186,0);
   connect(btn3,&QPushButton::clicked,this,&RecommendWindow::respond3);
   //
   r[0]=&RecommendWindow::respond4;
   r[1]=&RecommendWindow::respond5;
   r[2]=&RecommendWindow::respond6;
   r[3]=&RecommendWindow::respond7;
   r[4]=&RecommendWindow::respond8;
   r[5]=&RecommendWindow::respond9;
   //

   mw=parent;
   //
   for(int i=0;i<6;i++)
   {
       btns[i]=nullptr;
   }
   this->respond1();
}
RecommendWindow::~RecommendWindow()
{
    delete btn1;
    delete btn2;
    delete btn3;
    for(int i=0;i<6;i++)
    {
        delete btns[i];
    }
}
//热度按钮响应函数
void RecommendWindow::respond1()
{
    vector<int> rank=sortByHeat(G);
    for(int i=0;i<6;i++)
    {
        delete btns[i];
        btns[i]=new MyButton1(this);
        btns[i]->show();
        btns[i]->move(0,30+i*115);
        btns[i]->resize(280,115);
        btns[i]->setTxt(strToqstr(G->nodes[rank[i]].getName()));
        string inf1=G->nodes[rank[i]].getName()+qstrTostr("\n历史热度排名: No.")+to_string(G->nodes[rank[i]].getRank())+
                qstrTostr("\n是否开放: ");
        string inf2;
        if(G->nodes[rank[i]].getIsOpen())
        {
          inf2=qstrTostr("是\n当前人数为: ")+to_string(G->nodes[rank[i]].getTouristsNumber());
        }
        else
        {
          inf2=qstrTostr("否");
        }
        btns[i]->setText(strToqstr(inf1+inf2));
        connect(btns[i],&QPushButton::clicked,this,r[i]);
    }
}
//人数从高到低响应函数
void RecommendWindow::respond2()
{
     vector<int> rank=sortByTourists(G);
     int flag=0;
     if(rank.size()>=6)
         flag=6;
     else
         flag=rank.size();
     for(int i=0;i<6;i++)
     {
         delete btns[i];
         btns[i]=nullptr;
     }
     for(int i=0;i<flag;i++)
     {
         btns[i]=new MyButton1(this);
         btns[i]->show();
         btns[i]->move(0,30+i*115);
         btns[i]->resize(280,115);
         btns[i]->setTxt(strToqstr(G->nodes[rank[i]].getName()));
         string inf1=G->nodes[rank[i]].getName()+qstrTostr("\n历史热度排名: No.")+to_string(G->nodes[rank[i]].getRank())+
                 qstrTostr("\n是否开放: ");
         string inf2;
         if(G->nodes[rank[i]].getIsOpen())
         {
           inf2=qstrTostr("是\n当前人数为: ")+to_string(G->nodes[rank[i]].getTouristsNumber());
         }
         else
         {
           inf2=qstrTostr("否");
         }
         btns[i]->setText(strToqstr(inf1+inf2));

         connect(btns[i],&QPushButton::clicked,this,r[i]);
     }
}
//人数从低到高响应函数
void RecommendWindow::respond3()
{
    vector<int> rank=sortByTouristsR(G);
    int flag=0;
    if(rank.size()>=6)
        flag=6;
    else
        flag=rank.size();
    for(int i=0;i<6;i++)
    {
        delete btns[i];
        btns[i]=nullptr;
    }
    for(int i=0;i<flag;i++)
    {
        btns[i]=new MyButton1(this);
        btns[i]->show();
        btns[i]->move(0,30+i*115);
        btns[i]->resize(280,115);
        btns[i]->setTxt(strToqstr(G->nodes[rank[i]].getName()));
        string inf1=G->nodes[rank[i]].getName()+qstrTostr("\n历史热度排名: No.")+to_string(G->nodes[rank[i]].getRank())+
                qstrTostr("\n是否开放: ");
        string inf2;
        if(G->nodes[rank[i]].getIsOpen())
        {
          inf2=qstrTostr("是\n当前人数为: ")+to_string(G->nodes[rank[i]].getTouristsNumber());
        }
        else
        {
          inf2=qstrTostr("否");
        }
        btns[i]->setText(strToqstr(inf1+inf2));
        connect(btns[i],&QPushButton::clicked,this,r[i]);
    }
}
//六个按钮对应的响应函数，触发主窗口signal1信号
void RecommendWindow::respond4()
{
    MyWindow::endName=btns[0]->getTxt();
    ((MyWindow*)mw)->signal1();

}
void RecommendWindow::respond5()
{
    MyWindow::endName=btns[1]->getTxt();
    ((MyWindow*)mw)->signal1();

}
void RecommendWindow::respond6()
{
    MyWindow::endName=btns[2]->getTxt();
    ((MyWindow*)mw)->signal1();

}
void RecommendWindow::respond7()
{
    MyWindow::endName=btns[3]->getTxt();
   ((MyWindow*)mw)->signal1();

}
void RecommendWindow::respond8()
{
   MyWindow::endName=btns[4]->getTxt();
   ((MyWindow*)mw)->signal1();

}
void RecommendWindow::respond9()
{
    MyWindow::endName=btns[5]->getTxt();
    ((MyWindow*)mw)->signal1();

}

