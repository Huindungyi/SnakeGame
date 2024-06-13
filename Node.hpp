#pragma once

#include <ncurses.h>
using namespace std;

class Node{
protected:
	pair<int, int> position = {0,0};
	char shape = '\0';
public:
	virtual ~Node(){}
	void set_defult(pair<int, int> p, char ch);
	virtual void set_position(pair<int,int> p);
	virtual pair<int,int> get_position();
	virtual char get_shape();
};

void Node::set_defult(pair<int,int> p, char ch) {
	position = p;
	shape = ch;
}
void Node::set_position(pair<int,int> p) {
	position = p;
}
pair<int,int> Node::get_position() {
	return position;
}
char Node::get_shape() {
	return shape;
}
