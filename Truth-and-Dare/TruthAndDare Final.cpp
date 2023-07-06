#include<cstdlib>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include <cstdio>

using namespace std;

void input();

class data_control
{
	private:
		string name;
		int age;
		int p[6];
		
	public:
		void ini()
		{
			for(int i=0;i<6;i++)
			{
				p[i]=0;
			}
		}
		void input(long int number)
		{
			ini();
 			ofstream truth("truthanddare.txt", ios::app);
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
     		ifstream truth("truthanddare.txt");
     		system ("CLS");
    		cout << "POINTS TABLE"<< endl;
    		cout << "Number" << '\t' << "Name" <<'\t'<< "Age"<<"Points"<<endl;
     		cout << "---------------" << endl;
     		while (truth>>number >> name>> age)
			{
     			cout << number << '\t' << name <<'\t'<<age<<'\t'<<p[(number-1)] <<endl ;
    		}
     		cin.get();    
     	}
     	void deleteFile()
		{
    		ofstream truth("truthanddare.txt");
     	}
     	int points(int a)
     	{
     		p[--a]++;
			for(int j=0;j<6;j++)
			{
				if(p[j]!=15)
				{
					return -1;
				}
				else if(p[j]==10)
				{
					return (++j);
					exit;
				}	
			}	
		} 	
		 string searchname(int a)
 		{
 			long int number;
     		ifstream truth("truthanddare.txt");
     		while (truth >> number >> name >> age)
			{
           		if (number==a)
				{
                   	return name;
                }
            }
           	cin.get();
        }
        int searchage(int a)
 		{
 			long int number;
     		ifstream truth("truthanddare.txt");
     		while (truth >> number >> name >> age)
			{
           		if (number==a)
				{
                   	return age;
                }
            }
           	cin.get();
        }
};

class td
{
	public:
		int bottle()
		{
			srand(time(0));
			int n=rand()%6+1;
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=6;i++)
			{
				cout<<"  ";
				if(n==1)
				{				
					
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
				}
				else if(n==2)
				{
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
				}
				else if(n==3)
				{
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
				}
				else if(n==4)
				{
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
				}	
				else if(n==5)
				{
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
				}
				else if(n==6)
				{
					
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
				}	
				cout<<endl;
			}
			cout<<"6\t5\t4\n";
			if(n==1)
			{
				return 25;
				}
			else if(n==2)
			{
				return 52;
			}
			else if(n==3)
			{
				return 14;
			}
			else if(n==4)
			{
				return 36;
			}
			else if(n==5)
			{
				return 41;
			}
			else if(n==6)
			{
				return 63;
			}	
		}

		void T_K()
		{
			srand(time(0));
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
		}

		void D_K()
		{
			srand(time(0));
			int y=rand()%8+1;
			switch(y)
			{
				case 1:
					cout<<"\n Spin around 10 times and then try to walk in a straight line";
				break;

				case 2:	
					cout<<"\n Dance with no music for 30 seconds";
				break;

				case 3:
					cout<<"\n Arm wrestle the player opposite to you";
				break;

				case 4:
					cout<<"\n Eat a tablespoon of butter";
				break;

				case 5:
					cout<<"\n Do the chicken dance";
				break;

				case 6:
					cout<<"\n Descibe everyone in 3 words";
				break;

				case 7:
					cout<<"\n Let the group give you a new hairstyle";
				break;

				case 8:
					cout<<"\n Moonwalk across the room";
				break;
			}		
		}

		void T_T()
		{
			srand(time(0));
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
		}

		void D_T()
		{
			srand(time(0));
			int y=(rand()%8)+1;
			switch(y)
			{
				case 1:
					cout<<"\n Stay without your cellphone till your next turn";
				break;

				case 2:
					cout<<"\n Let the group give you a new hairstyle";
				break;

				case 3:
					cout<<"\n Let the group look through your phone for 2 mins";
				break;
				case 4:
					cout<<"\n Allow another player draw anything on your face";
				break;
				case 5:
					cout<<"\n Spin around in circle for one minute without stopping";
				break;
				case 6:
					cout<<"\n Do 20 situps";
				break;
				case 7:
					cout<<"\n Give a foot massage to another player";
				break;
	
				case 8:
					cout<<"\n Get slapped by everyone in the room";
				break;
			}	
		}

};


main()
{
	data_control obj;
	td ob;
	obj.ini();
	for(int i=1;i<=6;i++)
	{
		obj.input(i);
	}

		
		char w;
		int d,s,a,p;
		q:
			system("cls");
			obj.displayall();
			system("pause");
			system("cls");
			cout<<"Enter (P/Q)\n P to play \nQ to Quit\n";
			cin>>w;
			if(w=='P'||w=='p')
			{
				d=ob.bottle();
				s=d%10;
				a=d/10;
				string asker=obj.searchname(s);
				string answer=obj.searchname(a);
				cout<<asker<<" will ask to "<<answer<<endl;
							z:
				       			cout<<"Enter (T/D)\nT for Truth\nD for Dare\n";
				       			cin>>w;
				       			int y=obj.searchage(a);
				       			if(w=='T'||w=='t')
				       			{
				       				if(w<13)
				       				{	
										ob.T_K();
									}
									else
									{
										ob.T_T();
				       				}
				       			}
				       			else if(w=='D'||w=='d')
				       			{
									if(w<13)
				       				{	
										ob.D_K();
									}
									else
									{
										ob.D_T();
				       				}
				     			}
				       			else
				       			{
									goto z;
				       			}
							x:
				       			cout<<"Enter (C/F) \n C for Task Completed \n F for Task forfeited\n";
				       			cin>>w;
				       			if(w=='C'||w=='c')
				       			{
					      			p=obj.points(a);
					      			if(p>-1)
					      			{
					      				cout<<answer<<" is the winner \n";
					      				cout<<"\t\t\tCONGRATULATIONS !!\n";
					      				exit;
									}
									else if(p==-1)
									{
										goto q;
									}
				       			}
				       			else if(w=='F'||w=='f')
				       			{
					    			p=obj.points(a);
					      			if(p>-1)
					      			{
					      				cout<<answer<<" is the winner \n";
					      				cout<<"\t\t\tCONGRATULATIONS !!\n";
					      				exit;
									}
									else if(p==-1)
									{
										goto q;
									}
				       			}
				       			else
				       			{
									goto x;
				       			}
					}
					else if(w=='Q'||w=='q')
					{	
						exit;
					}
					else
					{
						goto q;
					}
				
}
