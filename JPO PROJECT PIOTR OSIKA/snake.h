#pragma once


class Snake {
private:
	int pos_X;
	int pos_Y;
	std::vector <std::tuple<int, int>> body;
	int speed;
	int length;
	std::string direction;
public:
	Snake(int x = 1, int y = 1, int s = 1,std::string dir = "none",int len = 1) : pos_X(x), pos_Y(y), speed(s), direction(dir), length(len) {};
	int get_posY();
	int get_posX();
	int get_len();
	void move();
	void set_dir(std::string dir);
	std::string get_dir();
	bool food_eaten(int foodX,int foodY);
	void grow();
	void reset();
	
	std::vector <std::tuple<int, int>> get_body();

	
};
