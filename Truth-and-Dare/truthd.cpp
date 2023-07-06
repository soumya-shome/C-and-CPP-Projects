#include<iostream>
#include<stdlib.h>
using namespace std;
class td
{
public:
	void bottle(int n)
	{
		if(n==1)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if(j==4 || i==3&&(j==2||j==6)||(i==2&&(j==3||j==5)))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
		}
		else if(n==2)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if(j==4 || i==5&&(j==2||j==6)||(i==6&&(j==3||j==5)))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
		}
		else if(n==3)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if((i==j) || (i==1&&(j==2||j==3||j==4)) || ((i==2||i==3||i==4)&&j==1))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
		}
		else if(n==4)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if(((i+j)==8) || (i==1&&(j==4||j==5||j==6)) || ((i==2||i==3||i==4)&&j==7))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
			}
		else if(n==5)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if((i==j) || (i==7&&(j==4||j==5||j==6)) || ((i==4||i==5||i==6)&&j==7))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
		}
		else if(n==6)
		{
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				for(int j=1;j<=7;j++)
				{
					if(((i+j)==8) || (i==7&&(j==2||j==3||j==4)) || ((i==4||i==5||i==6)&&j==1))
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;	
			}
			cout<<endl;
			cout<<"6\t5\t4\n";
		}
		getch();
	}


	void T_K()
	{
		srand(time(NULL));
		int y=rand()%8+1;
		switch(y)
		{
			case 1:
				cout<<"\n Tell about your stangest dream ";
			break;	

			case 2:
				cout<<"\n Have you ever wet your bed? ";
			break;
	
			case 3:
				cout<<"\n Have you ever cheated in a exam? ";
			break;
	
			case 4:
			cout<<"\n Tell You worst grades ";
			break;

			case 5:
				cout<<"\n Name The Person you fear the most ";
			break;

			case 6:
				cout<<"\n Tell about the craziest thing you have ever done ";
			break;
	
			case 7:
				cout<<"\n What question would you like to ask to the person opposite to you? ";
			break;

			case 8:
				cout<<"\n What animal are you afraid of the most? ";
			break;
		}
		getch();
	}

	void T_T()
	{
		srand(time(NULL));
		int y=rand()%8+1;
		switch(y)
		{
			case 1:
				cout<<"\n What is you least favorite thing about the person on your left? ";
			break;

			case 2:
				cout<<"\n Do you Google new people you meet? ";
			break;
	
			case 3:
				cout<<"\n If you could Invent anything, What would it be? ";
			break;
	
			case 4:
				cout<<"\n Your biggestr fear? ";
			break;

			case 5:
				cout<<"\n Where is the strangest place you have peed? ";
			break;

			case 6:
				cout<<"\n Describe yourself in 3 words ";
			break;

			case 7:
				cout<<"\n What's your most embarrassing nickname? ";
			break;

			case 8:
				cout<<"\n Have you ever worn the opposite sex's clothing? ";
			break;
		}
		getch();
	}
};


void main()
{
	td ob;
	srand(time(NULL));
	cout<<"Enter 1 to play \n";
	int m=rand()%6+1;
	cout<<m<<endl;
	td.bottle(m);
	td.T_K();
	td.T_T();
}
