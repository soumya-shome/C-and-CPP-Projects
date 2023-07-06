#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

class data_control
{
	private:
		string name;
		int age;
		int q[6];
		void ini()
		{
			for(int i=0;i<6;i++)
			{
				q[i]=0;
			}
		}
	public:
		void input(long int number)
		{
			ini();
 			ofstream truth("test.txt", ios::app);
 			system("cls");
 			cout<<"Player number:-"<<number<<endl;
 			cout << "Enter the name" << endl;
 			cin >> name;
 			cout << "Enter the age" << endl;
 			cin >> age;
 			cin.sync();
 			truth << number << ' ' << name <<' '<< age<<endl;     
 			truth.close();
			system("cls"); 
     	}
     	
     	void displayall()
		{
			long int number;
     		ifstream truth("test.txt");
    		cout << "POINTS TABLE"<< endl;
    		cout << "Number" << '\t' << "Name" <<'\t'<< "Age"<<"Points"<<endl;
     		cout << "---------------" << endl;
     		while (truth>>number >> name>> age)
			{
     			cout << number << '\t' << name <<'\t'<<age<<'\t'<<q[--number]<< endl ;
     		}
     		cin.get();    
     	}
     	
     	void deleteFile()
		{
     		ofstream truth("test.txt");
     	}
     	
     	
     	
     	
     	void points(int a)
     	{
     		q[a]++;	
		}
		
		
		
     	string searchname(int a)
 		{
 			long int number;
     		ifstream truth("test.txt");
     		while (truth >> number >> name >> age)
			{
           		if (number==a)
				{
                   	return name;
                }
            }
           	cin.get();
        }
};
main()
{
	int q;
	data_control ob;
	ob.deleteFile();
	for(int i=1;i<=6;i++)
	{
		ob.input(i);
	}
	ob.displayall();
	cout<<"Enter a number ";
	cin>>q;
	ob.points(--q);
	
	ob.displayall();
}
