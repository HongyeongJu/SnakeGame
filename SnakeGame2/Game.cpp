#include "Game.h"

Game::Game()
{
	// 소리 재생
	appleSound = new Sound("appleSound.wav");
	
	// 초기 설정을 해준다.
	init();
}

void Game::init()
{
	// 맵을 초기화한다.
	mapInit();

	// 점수 초기화
	score = 0;

	if (snake == nullptr) {
		// 뱀의 객체를 생성
		snake = new Snake(map, MAPSIZE);
	}
	else {
		delete snake;
		snake = new Snake(map, MAPSIZE);
	}

	// 뱀의 위치를 설정
	snake->setPosition(5, 5);
	// 뱀의 방향을 설정
	snake->setDirection(Direction::LEFT);

	// 사과 랜덤 생성
	makeApple();
}

// 소멸자
Game::~Game() {
	delete snake;
	for (int i = 0; i < MAPSIZE; i++) {
		delete[] map[i];
	}
	delete[] map;
	delete appleSound;
	delete appleSoundThread;
}

// 맵을 초기화 하는 함수
void Game::mapInit() {
	// 만약 맵이 원래 있더라면
	if (map != nullptr) {
		for (int i = 0; i < MAPSIZE; i++) {
			delete[] map[i];
		}
		delete[] map;
	}

	// 맵 초기화
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

// update 함수 
// 객체의 움직임을 설정함 
void Game::update() {
	// 키보드 입력 처리
	inputKeyBoard();
	// 뱀의 움직임
	snake->move();
}

// 출력전 객체 맵 적용 함수
void Game::beforePrint() {
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			// 맵에서 BLOCK이랑 APPLE이 아니라면, 초기화 시키기
			if (map[i][j] != Object::BLOCK && map[i][j] != Object::APPLE) {
				map[i][j] = Object::BLANK;

				// 뱀 객체의 x, y 값을 얻어내기
				int snakeX = snake->getX();
				int snakeY = snake->getY();

				map[snakeY][snakeX] = Object::HEAD;

				// 꼬리들을 반영하기
				for (auto i : snake->tails) {
					int tailX = i.first;
					int tailY = i.second;
					map[tailY][tailX] = Object::SNAKE;
				}
				
			}
		}
	}
}

// 충돌처리 함수
int Game::collision() {
	// 결과값 반환
	int result = MODE::GAME;
	
	// 뱀의 머리가 사과 or 벽 or 자기 자신과 부딪혔을 경우 이벤트 발생
	int snakeX = snake->getX();
	int snakeY = snake->getY();

	// 현재 뱀의 좌표가 있는 곳에 사과가 있는 경우
	switch (map[snakeY][snakeX]) {
	case Object::APPLE :
		// 점수 증가
		improveScore();
		// TO DO : 효과음 발생
		appleSoundThread = new std::thread(&Sound::play, appleSound, false);
		//appleSound->play(false);
		// 사과 생성
		makeApple();
		break;
	// 빈칸이나 머리인 경우에는 아무런 조치를 취하지 않는다.
	case Object::BLANK :
		
		// 뱀의 꼬리를 자르기
		snake->cutTail();
		break;
	case Object::HEAD :
		break;

	default :
		// 게임 패배 
		result = MODE::GAMEOVER;

		// TO DO: 패배 효과음 발생
		break;
	}

	return result;
}

// 키보드 입력처리 함수
void Game::inputKeyBoard() {
	// 키보드 입력 처리 함수
	if (KeyBoard::input1 == 224) {
		switch (KeyBoard::input2) {
		case 72: snake->setDirection(Direction::UP); break;
		case 80: snake->setDirection(Direction::DOWN); break;
		case 75: snake->setDirection(Direction::LEFT); break;
		case 77: snake->setDirection(Direction::RIGHT); break;
		}
	}
}

// 사과 랜덤 생성함수
void Game::makeApple() {
	// 랜덤 초기화 
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

// 점수 셋터 함수
void Game::setScore(int score) {
	this->score = score;
}

// 점수 겟터 함수
int Game::getScore() {
	return score;
}

// 점수 상승 함수
void Game::improveScore() {
	score += 10;
}

// 화면 출력
void Game::print() {
	// BLANK는 빈칸, BLOCK은 흰색 네모, SNAKE는 빈칸 동그라미, HEAD는 채워져있는 동그라미, APPLE은 별
	for (int i = 0; i < MAPSIZE; i++) {
		for (int j = 0; j < MAPSIZE; j++) {
			if (map[i][j] == Object::BLANK) {
				printf("  ");
			}
			else if (map[i][j] == Object::BLOCK) {
				printf("■");
			}
			else if (map[i][j] == Object::SNAKE) {
				TextColor::changeText_SomeColor(TextColor::GREEN);
				printf("○");
				TextColor::changeText_White();
			}
			else if (map[i][j] == Object::HEAD) {
				TextColor::changeText_SomeColor(TextColor::GREEN);
				printf("●");
				TextColor::changeText_White();
			}
			else if (map[i][j] == Object::APPLE) {
				TextColor::changeText_SomeColor(TextColor::RED);
				printf("★");
				TextColor::changeText_White();
			}
		}
		printf("\n");
	}

	printf("Score :  %5d", score);
}