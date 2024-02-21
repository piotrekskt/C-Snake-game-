#pragma once

class Game {
private:
	int width;
	int height;
	int score = 0;
	bool game_state = false;

public:
	Game(int x = 10, int y = 10) : width(x), height(y) {};
	void draw(Snake snake, Food &food);
	void logic(Snake snake, Food &food);
	bool state();
	void set_state(bool state);
	int get_score();
	void reset_score();
	void add_score();
	
};