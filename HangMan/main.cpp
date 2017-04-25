#include <iostream>
#include <string>
#include "Game.h"

//Global Variables
std::string word = "patty";

//Function Declaration
void GameRoutine();
void PrintIntro();

//Main Routine
int main() {
	bool PlayGameFlag = false;
	do {
		PrintIntro();
		GameRoutine();
	} while (PlayGameFlag);
	return 0;
}

//Function Definition
void PrintIntro()
{
	std::cout << "Welcome to HangMan! \n";
	std::cout << "In this game there's a hidden word and you have limited tries to guess it! \nAre you ready to take the challenge?\n";
	//system("pause"); //TODO
	std::cout << "Can you guess the " << word.length() << " letter word?";
	std::cout << std::endl;
	//TODO Print the Actual HangMan in ASCII
}

void GameRoutine()
{
	using namespace std;
	Game NewGame;
	cout << "Hidden Word: " << NewGame.getHiddenWord() << endl;
	cout << "Num of tries: " << NewGame.getNumOfTries() << endl;
	cout << "Max tries: " << NewGame.getMaxTries() << endl;
	for (int i = 0; i < 26; i++) {
		cout << "No." << i << " = " << NewGame.getValidLetter(i) << " (" << char(97+i) << ")" << endl;
	}
}

