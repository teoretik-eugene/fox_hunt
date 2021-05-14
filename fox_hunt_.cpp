#include <iostream>

class Coord {
public:
	int x_;
	int y_;

	Coord() {
		std::cout << "h";
		x_ = 0;
		y_ = 0;
	}
};

class Board {
public:
	Coord** board = new Coord[10];
	Board() {
		for (int j = 0; j < 10; j++) {
			board[j] = new Coord[10];
		}
	}
};

int main() {
	Board b1;

	return 0;
}