package player

import (
	"fmt"
	"sacrifice/card"
	"sacrifice/effect"
)

type Player struct {
	ID      int
	Name    string
	Hand    []card.Card
	IsAlive bool
	Effects []effect.ActiveEffect
}

type Account struct {
	Username    string
	Wins        int
	GamesPlayed int
}

func CreatePlayer(index int) Player {
	var p Player
	p.ID = index
	p.IsAlive = true
	fmt.Printf("Enter player's %v name\n", index)
	fmt.Scanf("%s", &p.Name)
	return p
}
