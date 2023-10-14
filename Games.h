#ifndef GAMES_H
#define GAMES_H

	// Coinflip
	void playCoinflip(int& balance);
	int simulateCoinflip();

	void playRoulette(int& balance);
	int spinRouletteWheel();

	void playBlackjack(int& balance);
	void shuffleDeck(int deck[], int deckSize);
	int dealCard(int deck[], int& deckIndex);
	int calculateHandValue(const int hand[], int handSize);
	void displayHand(const int hand[], int handSize);

#endif