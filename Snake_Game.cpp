#include <ncurses.h>
#include<iostream>
#include "Board.hpp"

using namespace std;

class Item : public Node {
public:
	Item(pair<int, int> p, char ch) { set_defult(p, ch); }
	void set_position(pair<int, int> position);
	pair<int, int> get_position();
	char get_shape();
};
void Item::set_position(pair<int, int> p) {
	position = p;
}
pair<int, int> Item::get_position() {
	return position;
}
char Item::get_shape() {
	return shape;
}

#define DefultSize 17

class Game {
	const int Row, Col;
	Board board;
	Snake snake;
	Node* green = NULL, * red = NULL;
	bool is_over = false;
	// add  gate 
public:
	Game(int row, int col) : Row(row), Col(col), board(row, col){}
	void update_Game();
	void play_Game();
	int is_Over();
};
void Game :: play_Game() {
	keypad(stdscr, true);
	noecho();
	int control = getch();
	// 이전 움직임 과 반대 되는 움직임 불가 (추가)
	snake.set_forward(control);
	snake.move();
	pair<int,int> head_position = snake.head();
	//event
	if (green->get_shape = board.get_shape(snake_head()))
		snake.push(),delete green , green = NULL; //update score
	else if (red->get_shape() == board.get_shape(snake_head()))
		snake.pop(),delete red, red = NULL;
	//GATE 추가
	

	// 승,패
	//벽에 박았는지 추가 -> 패 

	// snake.get_length() > = 8 -> 승

	// snake.get_length() < 2 -> 패
}

void Game::update_Game() {
	board.init_board();
	if (green == NULL) {
		int row, col;
		board.find_target(row, col,' ');
		green = new Item({row, col}, 'G');
	}
	board.add_node(green);
	if (red == NULL) {
		int row, col;
		board.find_target(row, col,' ');
		red = new Item({ row, col }, 'R');
	}
	board.add_node(red);
	// gate 추가하기


	list<Snake_Node*>::iterator iter = snake.begin();
	list<Snake_Node*>::iterator end = snake.end();
	for (iter ; iter!=end; iter++) {
		board.add_node(*iter);
	}
	board.refresh();

}

int Game::is_Over() {
	return false;
}

int main(){

	initscr();
	refresh();


	Game game(DefultSize, DefultSize);
	game.update_Game();
	
	while (!game.is_Over()) {
		// score 보드 추가
		game.play_Game();
		game.update_Game();
	}
	endwin();

	return 0;
}
