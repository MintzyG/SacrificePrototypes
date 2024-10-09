#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

enum Color { BLACK, WHITE, YELLOW, BLUE, GREEN, RED, ANY, EMPTY_COLOR };
enum Number { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, PLUS_TWO, PLUS_FOUR, PLUS_ONE, BLOCK, REVERSE, CHOOSE_COLOR, EMPTY_NUMBER };
enum Animal { OCTOPUS, OWL, MOOSE, WOLF, GOAT, BEAR, EMPTY_ANIMAL };
enum Type { HAND, INVENTORY, TERRITORY, EMPTY_TYPE };
enum Strength { LOW, HIGH, SPECIAL, EMPTY_STRENGTH };  

struct Card{

    Color card_color;
    Number card_number;
    Animal card_animal;
    Type card_type;
    Strength card_strength;
    int num_number = 10;
    int num_color = 6;
    bool is_plus;
    int played_by = 0;
    bool has_bought = false;
    int buy_amount = 0;
};
 
struct Deck{

    vector<Card> cards;
    int max_deck_size = 60;

};

struct PlayedDeck{

    vector<Card> played_cards;

};

struct Player{

    vector<Card> hand;
    vector<Card> possible_plays;
    string name;
    bool is_dead = false;
    int card_quantity = 0;

};

struct Game{

    vector<Player> players;
    PlayedDeck played_deck;
    Deck deck;
    Color starting_color;
    Card last_played_card;
    Player winner;
    size_t valid_play_count = 1;
    int first_player = 0;
    int to_buy = 0;
    int current_player = 0;
    int num_players = 3;
    int num_cards_per_hand = 7;
    int game_turns_played = 0;
    int bought_before_dm = 0;
    bool game_over = false;
    bool deathmatch = false;
    bool block_next = false;
    bool is_reversed = false;
    bool change_color = false;

};

void initialize_deck(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle_deck(Deck&);
bool deal_cards(Game&); 
void print_hand(const vector<Card>&, bool, Game&);
void initialize_game(Game&);
void add_players(Game&);
void print_game(const Game&); 
void play_game(Game&);
void start_color(Game&);
void first_player(Game&);
void turn(Game&);
bool check_win_condition(Game&);
void last_played_info(Game&);
void play_turn(Game&, int);
void get_next_player(Game&, bool);
void screen_clear();
void choose_winner(Game&);
void show_finished_game(Game&);
void show_turns(Game&);
void turn_ui(Game&);
void display_drawn(Game&);
void do_play(Game&, Card&, int);

int main(){

    srand(time(NULL));

    Game game;
    play_game(game);

}

void initialize_deck(Deck& deck){



        Card card;
        card.card_strength = Strength::LOW;
        card.card_type = Type::HAND;
        card.is_plus = false;
        
        for (int number = 0; number < card.num_number; number++){
            for (int color = 0; color < card.num_color; color++){

                card.card_color = Color(color);
                card.card_number = Number(number);

                // Assigns the animal of the card
                switch (color){
                    case 0:
                        card.card_animal = Animal::OWL;
                        break;

                    case 1:
                        card.card_animal = Animal::OCTOPUS;
                        break;

                    case 2:
                        card.card_animal = Animal::GOAT;
                        break;

                    case 3:
                        card.card_animal = Animal::WOLF;
                        break;

                    case 4:
                        card.card_animal = Animal::MOOSE;
                        break;
                        
                    case 5:
                        card.card_animal = Animal::BEAR;
                        break;
                                    
                    default:
                        card.card_animal = Animal::EMPTY_ANIMAL;
                        break;
                }

                deck.cards.push_back(card);

            }
        }

        Card plus_two;
        plus_two.is_plus = true;
        plus_two.card_number = Number::PLUS_TWO;
        
        for (int color = 0; color < card.num_color; color++){
            for (int i = 0; i < 2; i++){

                plus_two.card_color = Color(color);

                deck.cards.push_back(plus_two);

            }
        }

        Card plus_4;
        plus_4.is_plus = true;
        plus_4.card_number = Number::PLUS_FOUR;
        
        for (int color = 0; color < card.num_color; color++){
            for (int i = 0; i < 2; i++){

                plus_4.card_color = Color(color);

                deck.cards.push_back(plus_4);

            }
        }

        Card plus_1;
        plus_1.is_plus = true;
        plus_1.card_number = Number::PLUS_ONE;
        
        for (int color = 0; color < card.num_color; color++){

            plus_1.card_color = Color(color);

            deck.cards.push_back(plus_1);

        }

        Card block;
        block.card_number = Number::BLOCK;
        block.card_strength = Strength::LOW;
        block.card_type = Type::HAND;
        block.is_plus = false;

        for (int color = 0; color < card.num_color; color++){
            for (int i = 0; i < 3; i++){
                
                block.card_color = Color(color);

                deck.cards.push_back(block);

            }
        }

        Card reverse;
        reverse.card_number = Number::REVERSE;
        reverse.card_strength = Strength::LOW;
        reverse.card_type = Type::HAND;
        reverse.is_plus = false;

        for (int color = 0; color < card.num_color; color++){
            for (int i = 0; i < 3; i++){
                
                reverse.card_color = Color(color);

                deck.cards.push_back(reverse);

            }
        }

        Card choose_color;
        choose_color.card_number = Number::CHOOSE_COLOR;
        choose_color.card_color = Color::ANY;
        choose_color.card_strength = Strength::HIGH;
        choose_color.card_type = Type::HAND;
        choose_color.is_plus = false;

        for (int i = 0; i < 8; i++){
                
            deck.cards.push_back(choose_color);

        }
        
        
}

// Debug tool
void print_deck(const Deck& deck){

    for (Card c : deck.cards){

        print_card(c); 

    }

}

void print_card(const Card& card){

    switch (card.card_color){
    case Color::BLACK:
        cout<<"Black ";
        break;
    case Color::WHITE:
        cout<<"White ";
        break;
    case Color::YELLOW:
        cout<<"Yellow ";
        break;
    case Color::BLUE:
        cout<<"Blue ";
        break;
    case Color::GREEN:
        cout<<"Green ";
        break;
    case Color::RED:
        cout<<"Red ";
        break;
    case Color::EMPTY_COLOR:
        cout<<"Empty ";
        break;
    case Color::ANY:
        cout<<"";
        break;    
    default:
        cout<<"error ";
        break;
    }

    switch (card.card_number){
    case Number::ZERO:
        cout<<"zero";
        break;
    case Number::ONE:
        cout<<"one";
        break;
    case Number::TWO:
        cout<<"two";
        break;
    case Number::THREE:
        cout<<"three";
        break;
    case Number::FOUR:
        cout<<"four";
        break;
    case Number::FIVE:
        cout<<"five";
        break;
    case Number::SIX:
        cout<<"six";
        break;
    case Number::SEVEN:
        cout<<"seven";
        break;
    case Number::EIGHT:
        cout<<"eight";
        break;
    case Number::NINE:
        cout<<"nine";
        break;
    case Number::PLUS_TWO:
        cout<<"plus two";
        break;
    case Number::PLUS_FOUR:
        cout<<"plus four";
        break;
    case Number::PLUS_ONE:
        cout<<"plus one";
        break;
    case Number::BLOCK:
        cout<<"block";
        break; 
    case Number::REVERSE:
        cout<<"reverse";
        break; 
    case Number::EMPTY_NUMBER:
        cout<<"empty";
        break;
    case Number::CHOOSE_COLOR:
        cout<<"Choose color";
        break;    
    default:
        cout<<"error";
        break;
    }
    cout<< endl; 

}

void shuffle_deck(Deck& deck){

    Deck shuffled;

    while (!deck.cards.empty()){

        size_t rand_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[rand_index]);
        deck.cards.erase(deck.cards.begin() + rand_index);

    }

    deck = shuffled;

}

bool deal_cards(Game& game){

    if (game.deck.cards.size() < game.num_players * game.num_cards_per_hand){
        return false;
    }


     for (int card = 0; card < game.num_cards_per_hand; card++){
        for (int player = 0; player < game.num_players; player++){

            game.players[player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());

        }
     }

    return true;

}

void print_hand(const vector<Card>& hand, bool game_finished, Game& game){

    int counter = 1;
    for (Card c : hand){

        cout<<counter<<":";
        if(c.has_bought){
            cout << game.players[c.played_by].name << " bought: " << c.buy_amount << " cards";    
        } else if (game_finished){
            cout << game.players[c.played_by].name << " played: ";
        } else {
            cout<< " ";
        }
        counter++;
        if (!c.has_bought){
            print_card(c);
        }
        

    }
    cout<<endl;

}

void initialize_game(Game& game){

    initialize_deck(game.deck);
    shuffle_deck(game.deck);
    add_players(game);
    start_color(game);
    first_player(game);
}

void add_players(Game& game){

    string names;
    for(int player = 0; player < game.num_players; player++){
        
        Player new_player;
        game.players.push_back(new_player);
        cout<<"Choose player " << (player + 1) << " name" << endl;
        cin>>names;
        game.players[player].name = names;

    }

}

// Debug tool
void print_game(Game& game){

    for(int player = 0; player < game.num_players; player++){

        print_hand(game.players[player].hand, false, game);
        
    }

    print_deck(game.deck);

    cout << "Starting color: " << game.starting_color << endl;

}

void start_color(Game& game){

    int rand_color = rand() % Color::RED; 
    game.starting_color = Color(rand_color);

}

void first_player(Game& game){

    game.first_player = rand() % game.num_players;
    game.current_player = game.first_player;

}

void last_played_info(Game& game){

    if (game.played_deck.played_cards.empty()){
        cout<< "The starting color is: ";
        switch (game.starting_color)
        {
        case Color::BLACK:
            cout<<" Black";
            break;
        case Color::WHITE:
            cout<<" White";
            break;
        case Color::YELLOW:
            cout<<" Yellow";
            break;
        case Color::BLUE:
            cout<<" Blue";
            break;
        case Color::GREEN:
            cout<<" Green";
            break;
        case Color::RED:
            cout<<" Red";
            break;
        
        default:
            break;
        }
        cout<<endl;
    }

    if (!(game.played_deck.played_cards.empty())){
        cout << "The last played card was: ";
        print_card(game.last_played_card);
    }

    if (game.to_buy != 0){
        cout << "The sequence is on: " << game.to_buy << endl;
    }


}

void check_block(Game& game, Card card){

    if (card.card_number == Number::BLOCK){

        game.block_next = true;

    }

}

void check_plus(Game& game, Card card){

    if (card.is_plus){

        switch (card.card_number)
        {
        case Number::PLUS_ONE:
            game.to_buy += 1;
            break;
        case Number::PLUS_TWO:
            game.to_buy += 2;
            break;
        case Number::PLUS_FOUR:
            game.to_buy += 4;
            break;
        
        default:
            cout << endl << endl << "ERROR - to_buy (check_plus)" << endl << endl;
            break;
        }

    }

}

void check_reverse(Game& game, Card card){

    if (card.card_number == Number::REVERSE){

        game.is_reversed = !game.is_reversed;

    }

}

int check_choose_color(Game& game, Card card, int new_color){

    if (card.card_number == Number::CHOOSE_COLOR){

        game.change_color = true;
        cout << endl << "Which color would you like to play?" << endl;
        cout << "1: Black" << endl << "2: White" << endl << "3: Yellow" << endl 
        << "4: Blue" << endl << "5: Green" << endl << "6: Red" << endl;

        do {
            cin >> new_color;
        } while ((new_color <= 0) || (new_color > 6));

        return new_color;

    }

    return 0;

}

int check_strongs(Game& game, Card card, int new_color){

    check_plus(game, card);

    check_block(game, card);

    check_reverse(game, card);

    return check_choose_color(game, card, new_color);

}

void player_draw(Game& game){

    if (game.to_buy == 0){
        
        if (!game.deathmatch){

            game.players[game.current_player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());
            cout<<"There are " << (game.deck.cards.size()) << " cards left in the deck" << endl;
        
        
            if (game.deck.cards.empty()){

                cout << "The game is now on deathmatch";
                game.deathmatch = true;

            }
        

            if ((game.players[game.current_player].hand.back().card_color == game.last_played_card.card_color) || (game.players[game.current_player].hand.back().card_number == game.last_played_card.card_number) || (game.players[game.current_player].hand.back().card_number == Number::CHOOSE_COLOR)) {
       
                cout << endl << endl << "You can play the drawn card" << endl;
                cout << "1: Play" << endl << "2: Skip" << endl;
                int choice = 0;
                do {

                    cin >> choice;

                } while ((choice < 1) || (choice > 2)); 

                if (choice == 1){

                    turn_ui(game);

                } else if (choice == 2){

                    cout << endl << "You skipped your turn" << endl;

                }       

            }

        } else {

            game.players[game.current_player].is_dead = true;
            cout << game.players[game.current_player].name << " has died!" << endl;

        }

    } else {

        if (!game.deathmatch){

            game.players[game.current_player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());

            if (game.deck.cards.empty()){

                cout << "The game is now on deathmatch";
                game.deathmatch = true;
                game.bought_before_dm = 1;

            }

        } else {

            game.players[game.current_player].is_dead = true;
            cout << game.players[game.current_player].name << " has died!" << endl;

        }

    }

    int alive_players = 0;
    for(int players = 0; players < game.players.size(); players++){

        if (!game.players[players].is_dead){

            alive_players++;

        }
    }

    if (alive_players == 1){
        game.game_over = true;

        for(int players = 0; players < game.players.size(); players++){

            if (!game.players[players].is_dead){
                game.winner = game.players[players];
            }
        }
    }
}

void display_drawn(Game& game){

    if (game.to_buy == 0){

        if (!game.deathmatch){
            cout << endl << game.players[game.current_player].name << " has to draw" << endl;
            cout << game.players[game.current_player].name << " has drawn a: ";
            print_card(game.deck.cards[0]);
            player_draw(game);
        } else {

            player_draw(game);

        }

    } else {

        if (!game.deathmatch){
            cout << endl << game.players[game.current_player].name << " has to buy " << game.to_buy << " cards" << endl;  
            cout << game.players[game.current_player].name << " has drawn:" << endl;
            for (int buy_counter = 0; buy_counter < game.to_buy; buy_counter++){

                if (!game.deathmatch){
                    cout << (buy_counter + 1) << ": ";
                    print_card(game.deck.cards[0]);
                    player_draw(game);
                } else if ((game.deathmatch) && (game.bought_before_dm == 1)){

                    game.to_buy = 0;
                    return;

                } 

            }

            cout<<"There are " << (game.deck.cards.size() - 1)<< " cards left in the deck" << endl;
            game.to_buy = 0;

        } else {

            player_draw(game);
            game.to_buy = 0;

        }

    }

}

bool check_if_first_turn(Game& game){

    if (game.played_deck.played_cards.empty()){

        return true;

    } else {

        return false;

    }

}

bool compare_plus(Card& card1, Card& card2){

    if (card1.is_plus == card2.is_plus){
        return true;
    } else {
        return false;
    }

}

bool compare_card_number(Card& card1, Card& card2){

    if (card1.card_number == card2.card_number){
        return true;
    } else {
        return false;
    }

}

bool compare_card_color(Card& card1, Card& card2){

    if (card1.card_color == card2.card_color){
        return true;
    } else {
        return false;
    }

}

bool check_same_card(Game& game, Card& card1, Card& card2){

    if (compare_card_color(card1, card2) && compare_card_number(card1, card2)){
        return true;
    } else{
        return false;
    }

}

void check_effects(Game& game, Card& card){

    game.change_color = false;
    int new_color = 0;

    new_color = check_strongs(game, card, new_color);
    do_play(game, card, new_color);

    game.game_over = check_win_condition(game);

}

void do_play(Game& game, Card& played_card, int new_color){

    for (int cards = 0; cards < game.players[game.current_player].hand.size(); cards++){
        Card temp_card = game.players[game.current_player].hand[cards];

        if (check_same_card(game, played_card, temp_card)){

            if (game.change_color){

                game.players[game.current_player].hand[cards].card_color = Color(new_color - 1);

            }

            game.players[game.current_player].hand[cards].played_by = game.current_player;
            game.played_deck.played_cards.push_back(game.players[game.current_player].hand[cards]);
            game.last_played_card = game.players[game.current_player].hand[cards];
            game.players[game.current_player].hand.erase(game.players[game.current_player].hand.begin() + (cards));
            break;

        }
    }

}

bool ft_card_check(Game& game, Card& card){

    if (card.card_color == game.starting_color){
        return true;
    } else if (card.card_color == Color::ANY){
        return true;
    } else {
        return false;
    }

}

bool card_check(Game& game, Card& card){

    Card last_card = game.last_played_card;

    if (game.to_buy != 0){
        if (card.is_plus == true){
            return true;
        } else {
            return false;
        }
    } else if ((compare_card_color(card, last_card)) || (card.card_color == Color::ANY)){
        return true;
    } else if (compare_card_number(card, last_card)){
        return true;
    } else if ((compare_plus(card, last_card)) && (game.last_played_card.is_plus == true)){
        return true;
    } else {
        return false;
    }

}

void play_turns(Game& game){

    game.valid_play_count = 1;

    cout<< endl << "Type 0 to buy";
    cout << endl << "What do you want to play?" << endl;

    bool done = false;
    do{
        int action = 0;
        cin >> action;
        Card chosen_card;
        if (action != 0){
            chosen_card = game.players[game.current_player].hand[action - 1];
        }   

        if (action != 0){
            if (!check_if_first_turn(game)){
                if (card_check(game, chosen_card)){

                    check_effects(game, chosen_card);
                    done = true;

                } else {

                    cout << endl << "Chosen card is invalid" << endl;

                }
            } else {
                if (ft_card_check(game, chosen_card)){

                    check_effects(game, chosen_card);
                    done = true;

                } else {

                    cout << endl << "Chosen card is invalid" << endl;

                }
            }
        } else {

            Card bought;
            bought.has_bought = true;
            bought.played_by = game.current_player;
            if (game.to_buy == 0){
                bought.buy_amount = 1;
            } else {
                bought.buy_amount = game.to_buy;
            }
            game.played_deck.played_cards.push_back(bought);

            // Make a better draw function
            display_drawn(game);
            done = true;

        }

    }while(!done);

}

void get_next_player(Game& game, bool next_on_first){

    int next_player = 0;

    if (!next_on_first){

        if (!game.is_reversed) {

            next_player = (game.current_player + 1) % game.num_players;
            game.current_player = next_player;

        } else {

            next_player = (game.current_player - 1) % game.num_players;
            if (next_player < 0){

                next_player = (game.players.size() - 1);

            }
            game.current_player = next_player;

        }

    } else {

            game.first_player = (game.current_player + 1) % game.num_players; 
            game.current_player = game.first_player;
    }
}

void player_view_order(Game& game){


    if (game.played_deck.played_cards.empty()){

        cout << endl << endl << "Game started!!!" << endl;

    } else if ((game.players[game.current_player].name == game.players.front().name) && (!game.is_reversed)){

        cout << endl << endl << "Previous player: " << game.players.back().name << endl;

    } else if ((game.players[game.current_player].name == game.players.back().name) && (game.is_reversed)) {

        cout << endl << endl << "Previous player: " << game.players.front().name << endl;

    } else if ((game.players[game.current_player].name != game.players.back().name) && (game.is_reversed)) {

        cout << endl << endl << "Previous player: " << game.players[(game.current_player + 1)].name << endl;

    } else {

        cout << endl << endl << "Previous player: " << game.players[(game.current_player - 1)].name << endl;

    }

    if (!game.is_reversed){

        cout << "Current player: " << game.players[game.current_player].name << endl;
        if (game.players[(game.current_player)].name == game.players.back().name){

            cout << "Next player: " << game.players.front().name << endl << endl;

        } else {

        cout << "Next player: " << game.players[(game.current_player + 1)].name << endl << endl;

        }

    } else {

        cout << "Current player: " << game.players[game.current_player].name << endl;
        if (game.players[(game.current_player)].name == game.players.front().name){

            cout << "Next player: " << game.players.back().name << endl << endl;

        } else {

        cout << "Next player: " << game.players[(game.current_player - 1)].name << endl << endl;

        }

    }

}

void matching_cards(Game& game){

    int count = 0;
    for (int cards = 0; cards < game.players[game.current_player].hand.size(); cards++){

        Card card = game.players[game.current_player].hand[cards];

        if (check_if_first_turn(game)){
            if(ft_card_check(game, card)){
                count++;
            }
        } else {
            if (card_check(game, card)){
                count++;
            }
        }
    }

    cout << "You have " << count << " playable cards" << endl;

}

void turn_ui(Game& game){

    player_view_order(game);
    cout << game.players[game.current_player].name << "'s turn!"<<endl;
    last_played_info(game);
    if (game.deathmatch){
        cout << "The game is now in Deathmatch!" << endl;
    }     
    matching_cards(game);
    cout << endl << game.players[game.current_player].name << "'s hand: " << endl; 
    print_hand(game.players[game.current_player].hand, false, game);
    play_turns(game);

}

void check_blocked(Game& game){

    if (game.block_next){

        cout << game.players[game.current_player].name << " was blocked";
        get_next_player(game, false);
        game.block_next = false;

    }

}

void turn(Game& game){

    if (game.played_deck.played_cards.empty()){
        turn_ui(game);
        cout<< endl << "Press enter to end turn" << endl;
        cin.get();
        return;
    }

    get_next_player(game, false);
    if (game.players[game.current_player].is_dead){
        get_next_player(game, false);
    }
    check_blocked(game);
    turn_ui(game);
    cout<< endl << "Press enter to end turn" << endl;
    cin.get();
    return;    

}

bool check_win_condition(Game& game){

    if (game.to_buy == 0){
        for (int player = 0; player < game.num_players; player++){

            if (game.players[player].hand.empty()){
                return true;
            }

        }
        return false;
    }

    return false;

}

void play_game(Game& game){

    initialize_game(game);
    deal_cards(game);

    game.game_over = check_win_condition(game);
    int turn_counter = 0;

    //print_game(game);

    while (!game.game_over) {

        turn(game);
        turn_counter++;
        game.game_turns_played = turn_counter;
        cin.get();
        screen_clear();

    }

    show_finished_game(game);
    choose_winner(game);
    show_turns(game);

}

void screen_clear(){

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
    <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

}

void choose_winner(Game& game){
    cout << endl << "The winner was " << game.winner.name << "!!";
}

void show_finished_game(Game& game){

    cout<<endl<<endl<<"The game sequence was: "<<endl<<endl;
    print_hand(game.played_deck.played_cards, true, game);
    cout<<endl<<endl;

}

void show_turns(Game& game){

    cout<<endl<<endl;
    cout<<"The game was played for "<< game.game_turns_played<<" turns";
    cout<<endl;

}

