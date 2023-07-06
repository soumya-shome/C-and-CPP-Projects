#include<iostream>
using namespace std;

main()
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
