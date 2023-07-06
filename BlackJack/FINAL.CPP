#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
void main()
{
	srand(time(NULL));
	clrscr();
	int i,j,k,q;
	cout<<"                ";
	char str[]={"Welcome to Black Jack!!!"};
	int ben=strlen(str);
	for(i=0;i<ben;i++)
	{
		putchar(str[i]);
		delay(90);
	}
	delay(1000);
	clrscr();
	cout<<"                 "<<endl;
	delay(90);
	cout<<"----- ----- ----- -----"<<endl;
	delay(490);
	cout<<"|A   ||K    ||Q   ||J   |"<<endl;
	delay(490);
	cout<<"|     ||    ||    ||    |"<<endl;
	delay(490);
	cout<<"|     ||    ||    ||    |"<<endl;
	delay(490);
	cout<<"|     ||    ||    ||    |"<<endl;
	delay(490);
	cout<<"|    A||   K||   Q||   J|"<<endl;
	delay(490);
	cout<<"----- ----- ----- -----"<<endl;
	delay(1000);
	clrscr();

	a:
	cout<<"     MENU:"<<endl;
	cout<<"     <1>PLAY"<<endl<<"     <2>EXIT"<<endl;
	cin>>i;
	switch(i)
	{
		case 1:
			clrscr();
			cout<<endl<<"Press 1 and enter to start";
			cin>>j;
			if(j==1)
			{
				clrscr();
				int pt,deal=0;
				pt=rand()%10;
				cout<<"your hand:"<<pt<<endl;

				do
				{
					cout<<"press 1 to hit or 2 to stand"<<endl;
					int ch;
					cin>>ch;
					if(ch==1)
					{
						pt=pt+rand()%10;
						cout<<"your hand:"<<pt<<endl;
					}
					if(ch==2)
					{
						cout<<endl;
						cout<<"now its dealer's turn"<<endl;

						deal=deal+rand()%10;
						cout<<"dealer: "<<deal<<"  you:"<<pt<<endl;
						 if(pt==21&&deal<21)
						 {
							q=1;
							break;
						 }
						 if(deal==21 && pt<21)
						 {

							q=-1;
							break;
						 }
						 if(pt==deal)
						 {
							q=0;
							break;
						 }
						 if(deal>21 && pt<21)
						 {
							q=1;
							break;
						 }
						 if(pt>21 && deal<21)
						 {
							q=-1;
							break;
						 }
						}
				}while(pt<21);

				if(q==1)
				{
				cout<<"You Won";
				}
				else if(q==-1)
				{
				cout<<"you Lose";
				}
				else if(q==0)
				{
				cout<<"its  a Push";
				}
				else if(q==-2)
				{
				cout<<"Busted";
				}
			  cout<<"Do you want to play again??<y-1>/<n-2>"<<endl;
			  char g;

			  b:
			  cin>>g;
			  if(g=='2')
			  {
				exit(0);
			  }

			  if(g=='1')
			  {
				goto a;
			  }
			  else
			  {
				cout<<"you can enter only 1 or two";
				goto b;
			  }
			}
		break;

		case 2:
			exit(0);
		break;

		default:
			cout<<"you can enter only 1 or 2"<<endl;
			goto a;
		break;
	}
}