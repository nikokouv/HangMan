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
	do {
		//TODO Print the GUI and refresh it
		NewGame.SubmitGuess();
		if (NewGame.GameIsWon()){
			//TODO Add Game winning message etc
			break;
		}
	} while (NewGame.getNumOfTries() < NewGame.getMaxTries());
}

