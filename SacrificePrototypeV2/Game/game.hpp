#include "Cards/cards.hpp"
#include "Deck/deck.hpp"
#include "Player/player.hpp"
#include <Vector>

enum GameModes {
	Classic = 0,
	SpeedX,
	SpeedXOne,
	Exterminator,
	Duos,
	Teams,
	Tournament,
	Hardcore,
	Custom,
	GMSize
};

enum Deathmatch {
	NoDeathmatch = 0,
	DeathmatchTypeOne,
	DeathmatchTypeTwo,
	DeathmatchTypeThree
};

class Game {
public:

	// Initializes a Classic game of Sacrifice
	Game();

	// Initializes the Sacrifice with the desired GameMode, can't initialize Classic and Custom
	Game(GameModes);

	// Initializes a Custom GameMode of Sacrifice with 'X' empty cards in the deck
	Game(GameModes, int);
	
	// Prints the default game info, for more information use PrintGameDebug() or PrintGameRaw()
	void PrintGameInfo() const;

	// Sets up 'Amount' nameless players for the 
	void CreatePlayers(int);

	// Ask for the user to input the names of all players
	void NamePlayers();

	// Creates a match of Sacrifice
	void SetupGame();

	void SetPlayerAmount();

	~Game();

	//TODO: Implement DealCard()
	//TODO: FirstCard(), FirstPlay()

private:
	Deck m_Deck;
	GameModes m_Mode;
	std::vector<Player> m_Players;
	Deathmatch m_Deathmatch;
	
	int m_PlayerAmount;
	int m_MaxPlayers;
};
