#include<iostream>
using namespace std;
main()
{
	int n;
	cout<<"Enter one number\n";
	cin>>n;
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
