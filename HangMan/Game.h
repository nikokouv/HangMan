#pragma once

#include <string>
#include <iostream>
#define FWord std::string
#define FLetter char
#define DEFAULT_HIDDEN_WORD "patty";

enum class LetterStatus {
	ALREADY_SUBMITTED,
	NOT_FOUND,
	FOUND,
	NOT_OK
};

class Game
{
public:
	Game();
	void Reset();
	FWord getHiddenWord() const;
	int getNumOfTries() const;
	int getMaxTries() const;
	int getWordLength() const;
	void SubmitGuess();
	LetterStatus CheckGuessValidity(FLetter);
	void SetValidLetter();
	int getValidLetter(int) const;
	bool GameIsWon() const;
	int getGameProgress() const;
private:
	FWord HiddenWord;
	int ValidLetter[26] = {0};
	int NumberOfTries = 0;
	int MaxTries;
	int GameProgress;
};

