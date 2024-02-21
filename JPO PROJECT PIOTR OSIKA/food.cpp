#include "main.h"


int Food::get_posY() {
	return pos_Y;
}
int Food::get_posX() {
	return pos_X;
};
Food::Food() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> rand_width(0, BOARD_WIDTH - 1);
	std::uniform_int_distribution<int> rand_height(1, BOARD_HEIGHT);

	pos_X = rand_width(mt);
	pos_Y = rand_height(mt);
};
void Food:: update_positon() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> rand_width(0, BOARD_WIDTH - 1);
	std::uniform_int_distribution<int> rand_height(1, BOARD_HEIGHT);

	pos_X = rand_width(mt);
	pos_Y = rand_height(mt);
}
