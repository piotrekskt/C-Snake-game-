#include "main.h"

void logo() {
	std::cout << "=========  ===      ==        ==        ==    ==  =======" << std::endl;
	std::cout << "==         == =     ==       =  =       ==   =    ==     " << std::endl;
	std::cout << "==         ==  =    ==      =    =      ==  =     ==     " << std::endl;
	std::cout << "=========  ==   =   ==     =      =     ====      =====  " << std::endl;
	std::cout << "       ==  ==    =  ==    ==========    ==  =     ==     " << std::endl;
	std::cout << "       ==  ==     = ==   =          =   ==   =    ==     " << std::endl;
	std::cout << "=========  ==      ===  ==          ==  ==    ==  =======" << std::endl;
	std::cout << "by Piotr Osika\n";
	std::cout << "\n ENTER to start the game";
	std::cout << "\n EXIT to exit";
	std::cout << "\n";
	std::cout << "\n Scores:\n";

}
void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // Ustawia widocznoœæ kursora

	SetConsoleCursorInfo(out, &cursorInfo);
}


int main(void) {

	ShowConsoleCursor(false);

	std::string name;
	std::vector<std::pair<std::string, int>> table;
	Game board(BOARD_WIDTH, BOARD_HEIGHT);
	Snake player(BOARD_WIDTH / 2, BOARD_HEIGHT / 2);
	Food* apple = new Food();

	while (true) {

		logo();
		for (const auto& pair : table) {
			std::cout << "	" << pair.first << ": " << pair.second << std::endl;
		}
		if (table.size() == 0) {
			std::cout << "" << std::endl;
			std::cout <<"  Play to make it to the leaderboard! :)" << std::endl;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		
		if (_kbhit()) {
			switch (_getch()) {
			case 13: 
				player.reset();
				board.set_state(true);
				board.reset_score();
				system("CLS");
				break; 
			case 27:
				exit(1);
			}
		}
		
		

		while (board.state()) {

			board.draw(player, *apple);
			player.move();
			board.logic(player, *apple);

			if (player.food_eaten(apple->get_posX(), apple->get_posY())) {
				board.add_score();
				player.grow();
				apple->update_positon();
			}

			if (_kbhit()) {
				switch (_getch()) {
				case 'd':
					if (player.get_dir() != "left") {
						player.set_dir("right");
					}
					break;
				case 'w':
					if (player.get_dir() != "down") {
						player.set_dir("up");
					}
					break;
				case 's':
					if (player.get_dir() != "up") {
						player.set_dir("down");
					}
					break;
				case 'a':
					if (player.get_dir() != "right") {
						player.set_dir("left");
					}
					break;
				case 27:
					system("CLS");
					board.set_state(0);
				}
			}

			std::cout << std::endl;
			std::cout << "Score: " << board.get_score();
			
			if (!board.state()) {
				std::cout << "\nGame over!\n";
				Sleep(1500);
				
					if (board.get_score() > 0) {
						ShowConsoleCursor(true);
						std::cout << "\nType your name to save your score: ";
						std::cin >> name;
						ShowConsoleCursor(false);
						table.push_back(std::make_pair(name, board.get_score()));
						std::sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs) {
							return lhs.second > rhs.second;
							});
					}
				}
			

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		}
	}
	ShowConsoleCursor(true);
	
}

