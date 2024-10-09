#include <vector>
#include <iostream>
#include <cstdlib>
#include "Cards/cards.hpp"
#include "deck.hpp"

// Creates a deck with 'Amount' empty cards inside it if 'Fill' is true, otherwise
// it creates a deck with 'Amount' reserved, do 'Amount' = 0 and Fill = false, just to have
// it act as a default constructor
Deck::Deck(int Amount, bool Fill)
	: m_CardsInDeck(Amount)
{
	Card card;
	if (Fill)
		for (size_t i = 0; i < Amount; i++)
			m_Deck.push_back(card);

}

Deck::Deck() 
	: m_CardsInDeck(0)
{	
	for (int i = 0; i < SizeC - 2; i++) {
		// Setting up the numbers
		for (int j = 0; j < 5; j++) {
			Card card((Color)(i + 1), j);
			m_Deck.push_back(card);
			m_CardsInDeck += 1;
		}
		// Setting up +2
		for (int j = 0; j < 6; j++) {
			Card card((Color)(i + 1), TwoPT);
			m_Deck.push_back(card);
			m_CardsInDeck += 1;
		}
	
		for (int j = 0; j < 6; j++) {
			Card card((Color)(i + 1), Block);
			m_Deck.push_back(card);
			m_CardsInDeck += 1;
		}

		for (int j = 0; j < 6; j++) {
			Card card((Color)(i + 1), Reverse);
			m_Deck.push_back(card);
			m_CardsInDeck += 1;
		}
	}

	for (int i = 0; i < 16; i++) {
		Card card(Black, FourPT);
		m_Deck.push_back(card);
		m_CardsInDeck += 1;
	}

	for (int i = 0; i < 16; i++) {
		Card card(Black, Joker);
		m_Deck.push_back(card);
		m_CardsInDeck += 1;
	}
}

// TODO: Add PrintDeckDebug(); or PrintDeckRaw();

// Prints all cards inside the deck with just the default information about the cards
// if more information is required please use PrintDeckDebug(); or PrintDeckRaw();
void Deck::PrintDeck() const {

	std::cout << std::endl;

	for (int i = 0; i < m_Deck.size(); i++) {
		m_Deck[i].PrintCard();
	}

	std::cout << "Cards in deck: " << m_CardsInDeck << std::endl;
}

// Returns the amount of interactible cards inside the deck
int Deck::GetDeckSize() const {
	return m_CardsInDeck;
}

// Returns the Card at position 'Index' from the deck
Card Deck::GetCard(int index) const {
	return m_Deck[index];
}

// Replaces a Card at position 'Index' in the Deck
void Deck::Setcard(Card card, int index) {
	m_Deck[index] = card;
}

// Takes a card and prints all cards that can be played on top of that card
void Deck::PrintValidCards(Card card) const {

}

void Deck::ShuffleDeck() {
	std::vector<Card> tmp;
	tmp.reserve(m_CardsInDeck);

	for (int i = m_CardsInDeck; i >= 0 ; i--) {

	}
}

Deck::~Deck()
{
}