#pragma once

enum Color {
	EmptyC = 0,
	Blue,
	Green,
	Red,
	Yellow,
	Black,
	SizeC = 6
};

enum Type {
	EmptyT = 0,
	Block,
	Reverse,
	SizeT = 3
};

enum PlusType {
	EmptyPT = 0,
	OnePT,
	TwoPT,
	FourPT,
	TwentyPT,
	SizePT = 5
};

enum SpecialType {
	EmptyST = 0,
	Joker,
	DefenseRune,
	PovertyRune,
	BanishmentRune,
	SizeST = 5
};

class Card {
public:

	// Initializes a card with all variables set to their Empty equivalent
	Card();

	// Used to initialize a number card all other variables set to their Empty equivalent
	Card(Color, int);

	// Used to initialize a Plus card all other variables set to their Empty equivalent
	Card(Color, PlusType);

	// Used to initialize a Basic Type card all other variables set to their Empty equivalent
	Card(Color, Type);

	// Used to initialize a SpecialType card all other variables set to their Empty equivalent
	Card(Color, SpecialType);

	~Card();

	// Prints the cards always color first, unless the card is a SpecialType, then it doesn't print colors
	// If a completely empty card is provided it prints all its atributes to be easily distinguishable
	void PrintCard() const;
	
	// These below are basic getters and setter for all of the properties on a card

	Color GetColor() const;
	Type GetType() const;
	SpecialType GetSpecialType() const;
	PlusType GetPlusType() const;
	int GetNumber() const;
	
	void SetColor(Color);
	void SetType(Type);
	void SetSpecialType(SpecialType);
	void SetPlusType(PlusType);
	void SetNumber(int);

private:
	Color m_Color;
	Type m_Type;
	PlusType m_PlusType;
	SpecialType m_SpecialType;
	int m_Number;
};
