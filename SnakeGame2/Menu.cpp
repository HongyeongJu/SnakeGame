#include "Menu.h"

void Menu::print()
{
	TextColor::changeText_White();
	printf("===========================================\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("|               "); TextColor::changeText_SomeColor(colors[text_color_cnt]); printf("SNAKE GAME"); TextColor::changeText_White(); printf("                |\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("|               "); TextColor::changeText_SomeColor(colors[text_color_cnt]); printf("1. GAME START"); TextColor::changeText_White();  printf("             |\n");
	printf("|               "); TextColor::changeText_SomeColor(colors[text_color_cnt]); printf("2. RANKING"); TextColor::changeText_White(); printf("                |\n");
	printf("|               "); TextColor::changeText_SomeColor(colors[text_color_cnt]); printf("3. EXIT"); TextColor::changeText_White(); printf("                   |\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("|               "); TextColor::changeText_SomeColor(colors[text_color_cnt]); printf("MADE BY HONG"); TextColor::changeText_White(); printf("              |\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("===========================================\n");
}

int Menu::select()
{
	MENU_INPUT input = MENU_INPUT::NOTHING;
	if (KeyBoard::input1 == '1') {
		input = MENU_INPUT::GAME_START;
	}
	else if (KeyBoard::input1 == '2') {
		input = MENU_INPUT::RANKING;
	}
	else if (KeyBoard::input1 == '3') {
		input = MENU_INPUT::EXIT;
	}

	return input;
}

void Menu::improve_color_cnt()
{
	text_color_cnt = (text_color_cnt + 1) % 3;
}
