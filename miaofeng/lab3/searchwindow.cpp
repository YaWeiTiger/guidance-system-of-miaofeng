#include"searchwindow.h"
#include"mywindow.h"
#include<fstream>
#include"algorithm.h"
extern Path p;
SearchWindow::SearchWindow(QWidget* parent)
    :QMainWindow(parent)
{
    mw=parent;
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->hide();

    this->move(1280,0);
    this->setFixedSize(280,720);
    //
    closeWindow=new QPushButton("关闭",this);
    closeWindow->move(0,0);
    closeWindow->resize(280,30);
    connect(closeWindow,&QPushButton::clicked,this,&SearchWindow::respond1);
    //
    r[0]=&SearchWindow::respond2;
    r[1]=&SearchWindow::respond3;
    r[2]=&SearchWindow::respond4;
    r[3]=&SearchWindow::respond5;
    r[4]=&SearchWindow::respond6;
    r[5]=&SearchWindow::respond7;
    //
    for(int i=0;i<6;i++)
        btns[i]=nullptr;
    //从screenPath读取最短的6条(<=6)路经
    fstream f;
    f.open("screenPath.txt",ios::in);
    vector<Path> ps{};
    int n;
    f>>n;
    for(int j=0;j<n;j++)
    {
        Path p;
        int num;
        string name;
        int length;
        f>>num;
        for(int i=0;i<num-1;i++)
        {
            f>>name;

            f>>length;

            p.names.push_back(name);
            p.pathLen.push_back(length);
        }
        f>>name;
        p.names.push_back(name);
        ps.push_back(p);


    }
    //创建对应路径的按钮并在按钮上显示路径信息
    for(int i=0;i<ps.size();i++)
    {
        btns[i]=new MyButton2(this);
        btns[i]->setP(ps[i]);
        int len=0;
        double t=0;
        for(int j=0;j<ps[i].pathLen.size();j++)
        {
            len+=ps[i].pathLen[j];
        }
        t=(double)len/(1.2*60);
        string s1=qstrTostr("路线总长为：")+to_string(len)+"m\n";
        string s2=qstrTostr("预计用时：")+to_string(t)+"min";
        string s=qstrTostr("路线")+to_string(i+1)+"\n";
        btns[i]->setText(strToqstr(s+s1+s2  ));
        btns[i]->move(0,30+i*115);
        btns[i]->resize(280,115);
        connect(btns[i],&QPushButton::clicked,this,r[i]);
    }
    f.close();

}
SearchWindow::~SearchWindow()
{

}
//关闭按钮响应函数
void SearchWindow::respond1()
{
    ((MyWindow*)mw)->respond3();

}
//对应路线按钮的响应函数
void SearchWindow::respond2()
{
    p=btns[0]->getP();
   ((MyWindow*)mw)->update();
}
void SearchWindow::respond3()
{
    p=btns[1]->getP();
   ((MyWindow*)mw)->update();
}
void SearchWindow::respond4()
{
    p=btns[2]->getP();
   ((MyWindow*)mw)->update();
}
void SearchWindow::respond5()
{
    p=btns[3]->getP();
   ((MyWindow*)mw)->update();
}
void SearchWindow::respond6()
{
    p=btns[4]->getP();
   ((MyWindow*)mw)->update();
}
void SearchWindow::respond7()
{
    p=btns[5]->getP();
   ((MyWindow*)mw)->update();
}
