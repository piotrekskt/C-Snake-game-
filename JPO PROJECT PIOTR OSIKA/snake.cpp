#include "main.h"


int Snake::get_posY() {
	return pos_Y;
}

int Snake::get_posX() {
	return pos_X;
}

int Snake::get_len() {
	return length;
}

void Snake::set_dir(std::string dir) {
	direction = dir;
}
std::string Snake::get_dir() {
	return direction;
}

void Snake::move() {
	if (direction == "right") {
		pos_X += speed;
	}
	else if (direction == "down") {
		pos_Y += speed;
	}
	else if (direction == "left") {
		pos_X -= speed;
	}
	else if (direction == "up") {
		pos_Y -= speed;
	}
	body.emplace_back(pos_X, pos_Y);
	if (body.size() > length ) {
		body.erase(body.begin());
	}
	Sleep(115);
}

bool Snake::food_eaten(int foodX, int foodY) {
	if (pos_X == foodX && pos_Y == foodY) { return true; }
	else { return false; }
}

void Snake::grow() {
	length++;
}

std::vector <std::tuple<int, int>> Snake::get_body() {
	return body;
}

void Snake::reset() {
	pos_Y = BOARD_HEIGHT / 2; 
	pos_X = BOARD_WIDTH / 2;
	length = 1;
	body.clear();
	direction = "none";
}
