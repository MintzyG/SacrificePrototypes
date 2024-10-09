#include "game.hpp"
#include <iostream>

// Initializes a Classic game of Sacrifice
Game::Game()
	: m_Mode(Classic), m_MaxPlayers(10), m_Deathmatch(NoDeathmatch), m_PlayerAmount(0)
{
	m_Deck = Deck();
}

// Initializes the Sacrifice with the desired GameMode, can't initialize Classic and Custom
Game::Game(GameModes gm) 
	: m_Mode(gm), m_Deathmatch(NoDeathmatch), m_PlayerAmount(0)
{
	switch (gm) {
	case Classic:
		std::cerr << "Use the apropriate constructor for Classic, Game()";
		std::exit(1);
		break;
	case SpeedX:
		m_MaxPlayers = 10;
		break;
	case SpeedXOne:
		m_MaxPlayers = 2;
		break;
	case Exterminator:
		m_MaxPlayers = 10;
		break;
	case Duos:
		m_MaxPlayers = 10;
		break;
	case Teams:
		m_MaxPlayers = 12;
		break;
	case Tournament:
		m_MaxPlayers = 12;
		break;
	case Hardcore:
		m_MaxPlayers = 10;
		break;
	case Custom:
		std::cerr << "Use the apropriate constructor for custom, Game(int)";
		std::exit(1);
		break;
	case GMSize:
		std::cerr << "Can't Start a game with an invalid game mode: GMSize";
		std::exit(1);
		break;
	default:
		std::cerr << "Something went terribly wrong at game inicialization Game(GameModes)" << std::endl;
		std::exit(1);
		break;
	}
}

// TODO: Implement empty game constructor

// TODO: Reword Custom game constructor to just take an int
// Initializes a Custom GameMode of Sacrifice with 'X' empty cards in the deck
Game::Game(GameModes gm, int x)
	: m_Mode(gm), m_Deathmatch(NoDeathmatch), m_PlayerAmount(0)
{
	if (gm == Custom) {
		m_MaxPlayers = 20;
		m_Deck = Deck(x, true);
	}
	else {
		std::cerr << "You tried using the Custom Game constructor to initialize another Game Mode" << std::endl;
		std::exit(1);
	}
}

// TODO: add PrintGameDebug() or PrintGameRaw()

// Prints the default game info, for more information use PrintGameDebug() or PrintGameRaw()
void Game::PrintGameInfo() const {
	m_Deck.PrintDeck();
	for (int i = 0; i < m_PlayerAmount; i++) {
		std::cout << "Player " << i + 1 << ": " << m_Players[i].GetName() << std::endl;
	}

}

// Sets up 'Amount' nameless players for the game 
void Game::CreatePlayers(int amount) {
	Player player;
	for (int i = 0; i < amount; i++) {
		m_Players.push_back(player);
	}
}

// Ask for the user to input the names of all players
void Game::NamePlayers() {
	string name;
	for (int i = 0; i < m_PlayerAmount; i++) {
		std::cout << "Whats player " << i + 1 << " name: ";
		std::cin >> name;
		m_Players[i].SetName(name);
	}
}

// Creates a match of Sacrifice
void Game::SetupGame() {

	SetPlayerAmount();
	CreatePlayers(m_PlayerAmount);
	NamePlayers();

}

void Game::SetPlayerAmount() {
	int amount = 0;
	while (true) {
		std::cout << "How many players will participate: ";
		std::cin >> amount;
		if ((amount > m_MaxPlayers) || (amount < 0)) {
			std::cout << "Invalid amount of players" << std::endl;
			continue;
		} else {
			m_PlayerAmount = amount;
			break;
		}
	}
}

Game::~Game()
{
}