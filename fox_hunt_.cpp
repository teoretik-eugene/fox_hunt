#include <iostream>

/* Класс координаты на поле */
class Coord {
public:
	int x_;
	int y_;
	int fox_count;

	Coord() {
		//std::cout << "h";
		x_ = 0;
		y_ = 0;
		fox_count = 0;
	}
	/* Получить координату */
	void get_coord() {
		std::cout << x_ << ' ' << y_;
	}
	/* Получить количество лис в этой координате */
	void get_fox() {
		std::cout << fox_count;
	}
};

/* Класс игрового поля, который состоит из матрицы-объектов координат */
class Board {
public:
	/* Создание матрицы - поля */
	Coord **board = new Coord* [10];
	Board() {
		for (int j = 0; j < 10; j++) {
			board[j] = new Coord[10];
		}
		/* Вводим координаты */
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				board[i][j].x_ = i;
				board[i][j].y_ = j;
			}
		}
	}	
};

/* Реализация игры */
class Game {
public:
	Board* brd;
	Game(Board* ptr) {
		brd = ptr;
		/* Заполним рандомно лисичками */
		int foxes = 8;
		while (foxes > 0) {
			int x = rand() % 10;	// В данном случае rand дает нам повторный результат
			int y = rand() % 10;	// поэтому я его тут использовал
			brd->board[x][y].fox_count++;
			std::cout << "rand: " << x<<' '<< y << std::endl;
			// Эти "рандомные" координаты служат подсказкой, гдк спрятаны лисы
			foxes--;
		}

		bool isFinish = false;
		int fox_num = 0;
		std::cout << "Enter coordinates [0-9]" << std::endl;
		while (!isFinish) {
			int fox_middle = 0;		// Количество лис в выбранной координате
			int x_in, y_in;
			std::cout << "Enter X: ";
			std::cin >> x_in;
			std::cout << "Enter Y: ";
			std::cin >> y_in;
			fox_middle = CheckFox(x_in, y_in, brd);
			std::cout << "Fox count is: " << fox_middle << std::endl;
			fox_num = fox_num + fox_middle;		// Общее количество найденных лис
			if (fox_num == 8) {
				std::cout << "All foxes have been founded" << std::endl;
				isFinish = true;
			}
		}
	}
	/* Функция проверка лис в заданной координате */
	int CheckFox(int x, int y, Board *ptr) {
		int x_new = x; int y_new = y;	// Координаты выбранного положения
		int fox = 0;		// Общее количество лис

		//Проверка правой стороны
		while (x_new < 10) {
			fox = fox + ptr->board[x_new][y_new].fox_count;		// Суммируем всех лис
			ptr->board[x_new][y_new].fox_count = 0;			// Обнуляем, т.к. нашли
			x_new++;
		}
		x_new = x;	y_new = y;
		//Проверка по левой стороне
		while (x_new >= 0) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			x_new--;
		}
		x_new = x; y_new = y;
		//Проверка вертикально вверх
		while (y_new < 10) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			y_new++;
		}
		x_new = x; y_new = y;
		//Проверка вертикально вниз
		while (y_new >=0 ) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			y_new--;
		}
		x_new = x; y_new = y;
		//Проверка по диагонали вправо-вверх
		while (x_new < 10 && y_new < 10) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			x_new++; y_new++;
		}
		x_new = x; y_new = y;
		//Проверка по диагонали влево-вверх
		while (x_new >=0 && y_new < 10) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			x_new--; y_new++;
		}
		x_new = x; y_new = y;
		//Проверка по диагонали вправо-вниз
		while (x_new <10 && y_new >= 0) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			x_new++; y_new--;
		}
		x_new = x; y_new = y;
		//Проверка по диагонали влево-вниз
		while (x_new >= 0 && y_new >= 0) {
			fox = fox + ptr->board[x_new][y_new].fox_count;
			ptr->board[x_new][y_new].fox_count = 0;
			x_new--; y_new--;
		}
		return fox;
	}
};

int main() {
	Board *board = new Board;		// Создание поля	
	Game gm(board);			// Начало игры
	return 0;
}
