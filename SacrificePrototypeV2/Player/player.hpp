#pragma once
#include "Cards/cards.hpp"
#include "Deck/deck.hpp"
#include <vector>
#include <string>

using std::string;

class Player
{
public:
	// Creates a player with an empty hand and no name
	Player();

	// Creates a player with an empty hand and the given name
	Player(string);

	void SetName(string);
	string GetName() const;

	Deck GetHand() const;

	// Prints all valid plays on the player's hand based on the last card played
	void PrintValid(Card) const;

	void PrintPlayerName() const;

	~Player();

private:
	string m_Name;
	Deck m_Hand;
	bool m_Alive;

};
