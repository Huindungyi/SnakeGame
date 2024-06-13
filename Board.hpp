#pragma once

#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Snake.hpp"

using namespace std;



class Board {
private:
	const int Row, Col; //높이,너비 최대값
	void make_border();
	WINDOW* board_win;
public:
	Board(int row = 21, int col = 21);
	void add_node(Node* node);
	char get_shape(int x, int y) const;
	void find_target(int& row, int& col , char target);
	void refresh();
	void init_board();
	void clear();
};
Board::Board(int row, int col) :Row(row), Col(col) {
	int xmax, ymax;
	getmaxyx(stdscr, xmax, ymax);

	board_win = newwin(row, col,0 ,0);

	init_board();
}
void Board::init_board() {// 맵 초기화
	clear();
	refresh();
}
void Board::make_border() {
	wborder(board_win, '□', '□', '□', '□', '■', '■', '■', '■');
	// 추가 wall 생성 -> level 마다 갱신
}
char Board::get_shape(pair<int ,int > p) const {
	return mvwinch(board_win, p.first, p.second);
}
void Board:: find_target(int& row, int& col , char target) {
	srand(time(NULL));
	while (get_shape(row = rand() % Row, col = rand() % Col) != target);
}
void Board::add_node(Node* node) {
	pair<int, int> p = node->get_position();
	char ch = node->get_shape();
	mvwaddch(board_win,p.first, p.second, ch);
}
void Board::refresh() {
	wrefresh(board_win);
}
void Board::clear() {
	wclear(board_win);
	make_border();
}
