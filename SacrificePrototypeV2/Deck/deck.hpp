#pragma once

#include "Cards/cards.hpp"
#include <vector>

class Deck {
public:
	// Initializes a deck with the default deck of the Sacrifice game 
	Deck();

	// Creates a deck with 'Amount' empty cards inside it if 'Fill' is true, otherwise
	// it creates a deck with 'Amount' reserved, do 'Amount' = 0 and Fill = false, just to have
	// it act as a default constructor
	Deck(int, bool);

	// Prints all cards inside the deck with just the default information about the cards
	// if more information is required please use PrintDeckDebug(); or PrintDeckRaw();
	void PrintDeck() const;
	
	// Returns the amount of interactible cards inside the deck
	int GetDeckSize() const;

	// Returns the Card at position 'Index' from the deck
	Card GetCard(int) const;

	// Replaces a Card at position 'Index' in the Deck
	void Setcard(Card, int);
	//TODO: Implement RemoveCard()
	
	void PrintValidCards(Card) const;

	void ShuffleDeck();

	//TODO: Implement DeckShuffling()

	~Deck();
private:
	std::vector<Card> m_Deck;
	int m_CardsInDeck;
};
