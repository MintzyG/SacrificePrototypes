package effect

type GameAPI interface {
	BlockPlayer(id int, stackable bool)
	Reverse()
	NewSequence(amount int, player PlayerAPI)
	AddSequence(amount int)
	IsOnSequence() bool
}

type PlayerAPI interface {
	GetID() int
}

type CardEffect func(game GameAPI, player PlayerAPI)

type ActiveEffect struct {
	Name     string
	Duration int
	Data     map[string]int
}

var CardEffects = map[string]CardEffect{
	"Block":    BlockEffect,
	"Reverse":  ReverseEffect,
	"PlusTwo":  PlusTwoEffect,
	"PlusFour": PlusFourEffect,
}

func BlockEffect(game GameAPI, player PlayerAPI) {
	game.BlockPlayer(1, false)
}

func ReverseEffect(game GameAPI, player PlayerAPI) {
	game.Reverse()
}

func PlusTwoEffect(game GameAPI, player PlayerAPI) {
	if !game.IsOnSequence() {
		game.NewSequence(2, player)
		return
	}
	game.AddSequence(2)
}

func PlusFourEffect(game GameAPI, player PlayerAPI) {
	if !game.IsOnSequence() {
		game.NewSequence(4, player)
		return
	}
	game.AddSequence(4)
}
