#pragma once

class Food{
private:
	int pos_X;
	int pos_Y;
public:
	Food();
	int get_posY();
	int get_posX();
	void update_positon();
};