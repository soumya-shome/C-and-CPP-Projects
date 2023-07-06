#include<iostream>
using namespace std;
main()
{
		cout<<"6\t1\t2\n\n";
		for(int i=1;i<=6;i++)
		{
			cout<<"    ";
			for(int j=1;j<=6;j++)
			{
				if((i==j) || (i==1&&(j==2||j==3||j==4))||((i==2||i==3||i==4)&&j==1))
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
