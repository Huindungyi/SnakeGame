#pragma once

#include<iostream>
#include<ncurses.h>
#include<list>
#include "Node.hpp"

using namespace std;

#define BODY '+'
#define HEAD '*'

class Snake_Node :public Node {
public:
	Snake_Node(pair<int, int> p, char ch) { set_defult(p, ch); }
	~Snake_Node() {}
	void set_position(pair<int, int> position);
	void set_shape(char ch);
	pair<int, int> get_position();
	char get_shape();
};

void Snake_Node::set_position(pair<int, int> p) {
	position = p;
}
void Snake_Node::set_shape(char ch) {
	shape = ch;
}
pair<int, int> Snake_Node::get_position() {
	return position;
}
char Snake_Node::get_shape() {
	return shape;
}



class Snake {
	list<Snake_Node*> snake_body;
	pair<int, int> position = { 3,3 };
	
public:
	Snake();
	~Snake() {}
	void push(); 
	void pop(); 
	void set_forward(int direct); 
	pair<int, int> head(); // 머리위치
	list<Snake_Node*>::iterator begin();
	list<Snake_Node*>::iterator end();
	void move(); //움직임
	int get_length(); // 길이 구하기
};
Snake::Snake(){
	snake_body.push_back(new Snake_Node(position, HEAD));
	for (int i = 0; i < 2; i++) {
		set_forward(KEY_LEFT);
		push();
	}
}
void Snake::push() {
	snake_body.back()->set_shape(BODY);
	snake_body.push_back(new Snake_Node(position, HEAD));
}
void Snake::pop() {
	delete snake_body.front();
	snake_body.pop_front();
}

void Snake::move() {
	push();
	pop();
}

void Snake::set_forward(int direct) {
	switch (direct) {
	case KEY_UP:
		position.first--;
		break;
	case KEY_DOWN:
		position.first++;
		break;
	case KEY_LEFT:
		position.second--;
		break;
	case KEY_RIGHT:
		position.second++;
		break;
	}
}
pair<int, int>  Snake:: head() {
	return position;
}
list<Snake_Node*>::iterator Snake::begin() {
	return snake_body.begin();
}
list<Snake_Node*>::iterator Snake::end() {
	return snake_body.end();
}

int Snake::get_length() { // 길이 구하기
	return snake_body.size();
}