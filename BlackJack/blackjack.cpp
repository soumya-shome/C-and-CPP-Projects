#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int  main()
{
	srand(time(NULL));
	int i,j,k;
	cout << "                             ";
	char str[] = {"WELCOME TO BLACK JACK!!"};
	int ben = strlen(str);
	for(i=0;i<ben;i++)
		{
		putchar(str[i]);
		delay(90);
		}
	delay(1000);
	clrscr();
	cout <<"                     " << endl;
	delay(90);
	cout <<" ---------   ---------   ---------   ---------   " << endl;
	delay(490);
	cout <<"|A        | |K        | |Q        | |J        |   "<< endl;
	delay(490);
	cout <<"|         | |         | |         | |         |   "<<endl;
	delay(490);
	cout <<"|         | |         | |         | |         |   "<<endl;
	delay(490);
	cout <<"|         | |         | |         | |         |   "<<endl;
	delay(490);
	cout <<"|        A| |        K| |        Q| |        J|   "<<endl;
	delay(490);
	cout <<" ---------   ---------   ---------   ---------   "<<endl;
	delay(1000);
	clrscr();
	
	a:
	cout << "                      MENU : " << endl;
	cout << "                    <1> PLAY" << endl << "                    <2> EXIT" << endl ;
	cin >> i;
	switch(i)
		{
			case 1 :
			{
			clrscr();
			cout << endl <<  "press 1 and enter to start" ;
			cin >> j;
			if(j==1)
			{
				clrscr();
				int pt;
				pt= rand() %10;
				cout <<"your hand: "<< pt << endl;
				do
					{
						cout << "press 1 to hit or 2 to stand"<<endl;
						int ch;
						cin >> ch;
						if(ch==1)
							{
							pt = pt + rand()%10;
							cout << "your hand: " << pt<<endl;
							}
						if(ch==2)
							{
								cout << endl;
								cout << " now its the dealer's turn"<< endl;
								int deal;
								deal = random(12)+10;
								cout << "dealer : " << deal << "      you : " << pt<< endl;
								if(pt == 21)
									cout << "YOU WIN!!!!!";
								if(pt> deal)
									cout << "you WIN!!"<<endl;
								if(pt < deal && deal <=21)
									cout << " sorry you loose!"<<endl;
								if(pt==deal)
									cout <<" its a push!!" << endl;
								if(deal > 21)
									cout << " YOU WIN!! "<<endl ;
								if(pt>21)
									cout <<"busted!!!!"<<endl;
								break;
							}
				}while(pt<21);
			cout << "Do you want to play again??<y-1/n-2>"<<endl ;
			int g;
	
			b:
			cin >> g;
			if(g == 2)
				exit(0);
			if(g == 1)
				goto a;
			else
				cout << " you can enter only 1 or 2";
				goto b; 
			}
	     }
	
	break;
	
	
	case 2 : exit(0);
	break;
	default :{
	cout << "you can enter only '1' or '2'"<< endl;
	goto a;}
	}
	getch();
	
	}
	

