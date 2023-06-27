#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stack>
#include<QString>
#include<QDebug>
#include<QMouseEvent>
#include "class.h"
#include"algorithm.h"
using namespace std;
extern Path p;
extern Graph *G;


int Edge::getAdjvex() {
	return adjvex;
}
int Edge::getLength() {
	return length;
}
bool Edge::getIsOpen() {
	return isOpen;
}
void Edge::setAdjvex(int adjvex) {
	this->adjvex = adjvex;
}
void Edge::setLength(int length) {
	this->length = length;
}
void Edge::setIsOpen(bool isOpen) {
	this->isOpen = isOpen;
}


string Node::getName() {
	return name;
}
int Node::getTouristsNumber() {
	return touristsNumber;
}
bool Node::getIsOpen() {
	return isOpen;
}
int Node::getRank() {
	return rank;
}
int Node::getX() {
	return x;
}
int Node::getY() {
	return y;
}
void Node::setName(string name) {
	this->name = name;
}
void Node::setTouristsNumber(int touristsNumber) {
	this->touristsNumber = touristsNumber;
}
void Node::setIsOpen(bool isOpen) {
	this->isOpen = isOpen;
}
void Node::setRank(int rank) {
	this->rank = rank;
}
void Node::setX(int x) {
	this->x = x;
}
void Node::setY(int y) {
	this->y = y;
}


Graph::Graph() {

}


Path::Path()
{

}
Path::~Path()
{

}

