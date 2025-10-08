package game

import (
	"fmt"
	"sacrifice/card"
	"sacrifice/player"
)

type GameMode int

const (
	Normal GameMode = iota
)

type GameConfig struct {
	MaxPlayers int
	GameMode   GameMode
}

type Game struct {
	Config GameConfig

	Turn int

	Deck        []card.Card
	PlayedCards []card.Card
	DiscardPile []card.Card

	Players       []player.Player
	CurrentPlayer int

	OnSequence      bool
	CurrentSequence SequenceData
}

type SequenceData struct {
	StartedBy  player.Player
	BoughtBy   player.Player
	Amount     int
	Multiplier int
}

// ----- Game API ----- //

func (g *Game) Init() {
	g.Config.GameMode = Normal
	g.Config.MaxPlayers = 2
	g.CreateDeck()
	g.CreatePlayers()
	card.PrintDeck(g.Deck)
}

func (g *Game) CreateDeck() {
	g.Deck = card.CreateBaseDeck()
}

func (g *Game) CreatePlayers() {
	var players []player.Player
	for i := 0; i < g.Config.MaxPlayers; i++ {
		players = append(players, player.CreatePlayer(i+1))
	}
	g.Players = players
}

func (g *Game) BlockPlayer() {
	fmt.Println("BlockPlayer")
}

func (g *Game) Reverse() {
	fmt.Println("Reverse")
}

func (g *Game) NewSequence() {
	fmt.Println("NewSequence")
}

func (g *Game) AddSequence() {
	fmt.Println("AddSequence")
}

func (g *Game) IsOnSequence() bool {
	return g.OnSequence
}
