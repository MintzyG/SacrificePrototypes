#include "player.hpp"
#include <string>
#include <iostream>

using std::string;

Player::Player()
	: m_Alive(true), m_Name("Nameless")
{
	m_Hand = Deck(0, false);
}

Player::Player(string name)
	: m_Alive(true), m_Name(name)
{
	m_Hand = Deck(0, false);
}

void Player::SetName(string name) {
	m_Name = name;
}

string Player::GetName() const {
	return m_Name;
}

Deck Player::GetHand() const {
	return m_Hand;
}

// TODO: Implement functionality of Player::PrintValid()
// Prints all valid plays on the player's hand based on the last card played
void Player::PrintValid(Card lastCard)const {
}

void Player::PrintPlayerName() const {
	std::cout << m_Name;
}

Player::~Player()
{
}