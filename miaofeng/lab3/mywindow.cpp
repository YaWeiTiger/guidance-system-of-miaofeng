#include "mywindow.h"
#include "ui_mywindow.h"
#include<QPainter>
#include<QPen>
#include<QGraphicsView>
#include"flashdata.h"
#include"QDebug"
#include"algorithm.h"

Path p;//全局变量p表示当前的路径
Graph *G=nullptr;//G指向当前景区图结构


QString MyWindow::endName="";
MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{

    flash();
    //设置窗口大小
    this->setFixedSize(1560,720);
    //关联ui文件
    ui->setupUi(this);
    //创建地图
    background=new MyLabel(this);
    //设置选择框
    comboBox = new QComboBox(this);
    comboBox->move(320,0);
    comboBox->resize(130,30);
    comboBox->addItem("入口");
    comboBox->addItem("点将台");
    comboBox->addItem("古泉");
    comboBox->addItem("塔院");
    comboBox->addItem("宝金山玉虚宫");
    comboBox->addItem("秋风亭服务区");
    comboBox->addItem("鹰嘴岩");
    comboBox->addItem("好汉岩");
    comboBox->addItem("鹰嘴岩服务区");
    comboBox->addItem("琵琶石");
    comboBox->addItem("青杨林");
    comboBox->addItem("山间芦苇");
    comboBox->addItem("百年黄栌观景台");
    comboBox->addItem("百年黄栌服务区");
    comboBox->addItem("鹰虎石");
    comboBox->addItem("蓄水池观景台");
    comboBox->addItem("龙天观遗址");
    comboBox->addItem("清风亭");
    comboBox->addItem("玫瑰画餐厅");
    comboBox->addItem("红色背篓餐饮部");
    comboBox->addItem("石涧溪水");
    comboBox->addItem("坡坡餐厅");
    comboBox->addItem("云上石屋");
    comboBox->addItem("玫瑰亭");
    comboBox->addItem("农耕文化园");
    comboBox->addItem("杏树林");
    comboBox->addItem("层林观景台");
    comboBox->addItem("大杏树休息区");
    comboBox->addItem("卫生间1");
    comboBox->addItem("卫生间2");
    comboBox->addItem("卫生间3");
    comboBox->addItem("岔路口1");
    comboBox->addItem("岔路口2");
    comboBox->addItem("岔路口3");
    comboBox->addItem("岔路口4");
    comboBox->addItem("岔路口5");
    comboBox->addItem("岔路口6");
    comboBox->addItem("岔路口7");
    comboBox->addItem("岔路口8");
    comboBox->addItem("岔路口9");
    comboBox->addItem("岔路口10");
    comboBox->addItem("岔路口11");
    comboBox->addItem("岔路口12");
    comboBox->addItem("岔路口13");
    //文本域
    textField=new MyTextField(this);
    textField->resize(300,30);
    //textField->raise();
    connect(textField,&MyTextField::returnPressed,this,&MyWindow::respond);//事件响应，关联信号和槽
    //更新数据按钮
    flashButton=new QPushButton("更新数据",this);
    flashButton->move(460,0);
    connect(flashButton,&QPushButton::clicked,this,&flash);
    //
   connect(this,&MyWindow::signal1,this,&MyWindow::respond2);
    //
    recommendWindow=new RecommendWindow(this);
    recommendWindow->show();
    //
    searchWindow=nullptr;






}

MyWindow::~MyWindow()
{
    delete ui;
    delete textField;
    delete G;
    delete background;
}

MyTextField* MyWindow::getTextField()
{
    return this->textField;
}

QComboBox* MyWindow::getComboBox()
{
    return this->comboBox;
}

//搜索框中按下回车会执行该函数
void MyWindow::respond()
{
    this->textField->setTxt(this->textField->text());
    QString s=comboBox->currentText();
    string s1=qstrTostr(s);
    string s2=qstrTostr(this->textField->getTxt());
    int begin=getIndex(s1,G);
    int end=getIndex(s2,G);
   //终点存在且不为起点
    if(end!=-1&&end!=begin)
   {
       findPath(G, begin, end);//找到起点到终点所有路径
       p=minPath(G,begin,end);//找到最短路径
       screenPath(G,begin,end);//找到最短的6条路径
       //绘图
       this->update();
   }
   //未找到景点刷新两个文件，表示当前无任何有效路径
   else
   {
       fstream f1,f2;
       f1.open("path.txt",ios::out);
       f2.open("screenPath.txt",ios::out);
       f2<<0;
       f1.close();
       f2.close();
       p=Path();
       this->update();
   }
   //删除推荐窗口
   delete recommendWindow;
   recommendWindow=nullptr;
   delete searchWindow;
   //展示搜索窗口
   searchWindow=new SearchWindow(this);
   searchWindow->show();
}
//推荐窗中景点按钮的响应函数
void MyWindow::respond2()
{

    QString s=comboBox->currentText();
    string s1=qstrTostr(s);
    string s2=qstrTostr(this->endName);
    int begin=getIndex(s1,G);
    int end=getIndex(s2,G);
    //findPath(G, begin, end);
    p=minPath(G,begin,end);
    this->update();
}
//关闭按钮按下的响应函数
void MyWindow::respond3()
{
    delete searchWindow;
    searchWindow=nullptr;
    recommendWindow=new RecommendWindow(this);
    recommendWindow->show();
}
