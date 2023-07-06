#include<iostream>
using namespace std;
main()
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
