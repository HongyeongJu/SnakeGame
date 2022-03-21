#include "Game.h"

Game::Game()
{
	// �Ҹ� ���
	appleSound = new Sound("appleSound.wav");
	
	// �ʱ� ������ ���ش�.
	init();
}

void Game::init()
{
	// ���� �ʱ�ȭ�Ѵ�.
	mapInit();

	// ���� �ʱ�ȭ
	score = 0;

	if (snake == nullptr) {
		// ���� ��ü�� ����
		snake = new Snake(map, MAPSIZE);
	}
	else {
		delete snake;
		snake = new Snake(map, MAPSIZE);
	}

	// ���� ��ġ�� ����
	snake->setPosition(5, 5);
	// ���� ������ ����
	snake->setDirection(Direction::LEFT);

	// ��� ���� ����
	makeApple();
}

// �Ҹ���
Game::~Game() {
	delete snake;
	for (int i = 0; i < MAPSIZE; i++) {
		delete[] map[i];
	}
	delete[] map;
	delete appleSound;
	delete appleSoundThread;
}

// ���� �ʱ�ȭ �ϴ� �Լ�
void Game::mapInit() {
	// ���� ���� ���� �ִ����
	if (map != nullptr) {
		for (int i = 0; i < MAPSIZE; i++) {
			delete[] map[i];
		}
		delete[] map;
	}

	// �� �ʱ�ȭ
	map = new int* [MAPSIZE];
	for (int i = 0; i < MAPSIZE; i++) {
		map[i] = new int[MAPSIZE];
	}
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			map[i][j] = Object::BLANK;
		}
	}

	for (int i = 0; i < MAPSIZE; i++) {
		map[i][0] = Object::BLOCK;
		map[i][MAPSIZE - 1] = Object::BLOCK;
		map[0][i] = Object::BLOCK;
		map[MAPSIZE - 1][i] = Object::BLOCK;
	}
}

// update �Լ� 
// ��ü�� �������� ������ 
void Game::update() {
	// Ű���� �Է� ó��
	inputKeyBoard();
	// ���� ������
	snake->move();
}

// ����� ��ü �� ���� �Լ�
void Game::beforePrint() {
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			// �ʿ��� BLOCK�̶� APPLE�� �ƴ϶��, �ʱ�ȭ ��Ű��
			if (map[i][j] != Object::BLOCK && map[i][j] != Object::APPLE) {
				map[i][j] = Object::BLANK;

				// �� ��ü�� x, y ���� ����
				int snakeX = snake->getX();
				int snakeY = snake->getY();

				map[snakeY][snakeX] = Object::HEAD;

				// �������� �ݿ��ϱ�
				for (auto i : snake->tails) {
					int tailX = i.first;
					int tailY = i.second;
					map[tailY][tailX] = Object::SNAKE;
				}
				
			}
		}
	}
}

// �浹ó�� �Լ�
int Game::collision() {
	// ����� ��ȯ
	int result = MODE::GAME;
	
	// ���� �Ӹ��� ��� or �� or �ڱ� �ڽŰ� �ε����� ��� �̺�Ʈ �߻�
	int snakeX = snake->getX();
	int snakeY = snake->getY();

	// ���� ���� ��ǥ�� �ִ� ���� ����� �ִ� ���
	switch (map[snakeY][snakeX]) {
	case Object::APPLE :
		// ���� ����
		improveScore();
		// TO DO : ȿ���� �߻�
		appleSoundThread = new std::thread(&Sound::play, appleSound, false);
		//appleSound->play(false);
		// ��� ����
		makeApple();
		break;
	// ��ĭ�̳� �Ӹ��� ��쿡�� �ƹ��� ��ġ�� ������ �ʴ´�.
	case Object::BLANK :
		
		// ���� ������ �ڸ���
		snake->cutTail();
		break;
	case Object::HEAD :
		break;

	default :
		// ���� �й� 
		result = MODE::GAMEOVER;

		// TO DO: �й� ȿ���� �߻�
		break;
	}

	return result;
}

// Ű���� �Է�ó�� �Լ�
void Game::inputKeyBoard() {
	// Ű���� �Է� ó�� �Լ�
	if (KeyBoard::input1 == 224) {
		switch (KeyBoard::input2) {
		case 72: snake->setDirection(Direction::UP); break;
		case 80: snake->setDirection(Direction::DOWN); break;
		case 75: snake->setDirection(Direction::LEFT); break;
		case 77: snake->setDirection(Direction::RIGHT); break;
		}
	}
}

// ��� ���� �����Լ�
void Game::makeApple() {
	// ���� �ʱ�ȭ 
	srand((unsigned int)time(NULL));
	bool isOkay = false;

	while (!isOkay) {
		int appleX = ((int)rand()) % MAPSIZE;
		int appleY = ((int)rand()) % MAPSIZE;

		if (map[appleY][appleX] == Object::BLANK) {
			map[appleY][appleX] = Object::APPLE;
			isOkay = true;
		}
	}
	
}

// ���� ���� �Լ�
void Game::setScore(int score) {
	this->score = score;
}

// ���� ���� �Լ�
int Game::getScore() {
	return score;
}

// ���� ��� �Լ�
void Game::improveScore() {
	score += 10;
}

// ȭ�� ���
void Game::print() {
	// BLANK�� ��ĭ, BLOCK�� ��� �׸�, SNAKE�� ��ĭ ���׶��, HEAD�� ä�����ִ� ���׶��, APPLE�� ��
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			if (map[i][j] == Object::BLANK) {
				printf("  ");
			}
			else if (map[i][j] == Object::BLOCK) {
				printf("��");
			}
			else if (map[i][j] == Object::SNAKE) {
				TextColor::changeText_SomeColor(TextColor::GREEN);
				printf("��");
				TextColor::changeText_White();
			}
			else if (map[i][j] == Object::HEAD) {
				TextColor::changeText_SomeColor(TextColor::GREEN);
				printf("��");
				TextColor::changeText_White();
			}
			else if (map[i][j] == Object::APPLE) {
				TextColor::changeText_SomeColor(TextColor::RED);
				printf("��");
				TextColor::changeText_White();
			}
		}
		printf("\n");
	}

	printf("Score :  %5d", score);
}