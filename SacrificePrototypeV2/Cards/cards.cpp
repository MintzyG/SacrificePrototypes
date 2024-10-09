#include "cards.hpp"
#include "printCard.hpp"
#include <iostream>

// Initializes a card with all variables set to their Empty equivalent
Card::Card()
	: m_Color(EmptyC), m_Type(EmptyT), m_PlusType(EmptyPT), m_SpecialType(EmptyST), m_Number(-1)
{
}

// Used to initialize a number card all other variables set to their Empty equivalent
Card::Card(Color color, int number)
	: m_Color(color), m_Type(EmptyT), m_PlusType(EmptyPT), m_SpecialType(EmptyST), m_Number(number)
{
}

// Used to initialize a Plus card all other variables set to their Empty equivalent
Card::Card(Color color, PlusType pt)
	: m_Color(color), m_Type(EmptyT), m_PlusType(pt), m_SpecialType(EmptyST), m_Number(-1)
{
}

// Used to initialize a Basic Type card all other variables set to their Empty equivalent
Card::Card(Color color, Type t)
	: m_Color(color), m_Type(t), m_PlusType(EmptyPT), m_SpecialType(EmptyST), m_Number(-1)
{
}

// Used to initialize a SpecialType card all other variables set to their Empty equivalent
Card::Card(Color color, SpecialType st)
	: m_Color(color), m_Type(EmptyT), m_PlusType(EmptyPT), m_SpecialType(st), m_Number(-1)
{
}

Color Card::GetColor() const {
	return m_Color;
}

Type Card::GetType() const {
	return m_Type;
}

PlusType Card::GetPlusType() const {
	return m_PlusType;
}

SpecialType Card::GetSpecialType() const {
	return m_SpecialType;
}

int Card::GetNumber() const {
	return m_Number;
}

void Card::SetColor(Color color) {
	m_Color = color;
}

void Card::SetType(Type type) {
	m_Type = type;
}

void Card::SetPlusType(PlusType plusType) {
	m_PlusType = plusType;
}

void Card::SetSpecialType(SpecialType specialType) {
	m_SpecialType = specialType;
}

void Card::SetNumber(int number) {
	m_Number = number;
}

//TODO: Implement PrintCardRaw() and PrintCardDebug()
// Prints the cards always color first, unless the card is a SpecialType, then it doesn't print colors
// If a completely empty card is provided it prints all its atributes to be easily distinguishable
void Card::PrintCard() const {
	if (m_PlusType != 0) {
		std::cout << StringColor(m_Color) << StringPlusType(m_PlusType) << std::endl;
	} else if (m_Type != 0) {
		std::cout << StringColor(m_Color) << StringType(m_Type) << std::endl;
	}
	else if (m_Number != -1) {
		std::cout << StringColor(m_Color) << m_Number << std::endl;
	}
	else if (m_SpecialType != 0) {
		std::cout << StringSpecial(m_SpecialType) << std::endl;
	}
	else {
		std::cout << StringColor(m_Color) << StringType(m_Type) << StringPlusType(m_PlusType)
			<< StringSpecial(m_SpecialType) << m_Number << std::endl;
	}
}

Card::~Card () {
}