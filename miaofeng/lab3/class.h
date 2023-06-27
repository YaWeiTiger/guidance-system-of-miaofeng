#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stack>
#include<map>
#include<QString>

#define NUMOFSCENE 44
using namespace std;
//边
class Edge {
private:
	int adjvex;
	int length;
	bool isOpen;
public:
	Edge* next = nullptr;
	int getAdjvex();
	int getLength();
	bool getIsOpen();
	void setAdjvex(int adjvex);
	void setLength(int length);
	void setIsOpen(bool isOpen);
};
//结点（景点）
class Node {
private:
	string name;
	int touristsNumber;
	bool isOpen;
	int rank;
	int x, y;
	
public:
	Edge* edge = nullptr;
	string getName();
	int getTouristsNumber();
	bool getIsOpen();
	int getRank();
	int getX();
	int getY();
	void setName(string name);
	void setTouristsNumber(int touristsNumber);
	void setIsOpen(bool isOpen);
	void setRank(int rank);
	void setX(int x);
	void setY(int y);
};
//景区图结构
class Graph {
public:
	std::vector<Node> nodes{};
	Graph();
};
//路径结构
class Path
{
public:
    vector<string> names={};
    vector<int> pathLen={};
    //int length=0;
    Path();
    ~Path();
};







