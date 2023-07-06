#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include<ctime>
#include<cstdlib>

using namespace std;


int m1[4];
int m2[2];

int checkwin();
void board();
void gamerule();
void input();
int gameplay();
int toss();
void match1();
void maych2();
void final();


class data_control
{
	private:
		string name;
	public:
		void input(long int number)
		{
 			ofstream tictac("tictactoe.txt", ios::app);
 			system("cls");
 			cout<<"Player number:-"<<number<<endl;
 			cout << "Enter the name" << endl;
 			cin >> name;
 			cin.sync();
 			tictac << number << ' ' << name <<endl;     
 			tictac.close();
			system("cls"); 
     	}
     	
     	void displayall()
		{
			long int number;
     		ifstream tictac("tictactoe.txt");
     		system ("CLS");
    		cout << "Payers name"<< endl;
    		cout << "Number" << '\t' << "Name" <<endl;
     		cout << "---------------" << endl;
     		while (tictac>>number >> name)
			{
     			cout << number << '\t' << name <<endl ;
     		}
     		cin.get();    
     	}
     	
     	void deleteFile()
		{
     		ofstream tictac("tictactoe.txt");
     	}
     	
     	string searchname(int a)
 		{
 			long int number;
     		ifstream tictac("tictactoe.txt");
     		while (tictac >> number >> name)
			{
           		if (number==a)
				{
                   	return name;
                }
            }
           	cin.get();
        }
};

class play
{
	private:
		char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
		int checkwin()
		{
			if (square[1] == square[2] && square[2] == square[3])
			{
				return 1;
			}
			else if (square[4] == square[5] && square[5] == square[6])
			{
				return 1;
			}
			else if (square[7] == square[8] && square[8] == square[9])
			{
				return 1;
			}
			else if (square[1] == square[4] && square[4] == square[7])
			{
				return 1;
			}
			else if (square[2] == square[5] && square[5] == square[8])
			{
				return 1;
			}
			else if (square[3] == square[6] && square[6] == square[9])
			{
				return 1;
			}	
			else if (square[1] == square[5] && square[5] == square[9])
			{
				return 1;
			}
			else if (square[3] == square[5] && square[5] == square[7])
			{
				return 1;
			}
			else if (square[1] != '1' && square[2] != '2' && square[3] != '3'  && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		void board()
		{
			system("cls");
			cout << "\n\n\tTic Tac Toe\n\n";
		
			cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
			cout << endl;
		
			cout << "     |     |     " << endl;
			cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
		
			cout << "_____|_____|_____" << endl;
			cout << "     |     |     " << endl;
		
			cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
		
			cout << "_____|_____|_____" << endl;
			cout << "     |     |     " << endl;
		
			cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
		
			cout << "     |     |     " << endl << endl;
		}
	public:
		int gameplay()
		{
			system("cls");
			int player = 1,i,choice;
			char mark;
			do
			{
				board();
				player=(player%2)?1:2;
				cout << "Player " << player << ", enter a number:  ";
				cin >> choice;
				mark=(player == 1) ? 'X' : 'O';
				if (choice == 1 && square[1] == '1')
					square[1] = mark;
				else if (choice == 2 && square[2] == '2')
					square[2] = mark;
				else if (choice == 3 && square[3] == '3')
	
				square[3] = mark;
				else if (choice == 4 && square[4] == '4')
	
					square[4] = mark;
				else if (choice == 5 && square[5] == '5')
		
					square[5] = mark;
				else if (choice == 6 && square[6] == '6')
		
					square[6] = mark;
				else if (choice == 7 && square[7] == '7')
	
					square[7] = mark;
				else if (choice == 8 && square[8] == '8')
	
					square[8] = mark;
				else if (choice == 9 && square[9] == '9')
	
					square[9] = mark;
				else
				{
					cout<<"Invalid move ";
	
					player--;
					cin.ignore();
					cin.get();
				}
				i=checkwin();
	
				player++;
			}while(i==-1);
		
			board();
		
			if(i==1)
			{
				return player;
				
			}
			else
			{
				return 0;	
			}
		}
};

void input()
{
	data_control ob;
	ob.deleteFile();
	for(int i=1;i<=8;i++)
	{	
		ob.input(i);
	}
	ob.displayall();
	system("pause");
}

void match1()
{
	data_control obj;
	int w=0;
	for(int i=1;i<=8;i++)
	{
		play ob;
		string name=obj.searchname(i);
		int u;
		if(i%2==0)
		{
			cout<<"Player 2 ("<<name<<") "<<endl;
			system("pause");
			int y=ob.gameplay();
			if(y==0)
			{
				cout<<"It's a DRAW\n";
				cout<<"A Toss will now decide \n";
				u=toss();
				if(u==1)
				{
					name=obj.searchname(i-1);
					m1[w]=i-1;
					cout<<"Player 1 ("<<name<<") is the winner and Qualify for next round \n";
				}
				else
				{
					cout<<"Player 2 ("<<name<<") is the winner and Qualify for next round \n";
					m1[w]=i;
				}
				w++;
				system("pause");
				system("cls");
			}
			else if(y>0)
			{
				y--;
				if(y==1)
				{
					name=obj.searchname(i-1);
					cout<<"Player 1 ("<<name<<") is the winner and Qualify for next round \n";
					m1[w]=i-1;
				}
				else
				{
					m1[w]=i;
					cout<<"Player 2 ("<<name<<") is the winner and Qualify for next round \n";	
				}
				w++;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout<<"Player 1("<<name<<") vs ";
		}
	}
}

void match2()
{
	data_control obj;
	int w=0;
	for(int j=1;j<=4;j++)
	{
		play ob;
		int i=m1[(j-1)];
		string name=obj.searchname(i);
		int u;
		if(j%2==0)
		{
			cout<<"Player 2 ("<<name<<") "<<endl;
			system("pause");
			int y=ob.gameplay();
			if(y==0)
			{
				cout<<"It's a DRAW\n";
				cout<<"A Toss will now decide \n";
				u=toss();
				if(u==1)
				{
					name=obj.searchname(m1[j-2]);
					m2[w]=m1[j-2];
					cout<<"Player 1 ("<<name<<") is the winner and Qualify Semi-Final \n";
				}
				else
				{
					cout<<"Player 2 ("<<name<<") is the winner and Qualify for Semi-Final \n";
					m2[w]=i;
				}
				w++;
				system("pause");
				system("cls");
			}
			else if(y>0)
			{
				if(y==1)
				{
					name=obj.searchname(m1[j-2]);
					cout<<"Player 1 ("<<name<<") is the winner and Qualify for Semi-Final \n";
					m2[w]=m1[j-2];
				}
				else
				{
					m2[w]=i;
					cout<<"Player 2 ("<<name<<") is the winner and Qualify for Semi-Final \n";	
				}
				w++;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout<<"Player 1("<<name<<") vs ";
		}
	}
}

void final()
{
	data_control obj;
	play ob;
	cout<<"\t\t\t\tFINAL\n";
	string name=obj.searchname(m2[0]);
	cout<<"Player 1("<<name<<") VS ";
	string name2=obj.searchname(m2[1]);
	cout<<"Player 2("<<name2<<")"<<endl;
	system("pause");
	system("cls");
	int z=ob.gameplay();
	z--;
	if(z==1)
	{
		cout<<"Player 1 ("<<name<<") is the WINNER\n ";
	}
	else if(z==2)
	{
		cout<<"Player 2 ("<<name2<<") is the WINNER\n ";
	}
	else if(z==0)
	{
		cout<<"It's a DRAW\n";
		cout<<"A Toss will now decide \n";
		int u=toss();
		if(u==1)
		{
			cout<<"Player 1 ("<<name<<") is the WINNER\n ";
		}
		else if(u==2)
		{
			cout<<"Player 2 ("<<name2<<") is the WINNER\n ";
		}
	}
	cout<<"\t\t\t\tCONGRATULATIONS !!";
}

int toss()
{
	srand(time(0));
    int n=(rand()%2)+1;
    return n;
}

void gamerule()
{
	cout<<"LETS PLAY TIC TAK TOE";
	cout<<"\nRULES: \n";
	cout<<"1.ONLY APPLY ONE DIGIT NUMBER FROM 1 TO 9";
	cout<<"\n2.IF THE GAME BECOMES DRAW A TOSS IS DONE,THE WINNING PLAYER WOULD PROCEED TO THE NEXT ROUND";
	cout<<endl;
	cout<<"\t1   2    3   4    5   6    7   8"<<endl;
	cout<<"\t|___|    |___|    |___|    |___|"<<endl;
	cout<<"\t  |________|        |________|"<<endl;
	cout<<"\t       |_________________|"<<endl;
	cout<<"\t                |"<<endl;
	cout<<"\t             Winner"<<endl;
	system("pause");
}


main()
{
	gamerule();
	system("cls");
	input();
	system("cls");
	match1();
	system("pause");
	system("cls");
	match2();
	system("cls");
	final();
}
