#include"algorithm.h"
#include<math.h>
int numberOfEdge = 0;  //路径数
int indexOfPath = 0;   //用于6个最小路径的索引
int numberOfSecne[6];
int numberOfSecne1 = 0; //每个路径的景点数

string nameOfPath[6];
int lengthOfPath[6];   //两个长度为6的数组，用于存路径名字和长度
bool flag1 = true;

extern Path p;
extern Graph *G;

//排序不包括入口岔路口及卫生间
//
vector<int> sortByHeat(Graph* graph) {
    vector<int>heatOfNode;

    for (int i = 0; i < graph->nodes.size(); i++) {
        if (graph->nodes[i].getRank() == 0) {
            continue;
        }
        heatOfNode.push_back(graph->nodes[i].getRank());
    }

    vector<int>resultAfterSort(heatOfNode.size() + 1);
    for (int i = 0; i < heatOfNode.size(); i++) {
        resultAfterSort[heatOfNode[i]] = i + 1;
    }
    resultAfterSort.erase(resultAfterSort.begin());
    return resultAfterSort;
}
//
vector<int>sortByTourists(Graph* graph) {
    vector<int>resultAfterSort;

    vector<int>touristsNumber;
    touristsNumber.push_back(-1);
    for (int i = 1; i < graph->nodes.size(); i++) {
        if (graph->nodes[i].getRank() == 0) {
            continue;
        }
        if (graph->nodes[i].getIsOpen() == 0) {
            touristsNumber.push_back(-1);
        }
        else {
            touristsNumber.push_back(graph->nodes[i].getTouristsNumber());
        }
    }
    for (int i = 0; i < touristsNumber.size(); i++) {
        int maxNumber = 0;
        int maxIndex = 0;
        for (int j = 0; j < touristsNumber.size(); j++) {
            if (touristsNumber[j] > maxNumber) {
                maxNumber = touristsNumber[j];
                maxIndex = j;
            }
        }
        resultAfterSort.push_back(maxIndex);
        touristsNumber[maxIndex] = 0;
    }
    while (*(resultAfterSort.end()-1) == 0) {
        resultAfterSort.pop_back();
    }
    return resultAfterSort;
}

//
vector<int> sortByTouristsR(Graph* graph) {
    vector<int>resultAfterSort = sortByTourists(graph);
    reverse(resultAfterSort.begin(), resultAfterSort.end());
    return resultAfterSort;
}
//
int Find(Graph* G, int x, int y) {
    for (int i = 0; i < 44; i++) {
        if(pow((x-G->nodes[i].getX()),2)+pow(y-G->nodes[i].getY(),2)<=9)
            return i;
    }
    return -1;
}
//
Graph* create_() {
    Graph* graph = new Graph();
    int num = 0;
    string name_;//景点名字
    int touristsNumber_;//游客人数
    bool isOpen_;//是否开放
    int rank_;//热度等级
    int adjvex_;//景点编号
    int length_;//路径长
    int x_, y_;//景点在地图中的坐标
    ifstream ifs;
    ifs.open("data.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "error" << endl;
    }
    else {
        //cout << "ok";
    }
    ifs >> num;//读入景点个数
    for (int i = 0; i < num; i++) {
        graph->nodes.push_back(*(new Node()));
    }
    for (int i = 0; i < num; i++) {//读入各景点参数，创建图
        int number = 0;
        Edge* temp = nullptr;
        ifs >> name_ >> touristsNumber_ >> isOpen_ >> rank_;
        graph->nodes[i].setName(name_);
        graph->nodes[i].setTouristsNumber(touristsNumber_);
        graph->nodes[i].setIsOpen(isOpen_);
        graph->nodes[i].setRank(rank_);
        ifs >> number;
        for (int j = 0; j < number; j++) {
            graph->nodes[i].edge = new Edge();
            graph->nodes[i].edge->next = temp;
            temp = graph->nodes[i].edge;
            ifs >> adjvex_;
            graph->nodes[i].edge->setAdjvex(adjvex_);
            ifs >> length_;
            graph->nodes[i].edge->setLength(length_);
        }
        ifs >> x_ >> y_;
        graph->nodes[i].setX(x_);
        graph->nodes[i].setY(y_);
    }
    ifs.close();
    return graph;
}
//
Path minPath(Graph* graph, int begin,int end) {
    Path p;
    bool isVis[100];//判断某点是否访问过
    int pre[100];//前驱点集
    int path[100];//路径集
    for (int i = 0; i < NUMOFSCENE; i++) {//初始化
        isVis[i] = false;
        path[i] = 10000;
        pre[i] = -1;
    }
    path[begin] = 0;
    while (flag(isVis)) {//循环至所有点都被更新过
        int cr = findMin(path, isVis);//在未更新的点中寻找距离最小的点
        isVis[cr] = true;//该点标记为已更新
        Edge* e = graph->nodes[cr].edge;
        while (e) {
            if (!isVis[e->getAdjvex()]) {//若该点某条边指向顶点未访问过
                if (path[cr] + e->getLength() < path[e->getAdjvex()]) {//判断该边长加上该点现路径长是否小于指向点路径长
                    path[e->getAdjvex()] = path[cr] + e->getLength();//小于则更新
                    pre[e->getAdjvex()] = cr;
                }
            }
            e = e->next;
        }
    }
    for (int i = 0; i < NUMOFSCENE; i++) {
        if (i != begin&&i==end) {
           //qDebug()<< strToqstr(graph->nodes[begin].getName())<< "到" <<strToqstr(graph->nodes[i].getName()) << "的最短距离为" << path[i] ;

             p=printPath(begin, i, pre, graph);

        }
    }
    return p;
}
//
int findMin(int path[], bool isVis[]) {//在未更新点中寻找现路径最小的点并返回下标
    int min = 100000;
    int Index = -1;
    for (int i = 0; i < NUMOFSCENE; i++) {
        if (path[i] < min && (!isVis[i])) {
            Index = i;
            min = path[i];
        }
    }
    return Index;
}//
////
Path printPath(int begin, int end, int pre[], Graph* graph) {//打印得到的某条路径具体信息
    Path p;
    stack<int> s;
    stack<int> s_;
    int now = -1;
    now = end;
    int sideLength = 0;
    while (pre[now] != -1) {
        s.push(now);
        s_.push(PathLen(graph, pre[now], now));
        now = pre[now];
    }
    s.push(now);
    while (!s.empty()) {
        if (s.size() != 1) {
            //qDebug() << strToqstr(graph->nodes[s.top()].getName()) << "-" << s_.top() << "m-";
           p.names.push_back(graph->nodes[s.top()].getName());
           p.pathLen.push_back(s_.top());
            s_.pop();
        }
        else {
            //qDebug() << strToqstr(graph->nodes[s.top()].getName());
            p.names.push_back(graph->nodes[s.top()].getName());
        }
        s.pop();
    }
    return p;
}
//
int PathLen(Graph* G, int pre, int cur) {//求某条路径的棕长度
    Edge* e = new Edge();
    e = G->nodes[cur].edge;
    while (1) {
        if (e->getAdjvex() == pre) {
            return e->getLength();
        }
        e = e->next;
    }
}
//
bool flag(bool isVis[]) {//判断是否所有点都已经更新完毕
    for (int i = 0; i < NUMOFSCENE; i++) {
        if (!isVis[i])
            return true;
    }
    return false;
}
//
void findPath(Graph* G, int begin, int end) {//寻找两点间所有路径函数
    vector<int> path;//存放边集
    vector<int> k;//存放顶点集
    ofstream ofs;
    ofs.open("path.txt", ios::out);
    bool isvisited[100];//判断顶点是否访问过
    int visitTime[100];//判断该顶点已经访问了几条边
    for (int i = 0; i < 100; i++) {//初始化
        isvisited[i] = false;
        visitTime[i] = 0;
    }
    k.push_back(begin);//从某点开始，将起点压入顶点集
    isvisited[begin] = true;//在顶点集的点设置为已经访问过
    int now = begin;//now为顶点集中最顶上的点
    Edge* p = new Edge();
    p = G->nodes[now].edge;
    while (k.size() > 0) {//循环至顶点集中没有顶点为止，所有路径都找出
        p = G->nodes[now].edge;
        for (int i = 0; i < visitTime[now]; i++)//通过visitTime快速访问没访问过的边
            p = p->next;
        if (!p) {//如果该顶点所有边已经访问完，弹出顶点
            isvisited[k.back()] = false;
            k.pop_back();
            visitTime[now] = 0;
            if (k.size() == 0)
                break;
            path.pop_back();
            now = k.back();
            p = G->nodes[now].edge;
        }

        else if (!isvisited[p->getAdjvex()]) {//如果该顶点存在边且边指向的顶点未访问过
            path.push_back(p->getLength());
            visitTime[now]++;
            now = p->getAdjvex();
            isvisited[now] = true;
            k.push_back(now);
            if (now == end) {//边指向的顶点为终点
                for (int i = 0; i < k.size() - 1; i++) {
                    ofs << G->nodes[k[i]].getName() << " " << path[i] << " ";
                }//则得到一条新的路径
                ofs << G->nodes[k[k.size() - 1]].getName();
                ofs << endl;
                //弹出终点
                isvisited[now] = false;
                k.pop_back();
                path.pop_back();
                now = k.back();
                numberOfEdge++;
            }
        }
        else visitTime[now]++;//访问下一条边
    }
    ofs.close();
}
//
void screenPath(Graph* G, int begin, int end) {
    for(int i = 0; i < 6; i++){
        numberOfSecne[i] = 0;
    }
    numberOfEdge = 0;
    indexOfPath = 0;
    numberOfSecne1 = 0;
    findPath(G, begin, end);
    if (numberOfEdge <= 6) {
        //路径数小于6的情况
        numberOfEdge = 0;
        vector<int> path;//利用一个容器存放已走过的权值路径
        vector<int> k;//利用一个容器存放已走过的顶点
        ofstream ofs;
        ofs.open("screenPath.txt", ios::out);
        bool isvisited[100];
        int visitTime[100];
        for (int i = 0; i < 100; i++) {
            isvisited[i] = false;
            visitTime[i] = 0;
        }//初始化
        k.push_back(begin);//寻找从某点开始，到某一点end的所有路径
        isvisited[begin] = true;
        int now = begin;
        Edge* p = new Edge();
        p = G->nodes[now].edge;
        while (k.size() > 0) {
            p = G->nodes[now].edge;
            for (int i = 0; i < visitTime[now]; i++)
                p = p->next;
            if (!p) {
                isvisited[k.back()] = false;
                k.pop_back();
                visitTime[now] = 0;
                if (k.size() == 0)
                    break;
                path.pop_back();
                now = k.back();
                p = G->nodes[now].edge;
            }
            else if (!isvisited[p->getAdjvex()]) {
                indexOfPath = 0;
                path.push_back(p->getLength());
                visitTime[now]++;
                now = p->getAdjvex();
                isvisited[now] = true;
                k.push_back(now);
                if (now == end) {//如果寻找到了终点，判断路径信息
                    string s = "";
                    int numberOfAll = 0;
                    for (int i = 0; i < k.size() - 1; i++) {
                        s += (G->nodes[k[i]].getName() + " " + to_string(path[i]) + " ");
                        numberOfAll += path[i];
                    }
                    s += G->nodes[k[k.size() - 1]].getName();
                    numberOfSecne[indexOfPath] = k.size();

                    nameOfPath[indexOfPath] = s;
                    lengthOfPath[indexOfPath] = numberOfAll;
                    indexOfPath++;
                    //将名字和长度存到数组中，并将索引加1
                    isvisited[now] = false;
                    k.pop_back();
                    path.pop_back();
                    now = k.back();
                    numberOfEdge++;
                }
            }
            else visitTime[now]++;
        }

        for (int i = 0; i < numberOfEdge; i++) {
            for (int j = 0; j < numberOfEdge - i - 1; j++) {
                int min = lengthOfPath[i];
                string name = nameOfPath[i];
                int tempNumber = numberOfSecne[i];
                if (lengthOfPath[j] < lengthOfPath[j + 1]) {
                    lengthOfPath[j] = lengthOfPath[j + 1];
                    lengthOfPath[j + 1] = min;
                    nameOfPath[j] = nameOfPath[j + 1];
                    nameOfPath[j + 1] = name;
                    numberOfSecne[j] = numberOfSecne[j + 1];
                    numberOfSecne[j + 1] = tempNumber;
                }
            }
        }
        //对得到的路径进行从大到小的排序
        ofs << numberOfEdge << endl;
        for (int i = (numberOfEdge-1); i > 0; i--) {
            ofs << numberOfSecne[i] << " ";
            ofs << nameOfPath[i] << endl;
            //ofs << qstrTostr("总长为") << lengthOfPath[i] << endl;
        }
        ofs << numberOfSecne[0] << " ";
        ofs << nameOfPath[0];
        //逆向输出到文件中，从小到大

        ofs.close();
    }
    else {
        //路径数大于6的情况
        vector<int> path;//利用一个容器存放已走过的权值路径
        vector<int> k;//利用一个容器存放已走过的顶点
        ofstream ofs;
        ofs.open("screenPath.txt", ios::out);
        bool isvisited[100];
        int visitTime[100];
        for (int i = 0; i < 100; i++) {
            isvisited[i] = false;
            visitTime[i] = 0;
        }//初始化
        k.push_back(begin);//寻找从某点开始，到某一点end的所有路径
        isvisited[begin] = true;
        int now = begin;
        Edge* p = new Edge();
        p = G->nodes[now].edge;
        int cnt = 0;
        while (k.size() > 0) {
            if (cnt < 6) {
                //先存3条路径到数组中
                p = G->nodes[now].edge;
                for (int i = 0; i < visitTime[now]; i++)
                    p = p->next;
                if (!p) {
                    isvisited[k.back()] = false;
                    k.pop_back();
                    visitTime[now] = 0;
                    if (k.size() == 0)
                        break;
                    path.pop_back();
                    now = k.back();
                    p = G->nodes[now].edge;
                }
                else if (!isvisited[p->getAdjvex()]) {
                    path.push_back(p->getLength());
                    visitTime[now]++;
                    now = p->getAdjvex();
                    isvisited[now] = true;
                    k.push_back(now);
                    if (now == end) {//如果寻找到了终点，判断路径信息
                        string s = "";
                        int numberOfAll = 0;
                        for (int i = 0; i < k.size() - 1; i++) {
                            //ofs << mapOfScene[k[i]] << " " << path[i] << " ";
                            s += (G->nodes[k[i]].getName() + " " + to_string(path[i]) + " ");
                            numberOfAll += path[i];
                        }
                        s += G->nodes[k[k.size() - 1]].getName();
                        numberOfSecne[indexOfPath] = k.size();
                        nameOfPath[indexOfPath] = s;
                        lengthOfPath[indexOfPath] = numberOfAll;
                        indexOfPath++;
                        //将路径名和路径长度存到数组中并将索引加1
                        cnt++;
                        isvisited[now] = false;
                        k.pop_back();
                        path.pop_back();
                        now = k.back();
                        numberOfEdge++;
                    }
                }
                else visitTime[now]++;
                while (cnt == 6 && flag1) {
                    //当存了6条路径后进行从大到小的排序
                    for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 6 - i - 1; j++) {
                            int min = lengthOfPath[j];
                            string name;
                            name = nameOfPath[j];
                            int tempNumber = numberOfSecne[j];
                            if (lengthOfPath[j] < lengthOfPath[(j + 1)]) {
                                lengthOfPath[j] = lengthOfPath[(j + 1)];
                                lengthOfPath[(j + 1)] = min;
                                nameOfPath[j] = nameOfPath[(j + 1)];
                                nameOfPath[(j + 1)] = name;
                                numberOfSecne[j] = numberOfSecne[(j + 1)];
                                numberOfSecne[(j + 1)] = tempNumber;
                            }
                        }
                    }
                    flag1 = false;
                }
            }
            else {
                //继续读入剩下的路径
                p = G->nodes[now].edge;
                for (int i = 0; i < visitTime[now]; i++)
                    p = p->next;
                if (!p) {
                    isvisited[k.back()] = false;
                    k.pop_back();
                    visitTime[now] = 0;
                    if (k.size() == 0)
                        break;
                    path.pop_back();
                    now = k.back();
                    p = G->nodes[now].edge;
                }

                else if (!isvisited[p->getAdjvex()]) {
                    indexOfPath = 0;
                    path.push_back(p->getLength());
                    visitTime[now]++;
                    now = p->getAdjvex();
                    isvisited[now] = true;
                    k.push_back(now);
                    if (now == end) {//如果寻找到了终点，判断路径信息
                        string s = "";
                        int numberOfAll = 0;
                        for (int i = 0; i < k.size() - 1; i++) {
                            s += (G->nodes[k[i]].getName() + " " + to_string(path[i]) + " ");
                            numberOfAll += path[i];
                        }
                        s += G->nodes[k[k.size() - 1]].getName();
                        numberOfSecne1 = k.size();
                        if (numberOfAll <= lengthOfPath[5]) {
                            lengthOfPath[0] = lengthOfPath[1];
                            nameOfPath[0] = nameOfPath[1];
                            numberOfSecne[0] = numberOfSecne[1];
                            lengthOfPath[1] = lengthOfPath[2];
                            nameOfPath[1] = nameOfPath[2];
                            numberOfSecne[1] = numberOfSecne[2];
                            lengthOfPath[2] = lengthOfPath[3];
                            nameOfPath[2] = nameOfPath[3];
                            numberOfSecne[2] = numberOfSecne[3];
                            lengthOfPath[3] = lengthOfPath[4];
                            nameOfPath[3] = nameOfPath[4];
                            numberOfSecne[3] = numberOfSecne[4];
                            lengthOfPath[4] = lengthOfPath[5];
                            nameOfPath[4] = nameOfPath[5];
                            numberOfSecne[4] = numberOfSecne[5];
                            lengthOfPath[5] = numberOfAll;
                            nameOfPath[5] = s;
                            numberOfSecne[5] = numberOfSecne1;
                        }
                        else if (numberOfAll <= lengthOfPath[4] && numberOfAll > lengthOfPath[5]) {
                            lengthOfPath[0] = lengthOfPath[1];
                            nameOfPath[0] = nameOfPath[1];
                            numberOfSecne[0] = numberOfSecne[1];
                            lengthOfPath[1] = lengthOfPath[2];
                            nameOfPath[1] = nameOfPath[2];
                            numberOfSecne[1] = numberOfSecne[2];
                            lengthOfPath[2] = lengthOfPath[3];
                            nameOfPath[2] = nameOfPath[3];
                            numberOfSecne[2] = numberOfSecne[3];
                            lengthOfPath[3] = lengthOfPath[4];
                            nameOfPath[3] = nameOfPath[4];
                            numberOfSecne[3] = numberOfSecne[4];
                            lengthOfPath[4] = numberOfAll;
                            nameOfPath[4] = s;
                            numberOfSecne[4] = numberOfSecne1;
                        }
                        else if (numberOfAll <= lengthOfPath[3] && numberOfAll > lengthOfPath[4]) {
                            lengthOfPath[0] = lengthOfPath[1];
                            nameOfPath[0] = nameOfPath[1];
                            numberOfSecne[0] = numberOfSecne[1];
                            lengthOfPath[1] = lengthOfPath[2];
                            nameOfPath[1] = nameOfPath[2];
                            numberOfSecne[1] = numberOfSecne[2];
                            lengthOfPath[2] = lengthOfPath[3];
                            nameOfPath[2] = nameOfPath[3];
                            numberOfSecne[2] = numberOfSecne[3];
                            lengthOfPath[3] = numberOfAll;
                            nameOfPath[3] = s;
                            numberOfSecne[3] = numberOfSecne1;
                        }
                        else if (numberOfAll <= lengthOfPath[2] && numberOfAll > lengthOfPath[3]) {
                            lengthOfPath[0] = lengthOfPath[1];
                            nameOfPath[0] = nameOfPath[1];
                            numberOfSecne[0] = numberOfSecne[1];
                            lengthOfPath[1] = lengthOfPath[2];
                            nameOfPath[1] = nameOfPath[2];
                            numberOfSecne[1] = numberOfSecne[2];
                            lengthOfPath[2] = numberOfAll;
                            nameOfPath[2] = s;
                            numberOfSecne[2] = numberOfSecne1;
                        }
                        else if (numberOfAll <= lengthOfPath[1] && numberOfAll > lengthOfPath[2]) {
                            lengthOfPath[0] = lengthOfPath[1];
                            nameOfPath[0] = nameOfPath[1];
                            numberOfSecne[0] = numberOfSecne[1];
                            lengthOfPath[1] = numberOfAll;
                            nameOfPath[1] = s;
                            numberOfSecne[1] = numberOfSecne1;
                        }
                        else if (numberOfAll <= lengthOfPath[0] && numberOfAll > lengthOfPath[1]) {
                            lengthOfPath[0] = numberOfAll;
                            nameOfPath[0] = s;
                            numberOfSecne[0] = numberOfSecne1;
                        }
                        isvisited[now] = false;
                        k.pop_back();
                        path.pop_back();
                        now = k.back();
                        numberOfEdge++;
                    }
                }
                else visitTime[now]++;
            }
        }
        ofs << 6 << endl;
        for (int i = 5; i >0; i--) {
            ofs << numberOfSecne[i] << " ";
            ofs << nameOfPath[i] << endl;
           // ofs << qstrTostr("总长为") << lengthOfPath[i] << endl;
        }
        ofs << numberOfSecne[0] << " ";
        ofs << nameOfPath[0];
        //输出6条路径到文件中，从小到大
        ofs.close();
    }
}
//
int getIndex(string name,Graph *g)
{
    for(int i=0;i<g->nodes.size();i++)
    {
        if(name==g->nodes[i].getName())
            return i;
    }
    return -1;
}
//
QString strToqstr(const string str)
{
    return QString::fromLocal8Bit(str.data());
}
//
string qstrTostr(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}
