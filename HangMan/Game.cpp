#include "Game.h"

FWord GenerateNewWord() {
	//TODO get from file
	return DEFAULT_HIDDEN_WORD;
}

Game::Game()
{
	Reset();
}

void Game::Reset()
{
	//TODO clear the screen
	NumberOfTries = 0;
	HiddenWord = GenerateNewWord();
	SetValidLetter();
	MaxTries = HiddenWord.length() + 3;
}

FWord Game::getHiddenWord() const
{
	return HiddenWord;
}

int Game::getNumOfTries() const
{
	return NumberOfTries;
}

int Game::getMaxTries() const
{
	return MaxTries;
}

int Game::getWordLength() const
{
	return HiddenWord.length();
}

void Game::SubmitGuess()
{
	NumberOfTries++;
	FLetter Guess;
	std::cout << "Please Enter your Guess: ";
	std::cin >> Guess;
	CheckGuessValidity(Guess);
}

LetterStatus Game::CheckGuessValidity(FLetter Guess)
{
	bool TriedLetters[26] = {false};
	if (Guess < 97 || Guess > 122) {
		return LetterStatus::NOT_OK;
	}
	for (int i = 0; i < 26; i++) {
		if (Guess == TriedLetters[i]) {
			return LetterStatus::ALREADY_SUBMITTED;
		}
		if (ValidLetter[Guess - 97]) {
			return LetterStatus::FOUND;
		}
		else {
			return LetterStatus::NOT_FOUND;
		}
	}
}

void Game::SetValidLetter()
{
	for (int i = 0; i < getWordLength(); i++) {
		ValidLetter[HiddenWord[i] - 97]++;
	}
	return;
}

int Game::getValidLetter(int i) const
{
	return ValidLetter[i];
}
