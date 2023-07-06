#include <iostream>
#include <ctime>
 
using namespace std;
 
// Global Variables //
 
char *card_num[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
char *card_type[] = {"Clubs","Diamonds","Spades","Hearts"};
 
 
// Structures //
 
struct cardtype {
    int color;
    int number;
    int value;
};
 
struct decktype {
    bool deck[52];
    int size;
};
 
// Functions //
 
void SeedRandom() {
    time_t tTime;
    time(&tTime);
    srand(tTime);
    rand();
}
 
struct cardtype PickACard(struct decktype &deck) {
    struct cardtype card;
    int randnum = (int) (1.0 * rand() / (RAND_MAX + 1) * deck.size);
    int counter = 0;
    int i;
    for (i=0; i<52; ++i) {
        if (deck.deck[i] == true) {
            ++counter;
        }
        if (counter == randnum+1) {
            break;
        }
    }
    --deck.size;
    deck.deck[i] = false;
    card.number = i / 4;
    card.color = i % 4;
    if (card.number == 10 || card.number == 11) {
        card.value = 10;
    } else if (card.number == 9) {
        card.value = 1;
    } else if (card.number == 12) {
        card.value = 11;
    } else {
        card.value = card.number + 2;
    }
    return card;
}
 
struct decktype DeckInit() {
    struct decktype deck;
    deck.size = 52;
    for (int i=0; i<52; ++i) {
        deck.deck[i] = true;
    }
    return deck;
}
 
char *TextCard(struct cardtype &card) {
    char *str = (char *) malloc (22 * sizeof(char));
    sprintf(str,"%s of %s (%d)",card_num[card.number],card_type[card.color],card.value);
    return str;
}
 
// Main //
 
void main() {
    SeedRandom();
 
    bool IsGameOver = false;
    char WantCard;
 
    int totalvalue = 0;
 
    cout << "Welcome to blackjack!" << endl;
    struct decktype deck = DeckInit();
 
    while (!IsGameOver) {
        bool ValidChoice = false;
        while (!ValidChoice) {
            cout << "Do you want a card? (Y)es / (N)o" << endl;
            cin >> WantCard;
            if (WantCard == 'Y') {
                struct cardtype card = PickACard(deck);
                totalvalue += card.value;
                cout << "You received a " << TextCard(card) << ", current total value at " << totalvalue << "." << endl;
                if (totalvalue > 21) {
                    cout << "Sorry, you have exceeded 21 points and thus lost!" << endl;
                    IsGameOver = true;
                }
                if (totalvalue == 21) {
                    cout << "Congratulations, you have won!" << endl;
                    IsGameOver = true;
                }
                ValidChoice = true;
            } else if (WantCard == 'N') {
                cout << "You stopped prematurely, and since there isn't an opponent, you won :)" << endl;
                ValidChoice = true;
                IsGameOver = true;
            } else {
                cout << "Invalid choice, please try again";
            }
        }
 
    }
    cout << "The game is over now, thanks for playing!" << endl;
 
 cin.ignore();
 cin.get();
}
</ctime></iostream>
