#include<iostream>
#include<stdlib.h>
using namespace std;
void bottle(int n)
{
	if(n==1)
	{
		cout<<"6\t1\t2\n\n";
		for(int i=1;i<=5;i++)
		{
			cout<<"    ";
			for(int j=1;j<=5;j++)
			{
				if(j==3 || i==2&&(j==1||j==5))
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
		cout<<"5\t4\t3\n";
	}
	else if(n==2)
	{
		cout<<"6\t1\t2\n\n";
		for(int i=1;i<=5;i++)
		{
			cout<<"    ";
			for(int j=1;j<=5;j++)
			{
				if(j==3 || i==4&&(j==1||j==5))
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
		cout<<"5\t4\t3\n";
	}
	else if(n==3)
	{
		cout<<"6\t1\t2\n\n";
		for(int i=1;i<=5;i++)
		{
			cout<<"    ";
			for(int j=1;j<=5;j++)
			{
				if((i==j) || (i==1&&j==3)||(i==3&&j==1))
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
		cout<<"5\t4\t3\n";
	}
	else if(n==4)
	{
		cout<<"6\t1\t2\n\n";
		for(int i=1;i<=5;i++)
		{
			cout<<"    ";
			for(int j=1;j<=5;j++)
			{
				if(((i+j)==6) || (i==1&&j==3)||(i==3&&j==5))
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
		cout<<"5\t4\t3\n";
	}

}
void main()
{
	srand(time(NULL));

	z:
	cout<<"Enter 1 to play \n";
	int m=rand()%4+1;
	cout<<m<<endl;
	bottle(1);
	cout<<endl;
	bottle(2);
	cout<<endl;
	bottle(3);
	cout<<endl;
	bottle(4);
}
