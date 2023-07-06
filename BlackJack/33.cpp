/* BlackJack
Nathan Guse 1/19/06   */

#include<iostream>
#include<lvp/random.h>
using  namespace std;
//-------------------------------------------------------------------

	/* Errors found:

	*/

	/* Things needed to be changed/added

	*/

//-------------------------------------------------------------------

void Intro();
void Shuffle(int deck[52]);
void Deal(int cards[2][5], int deck[52], int &numCard);
void UserHitStay(int cards[2][5], int deck[52], int &numCard);
void CompHitStay(int cards[2][5], int deck[52], int &numCard);
void DisplayYouCards(int cards[2][5]);
void DisplayCompCards(int cards[2][5], bool userDone);
void CardValue(int card);
void FindTotals(int cards[2][5], int totals[2]);
void FindWin(int cards[2][5], int scores[3]);
void NumWinLose(int scores[3]);
char PlayAgain(int scores[3]);

void DisplayAllCards(int deck[52]); //remove before final

//-------------------------------------------------------------------

int main()
{
	int numCard=0; //to know what card you are on

	int totals[2]={0,0}; // count totals for each hand (0 is users hand, 1 is computers hand)
	int scores[3]={0,0,0}; // for scoring
	int deck[52]; // the deck

	int cards[2][5]; //cards in each hand(0 is users hand, 1 is computers hand)

	char runAgain; //used to know if the user wants to play again
	
//--------------------------------

	Intro();
	
	Shuffle(deck);

	do{
		if (numCard>40)
		{
			Shuffle(deck);
			numCard=0;
		}

//		DisplayAllCards(deck); // Remove before the final

		for (int a=0; a<=4; a++) //resets your hand
		{
			cards[0][a]=-1;
			cards[1][a]=-1;
		}

		Deal(cards, deck, numCard);

		DisplayYouCards(cards);

		DisplayCompCards(cards, false);

		UserHitStay(cards, deck, numCard);

		CompHitStay(cards, deck, numCard);

		FindWin(cards, scores);

		runAgain=(PlayAgain(scores));
		if((runAgain=='y')||(runAgain=='Y')) //to play again
		{
			cout<<endl;
			cout<<"--------------------------------------------------"<<endl;
		}
		else if ((runAgain=='n')||(runAgain=='N')) //to quit
		{
			cout<<endl;
			break;
		}
	}while ((runAgain!='n')&&(runAgain!='N'));

	return(0);
}

//-------------------------------------------------------------------

void Intro()
// Displays the intro
{
	cout<<"##############################################################"<<endl 
		<<"## Program Title: BlackJack"<<endl
		<<"## Program Author: EXreaction(Nathan Guse) <www.gotechzilla.com>"<<endl
		<<"## Program Description: A Blackjack game"<<endl
		<<"## Program Version: 1.0"<<endl
		<<"###############################################################"<<endl<<endl;
}

//-------------------------------------------------------------------

void Shuffle(int deck[52])
// Shuffle the cards
{
	bool picked[52];
	int card, a=0;

	randomize();

	for (a; a<=51; a++)
	{
		deck[a]=-1;
		picked[a]=false;
	}

	for (int b=0; b<=51; b++)
	{
		do{
			card = random(52);
			if (picked[card]==false)
			{
				deck[b]=card;
				picked[card]=true;
			}
		}while (deck[b]==-1);
	}
}

//-------------------------------------------------------------------

void Deal(int cards[2][5], int deck[52], int &numCard)
// Deals out the first cards
{
	int a=0;

	for (a;a<=1;a++)
	{
		cards[0][a]=(deck[numCard]);
		numCard++;
		cards[1][a]=(deck[numCard]);
		numCard++;
	}
}

//-------------------------------------------------------------------

void UserHitStay(int cards[2][5], int deck[52], int &numCard)
// Find out if the user wants to hit, or stay
{
	int totals[2];

	char hs;
	
	for (int a=2; a<=4; a++)
	{
		FindTotals(cards, totals); 
		if (totals[0]>=21)// if the total of their hands is >=21 then don't ask if they want to hit or stay
		{
			break;
		}

		cout<<endl<<"You have "<<totals[0]<<" would you like to hit(h), or stay(s)?";
		cin>>hs;
		if ((hs=='h')||(hs=='H'))
		{
			cards[0][a]=deck[numCard];
			numCard++;
			DisplayYouCards(cards);
		}
		else if ((hs=='s')||(hs=='S'))
		{
			DisplayYouCards(cards);
			break;
		}
		else
		{
			a--;
			cout<<hs<<" is not acceptable, enter in either a 'h', or a 's'"<<endl;
		}
	}

}

//-------------------------------------------------------------------

void CompHitStay(int cards[2][5], int deck[52], int &numCard)
// Find out if the computer should hit, or stay
{
	int totals[2];

	FindTotals(cards, totals);

	if ((totals[0]<=21)&&(cards[0][4]==-1))
	{
		if ((totals[1]==21)&&(cards[1][2]==-1))
		{
		}
		else
		{
			for (int a=2; a<=4; a++)
			{
				FindTotals(cards, totals);

				if (totals[1]<=16)
				{
					cards[1][a]=deck[numCard];
					numCard++;
				}
//				else if (compTot==17) //needs work yet
//				{
//					if (((compCard[0]/4)==0)||((compCard[1]/4)==0)||((compCard[2]/4)==0)||((compCard[3]/4)==0))
//					{
//						compCard[a]=deck[numCard];
//						numCard++;
//					}
//				}
				else
				{
					break;
				}
			}
		}
	}
	DisplayCompCards(cards, true);
}

//-------------------------------------------------------------------

void DisplayYouCards(int cards[2][5])
// Displays the User's cards
{	
	cout<<"Your Cards:"<<endl;
	for (int a=0; a<=4; a++)
	{
		if (cards[0][a]>=0)
		{
			CardValue(cards[0][a]);
		}
	}
}

//-------------------------------------------------------------------

void DisplayCompCards(int cards[2][5], bool userDone)
// Displays the Computer's cards
{
	if (userDone==true)
	{
		cout<<endl<<"Computers Cards:"<<endl;
		for (int a=0; a<=4; a++)
		{
			if (cards[1][a]>=0)
			{
				CardValue(cards[1][a]);
			}
		}
	}
	else
	{
		cout<<endl<<"Computers Cards:"<<endl;
		CardValue(cards[1][0]);
	}
}

//-------------------------------------------------------------------

void CardValue(int card)
// Displays what each card really means
{
	switch (card/4)
	{
	case 0:
		cout<<"Ace";
		break;
	case 10:
		cout<<"Jack";
		break;
	case 11:
		cout<<"Queen";
		break;
	case 12:
		cout<<"King";
		break;
	default:
		cout<<(card/4+1);
	}

	cout<<" of ";

	switch (card%4)
	{
	case 0:
		cout<<"Clubs"<<endl;
		break;
	case 1:
		cout<<"Spades"<<endl;
		break;
	case 2:
		cout<<"Hearts"<<endl;
		break;
	case 3:
		cout<<"Diamonds"<<endl;
		break;
	}
}

//-------------------------------------------------------------------

void FindTotals(int cards[2][5], int totals[2])
// Finds the totals
{
	totals[0]=0;
	totals[1]=0;

	for (int a=0; a<=4; a++) // Find the user's, and comp's total
	{
		// User's total section
		if ((cards[0][a]/4)>=10)
		{
			totals[0]+=10;
		}
		else if (cards[0][a]!=-1)
		{
			totals[0]+=((cards[0][a]/4)+1);
		}
		
		// Comp's total section
		if ((cards[1][a]/4)>=10)
		{
			totals[1]+=10;
		}
		else if (cards[1][a]!=-1)
		{
			totals[1]+=((cards[1][a]/4)+1);
		}
	}
	for (int b=0; b<=4; b++)
	{
		if ((cards[0][b]==0)||(cards[0][b]==1)||(cards[0][b]==2)||(cards[0][b]==3))
		{
			if (totals[0]<12)
			{
				totals[0]+=10;
			}
		}
		if ((cards[1][b]==0)||(cards[1][b]==1)||(cards[1][b]==2)||(cards[1][b]==3))
		{
			if (totals[1]<12)
			{
				totals[1]+=10;
			}
		}
	}
}

//-------------------------------------------------------------------

void FindWin(int cards[2][5], int scores[3])
// Find out the total and find out who wins
{
	int totals[2];

	FindTotals(cards, totals);

	cout<<endl;

	if ((totals[0]==21)&&(cards[0][2]==-1))
	{
		if ((totals[1]==21)&&(cards[1][2]==-1))
		{
			cout<<"We both have BlackJack!"<<endl;
			scores[2]++;
		}
		else
		{
			cout<<"You have Blackjack!"<<endl;
			scores[0]++;
		}
	}
	else if ((totals[1]==21)&&(cards[1][2]==-1))
	{
		cout<<"I have Blackjack!"<<endl;
		scores[1]++;
	}
	else
	{
		if (totals[0]>21)
		{
			cout<<"You busted("<<totals[0]<<"), so you lose!";
			scores[1]++;
		}
		else if (totals[1]>21)
		{
			cout<<"I busted("<<totals[1]<<"), so you win!";
			scores[0]++;
		}
		else if ((cards[0][4]!=-1)&&(totals[0]<22))
		{
			cout<<"You have 5 cards that add up to less than 22, so you win!";
			scores[0]++;
		}
		else if ((cards[1][4]!=-1)&&(totals[1]<22))
		{
			cout<<"I have 5 cards that add up to less than 22, so you lose!";
			scores[1]++;
		}
		else
		{
			cout<<endl<<"You have "<<totals[0]<<" and I have "<<totals[1]<<" so ";
			if (totals[0]>totals[1])
			{
				cout<<"you win!";
				scores[0]++;
			}
			else if (totals[1]>totals[0])
			{
				cout<<"you lose!";
				scores[1]++;
			}
			else
			{
				cout<<"we pushed!";
				scores[2]++;
			}
		}
	}

}

//-------------------------------------------------------------------

void NumWinLose(int scores[3])
// Display how many times they have won/lost
{
		cout<<endl<<"-------------------------"<<endl;
		cout<<"You have won "<<scores[0]<<" times."<<endl;
		cout<<"The computer has won "<<scores[1]<<" times."<<endl;
		cout<<"We have tied "<<scores[2]<<" times."<<endl;
		cout<<"-------------------------"<<endl;
}

//-------------------------------------------------------------------

char PlayAgain(int scores[3])
// Ask if they would like to play again, or see the scores
{
	char again='n';
	
	do{
		cout<<endl<<"Would you like to play again (y or n), or see the score(s)?";
		cin>>again;
		
		if ((again=='s')||(again=='S')) //to see the scores
		{
			NumWinLose(scores);
		}
		else if ((again!='n')&&(again!='N')&&(again!='y')&&(again!='Y'))
		{
			cout<<again<<" is not acceptable, enter in either a 'n', 'y', or a 's'"<<endl;
		}
	}while ((again!='n')&&(again!='N')&&(again!='y')&&(again!='Y'));

	return(again);
}

//-------------------------------------------------------------------

void DisplayAllCards(int deck[52]) //used to make sure every card is displaying correctly, remove before final
{
	for (int a=0; a<=51; a++)
	{
		CardValue(deck[a]);
	}
}


