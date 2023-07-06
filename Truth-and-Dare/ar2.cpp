#include<iostream>
using namespace std;
main()
{
	
	
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if((i==j) || (i==1&&j==3)||(i==2&&j==1))
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(((i+j)==6) || (i==1&&(j==3||j==2)||(i==2i==3)&&j==5))
			{
				cout<<"*";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
