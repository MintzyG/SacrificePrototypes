package card

import (
	"fmt"
	"sacrifice/effect"
)

type CardKind int

const (
	Zero CardKind = iota
	One
	Two
	Three
	Four
	Five
	Six
	Seven
	Eight
	Nine
	Block
	Reverse
	PlusTwo
	PlusFour
	Special
)

var AllCardKinds = []CardKind{
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Block,
	Reverse,
	PlusTwo,
	PlusFour,
	Special,
}

var CardNames = map[CardKind]string{
	Zero:     "Zero",
	One:      "One",
	Two:      "Two",
	Three:    "Three",
	Four:     "Four",
	Five:     "Five",
	Six:      "Six",
	Seven:    "Seven",
	Eight:    "Eight",
	Nine:     "Nine",
	Block:    "Block",
	Reverse:  "Reverse",
	PlusTwo:  "Plus Two",
	PlusFour: "Plus Four",
	Special:  "Special",
}

type CardColor int

const (
	Black CardColor = iota
	White
	Red
	Green
	Blue
	Yellow
	Purple
	None
)

var AllCardColors = []CardColor{
	Black,
	White,
	Red,
	Green,
	Blue,
	Yellow,
	Purple,
	None,
}

var CardColorNames = map[CardColor]string{
	Black:  "Black",
	White:  "White",
	Red:    "Red",
	Green:  "Green",
	Blue:   "Blue",
	Yellow: "Yellow",
	Purple: "Purple",
	None:   "None",
}

type Card struct {
	CardKind  CardKind
	CardColor CardColor
	Effect    effect.CardEffect
}

func (c Card) String() string {
	return fmt.Sprintf("%v %v", CardColorNames[c.CardColor], CardNames[c.CardKind])
}

func CreateBaseDeck() []Card {
	var deck []Card
	for _, k := range AllCardKinds {
		if k < Nine {
			for _, c := range AllCardColors {
				if c >= Purple {
					break
				}
				deck = append(deck, Card{
					CardKind:  k,
					CardColor: c,
				})
			}
		} else if k < Special {
			for cc := 0; cc < 2; cc++ {
				var e effect.CardEffect
				switch k {
				case Block:
					e = effect.BlockEffect
				case Reverse:
					e = effect.ReverseEffect
				case PlusTwo:
					e = effect.PlusTwoEffect
				case PlusFour:
					e = effect.PlusFourEffect
				}
				for _, c := range AllCardColors {
					if c >= Purple {
						break
					}
					deck = append(deck, Card{
						CardKind:  k,
						CardColor: c,
						Effect:    e,
					})
				}
			}
		}
	}
	return deck
}

func PrintDeck(deck []Card) {
	for _, c := range deck {
		fmt.Println(c)
	}
}
