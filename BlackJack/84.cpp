#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <QMessageBox>

#include "b.h"

class QLabel;
class QString;

using namespace std;

Card::Card(Rank r, Suit s, bool isFace):  rank(r), suit(s), isFaceUp(isFace)
{} 

int Card::getValue() const
{
	//if a cards is face down, its value is 0
	int value = 0;
	if (isFaceUp)
	{
		//value is number showing on card
		value = rank;
		// value is 10 for face cards
		if (value > 10)
            		value = 10;
    	}
    	return value;
}

void Card::flip()
{
    	isFaceUp = !isFaceUp;
}

string Card::convert()                               
{
	ostringstream oss;
 	string str;
    	const string RANKS[] = {"0", "14", "02", "03", "04", "05", "06", "07", 
			"08", "09","10", "11", "12", "13"};
    	const string SUITS[] = {"1", "2", "3", "4"};

    	if (isFaceUp)
        	oss << ":images/" << SUITS[suit] << RANKS[rank] << ".gif";
    	else
        	oss << ":images/" << "xx" << ".gif";

    	str = oss.str();
    	return str;
}

Hand::Hand()
{
	cards.reserve(5);
}

Hand::~Hand()  
{
	clear();
}

void Hand::add(Card* pCard) 
{
	cards.push_back(pCard);
}
 
void Hand::clear()
{
	//iterate through vector, freeing all memory on the heap
	vector<Card*>::iterator iter = cards.begin();
	for (iter = cards.begin(); iter != cards.end(); ++iter)
	{
		delete *iter;
        	*iter = 0;
    	}
    	//clear vector of pointers
    	cards.clear();
}

int Hand::getTotal() const
{
    	// if no cards in hand, return 0
    	if ( cards.empty())
        	return 0;
  
    	// if a first card has value of 0, then card is face down; return 0
    	if (cards[0]->getValue() == 0)
        	return 0;
    
    	//add up card values, treat each Ace as 1
    	int total = 0;
    	vector<Card*>::const_iterator iter;
    	for (iter = cards.begin(); iter != cards.end(); ++iter)
        	total += (*iter)->getValue();
                  
    	//determine if hand contains an Ace
    	bool containsAce = false;
    	for (iter = cards.begin(); iter != cards.end(); ++iter)
        	if ((*iter)->getValue() == Card::ACE)
	containsAce = true;
          
    	// if hand contains Ace and total is low enough, treat Ace as 11
    	if (containsAce && total <= 11)
        //add only 10 since we've already added 1 for the Ace
        	total += 10;   
            
    	return total;
}

AbstractPlayer::AbstractPlayer(const string& s): name(s)
{ }

AbstractPlayer::~AbstractPlayer()  
{ }

string AbstractPlayer::getName() const
{ 
    	return name;
}

QString& AbstractPlayer::getLabelQStr()  const
{ 
    	return labelQStr;
}

bool AbstractPlayer::isBusted() const
{ 
    	return (getTotal() > 21);
}

QString AbstractPlayer::bust() const
{
    	string str = "";
    	ostringstream oss ;
    	oss << "";
    	oss << name << " bust! ";
    	str = oss.str();
    	return str.c_str();
}

int Player::hitCount = 0;

Player::Player(const string& name):  AbstractPlayer(name)
{ } 

Player::~Player()
{ }
    
int Player::getHitCount() 
{
 	return hitCount;
}
   
void Player::resetHitCount() 
{
 	hitCount = 0;
}


void Player::setHitCount() 
{
 	hitCount++;
}

bool Player::isHitting() const
{
    	return getHitCount();
}

void Player::win(Canvas &cnvs;) const
{
    	string s = "";
    	s.append(name);
    	s.append(" won!");   
    	resultMessage(s);
	cnvs.setEnableHitStandButtons(false);
}

void Player::lose(Canvas &cnvs;) const
{
    	string s = "";
    	s.append(name);
    	s.append(" lost!");   
    	resultMessage(s);
	cnvs.setEnableHitStandButtons(false);
}

void Player::push(Canvas &cnvs;) const
{
    	string s = "";
    	s.append("Push!");   
    	resultMessage(s);
	cnvs.setEnableHitStandButtons(false);
}

void Player::resultMessage(string& s) const
{
    	QMessageBox msgBox;
	msgBox.setWindowTitle("Results ...");
    	msgBox.setText(s.c_str());
    	msgBox.exec();
}

House::House(const string& name) :  AbstractPlayer(name)
{ }

House::~House()
{ }

bool House::isHitting() const
{
	bool b = (getTotal() <= 16);
	return b;
}   

void House::flipFirstCard(bool b)
{
    	if (!(cards.empty()))  {
       		if(b) cards[0]->flip();
    	}
}

Deck::Deck()
{ 
    	cards.reserve(52);
    	populate();
}

Deck::~Deck()
{ }

void Deck::populate()
{
    	clear();
    	// create standard deck
    	for (int s = Card::SPADES; s <= Card::CLUBS; ++s)
        	for (int r = Card::ACE; r <= Card::KING; ++r)
                	add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
}

void Deck::shuffle()
{
    	random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& aHand)
{
	// cards : inherited from Hand class
    	if (!cards.empty()) {
        	aHand.add(cards.back());
        	cards.pop_back();
    	}
    	else {
        	cout << "Out of cards. Unable to deal.";
    	}
}

QString Deck::additionalCards(AbstractPlayer& aAbstractPlayer)
{
    	// continue to deal a card as long as generic player isn't busted and
    	// wants another hit
	if(aAbstractPlayer.isHitting() && !aAbstractPlayer.isBusted()) 
        	deal(aAbstractPlayer);
        return aAbstractPlayer.makeLabelString();
} 

Game::Game(const vector<string>& names, Canvas *cnv):canvas(cnv)
{
    	// create a vector of players from a vector of names       
    	vector<string>::const_iterator pName;
    	for (pName = names.begin(); pName != names.end(); ++pName)      
        	player.push_back(Player(*pName));

    	srand(time(0));    //seed the random number generator
    	deck.populate();
    	deck.shuffle();
}

Game::~Game()
{ }

void Game::gameStarted()
{          
        string pixStr = "";
    	QString qstr = " ";

    	//remove everyone's cards
	vector<Player>::iterator iterPlayer;
      	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) 
		iterPlayer->clear();
    	house.clear();

	Player::resetHitCount();

	canvas->clearIcons();
    	canvas->setResultLabel(qstr);
    	// by default, stand=false until user hit Stand button.
    	setStand(true);

    	// deal initial 2 cards to everyone
    	for (int i = 0; i < 2; ++i) {
        	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {     
        		deck.deal(*iterPlayer);
		}
        	deck.deal(house);

    	}
    
    	// hide house's first card
   	if(!Player::getHitCount())house.flipFirstCard(true);    
    
    	// display everyone's hand
    	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {      
        	qstr = iterPlayer->makeLabelString();
        	canvas->setPlayerStateLabel(qstr);
        	iterPlayer->makePixmaps(*iterPlayer);
		canvas->drawCards(*iterPlayer);
    	}
    	qstr = house.makeLabelString();
    	canvas->setHostStateLabel(qstr);
    	house.makePixmaps(house);
	canvas->drawCards(house);
}

void Game::hitSelected()
{         

	QString qstr;
	vector<Player>::iterator iterPlayer;
	// reveal house's first card which has been hidden
    	if(!Player::getHitCount()) house.flipFirstCard(true);    

        //deal additional cards to players
        for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {
      		iterPlayer->setHitCount();  
                qstr = deck.additionalCards(*iterPlayer);
                canvas->setPlayerStateLabel(qstr);
        	iterPlayer->makePixmaps(*iterPlayer);
		canvas->drawCards(*iterPlayer);
        }

	
    	//deal additional cards to house
    	qstr = deck.additionalCards(house);
        house.makeLabelString();
        canvas->setHostStateLabel(qstr);
    	house.makePixmaps(house);
	canvas->drawCards(house);

      	if(house.isBusted()) {
            	qstr =  house.bust();
            	canvas->setResultLabel(qstr);
        	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {
        		if (!iterPlayer->isBusted()) {
				iterPlayer-> win(*canvas);
			}
			// both busted
			else {
				iterPlayer->lose(*canvas);
			}
    		}
	}
	else {
        	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {
			// player is still in, not busted
        		if (!(iterPlayer->isBusted())) {
				// player still hitting
				if(iterPlayer->isHitting()) 
					break; 
				// player stand
				else {
					while(house.isHitting()) {
    					//deal additional cards to house
    						qstr = deck.additionalCards(house);
        					house.makeLabelString();
    						house.makePixmaps(house);
						canvas->drawCards(house);
					}
				}
				
				if(iterPlayer-> getTotal() > house.getTotal()) {
						iterPlayer->win(*canvas);
				}
				else if(iterPlayer->getTotal() < house.getTotal())
						iterPlayer->lose(*canvas);
				else
						iterPlayer->push(*canvas);
			}
			// player busted
              		else {
				iterPlayer->lose(*canvas);
            			qstr = iterPlayer->bust();
            			canvas->setResultLabel(qstr);
			}
    		}
	}
}

// Player opted to stand, House will hit if total <= 16 
void Game::standSelected()
{         
	vector<Player>::iterator iterPlayer;
        QString qstr;

	if(Player::getHitCount())  {
    	  	house.flipFirstCard(false);    
		Player::setHitCount();
	}
	else {
    	  	house.flipFirstCard(true);    
		Player::setHitCount();
	}

    	//deal additional cards to house
    	qstr = deck.additionalCards(house);
        house.makeLabelString();
        canvas->setHostStateLabel(qstr);
    	house.makePixmaps(house);
	canvas->drawCards(house);

      	if(house.isBusted()) {
            	qstr = house.bust();
            	canvas->setResultLabel(qstr);
        	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {
        		if (!iterPlayer->isBusted()) {
				iterPlayer-> win(*canvas);
			}
    		}
	}
	else {
        	for (iterPlayer = player.begin(); iterPlayer != player.end(); ++iterPlayer) {
			if(!house.isHitting()) {
				if(iterPlayer-> getTotal() > house.getTotal())
					iterPlayer->win(*canvas);
				else if(iterPlayer->getTotal() < house.getTotal())
					iterPlayer->lose(*canvas);
				else
					iterPlayer->push(*canvas);
			}
		}
	}
}

void Game::setStand(bool b)
{         
	stand = b;
}


bool Game::getStand()
{         
	return stand;
}

// overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    	const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", 
                            "10", "J", "Q", "K"};
    	const string SUITS[] = {"s", "h", "d", "c"};

    	if (aCard.isFaceUp)
        	os << RANKS[aCard.rank] << SUITS[aCard.suit];
    	else
        	os << "XX";

    	return os;
}

//overloads << operator so a AbstractPlayer object can be sent to cout
ostream& operator<<(ostream& os, const AbstractPlayer& aAbstractPlayer)
{
    	string str = "";
    	ostringstream oss;
    	oss << "" ;
    	oss << aAbstractPlayer.name << ":   ";
    
    	vector<Card*>::const_iterator pCard;
    	if (!aAbstractPlayer.cards.empty()) {
        	for (pCard = aAbstractPlayer.cards.begin(); 
             		pCard != aAbstractPlayer.cards.end(); ++pCard) {
            	oss << *(*pCard) << "   ";
        	}
        	if (aAbstractPlayer.getTotal() != 0) {
            		oss << "(" << aAbstractPlayer.getTotal() << ")";
        	}
    	}
    	else {
        	oss << "<empty>";
    	}
        
    	str = oss.str();
    	aAbstractPlayer.labelQStr = str.c_str();
    	return os;
}

void AbstractPlayer::makePixmaps(AbstractPlayer &ap;) 
{ }

vector<QPixmap>& Player::getPixmaps() 
{
	return pixmaps;
}

vector<QPixmap>& House::getPixmaps() 
{
	return pixmaps;
}

void Player::makePixmaps(AbstractPlayer &ab;) 
{
       	string str;
    	vector<Card*>::const_iterator pCard;
    	if (!cards.empty()) {
		
                Player *ptr = dynamic_cast<Player *> (&ab;);

		ptr->pixmaps.clear();
        	for (pCard = cards.begin(); 
             		pCard != cards.end(); ++pCard) {
			str = (*pCard)->convert();
		  	pixmaps.push_back(QPixmap(str.c_str()));
			
        	}
        	if (getTotal() != 0) {
            	//	oss << "(" << getTotal() << ")";
        	}
    	}
}

void House::makePixmaps(AbstractPlayer &ab;) 
{
       	string str;
    	vector<Card*>::const_iterator pCard;
    	if (!cards.empty()) {
		
                House *ptr = dynamic_cast<House *> (&ab;);

		ptr->pixmaps.clear();
        	for (pCard = cards.begin(); 
             		pCard != cards.end(); ++pCard) {
			str = (*pCard)->convert();
		  	pixmaps.push_back(QPixmap(str.c_str()));
			
        	}
        	if (getTotal() != 0) {
            	//	oss << "(" << getTotal() << ")";
        	}
    	}
}

QString AbstractPlayer::makeLabelString()
{
    	string str = "";
    	ostringstream oss;
    	oss << "" ;
    	oss << name << ":   ";
    
    	vector<Card*>::const_iterator pCard;
    	if (!cards.empty()) {
        	for (pCard = cards.begin(); 
             		pCard != cards.end(); ++pCard) {
            		oss << *(*pCard) << "   ";
        	}
        	if (getTotal() != 0) {
            		oss << "(" << getTotal() << ")";
        	}
    	}
    	else {
        	oss << "<empty>";
    	}
        
    	str = oss.str();
    	return str.c_str();
}
