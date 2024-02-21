#include "main.h"


bool Game::state() {
	return game_state;
}

void Game::set_state(bool state) {
	game_state =state;
}
int Game::get_score() {
	return score*10;
}
void Game::add_score() {
	score++;
}
void Game::reset_score() {
	score = 0;

}

void Game::draw(Snake snake, Food &food) {

	std::vector<std::tuple<int, int>> positions = snake.get_body();

	for (int i = 0; i < height + 2; i++) {
		std::cout << "%";
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height + 1) {
				std::cout << "%";
			}
			else if (j == snake.get_posX() && i == snake.get_posY()) { std::cout << "O"; }
			else if (j == food.get_posX() && i == food.get_posY()) { std::cout << "@"; }
			else {
				bool isBodyPart = false;
				for (size_t idx = 0; idx < positions.size(); idx++) {
					if (j == std::get<0>(positions[idx]) && i  == std::get<1>(positions[idx])) {
						std::cout << "o";
						isBodyPart = true;
						break;
					}
				}
				if (!isBodyPart) { std::cout << " "; }
			}
		}
			std::cout << "%\n";
		
	}
	};

void Game::logic(Snake snake, Food &food) {
	std::vector<std::tuple<int, int>> positions = snake.get_body();

	if (snake.get_posY() == 0 || snake.get_posX() == -1 || snake.get_posY() == height + 1 || snake.get_posX() == width) {
		system("CLS");
		game_state = false;
	}

	for (size_t idx = 0; idx < positions.size()-1; idx++) {
		if (snake.get_posX() == std::get<0>(positions[idx]) && snake.get_posY() == std::get<1>(positions[idx])) {
			system("CLS");
			game_state = false;
		}
	}
}






