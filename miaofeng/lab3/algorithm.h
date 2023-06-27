#ifndef ALGORITHM_H
#define ALGORITHM_H
#include"class.h"
//按热度排序
vector<int> sortByHeat(Graph* graph);
//人数从高到低排序
vector<int>sortByTourists(Graph* graph);
//人数从低到高排序
vector<int> sortByTouristsR(Graph* graph);
//判断点x，y是否在以景点坐标为圆心3为半径的圆中
int Find(Graph* G, int x, int y);
//从文件中读取数据创建景区图结构
Graph* create_();
//返回给定起点到给定终点的最短路径
Path minPath(Graph*, int,int);
int findMin(int[], bool[]);
bool flag(bool[]);
Path printPath(int, int, int[], Graph*);
//返回给定端点的边的长度
int PathLen(Graph*, int, int);
//将begin到end所有的路径输出到文件中
void findPath(Graph* G, int begin, int end);
//将begin到end最短的6条路径输出到文件中（不足6条有几条就写几条）
void screenPath(Graph* G, int begin, int end);
//获得给定名字的景点的索引
int getIndex(string name,Graph *g);
//将std::string变量转化成QString
QString strToqstr(const string str);
//将QString变量转化成std::string
string qstrTostr(const QString qstr);

#endif // ALGORITHM_H
