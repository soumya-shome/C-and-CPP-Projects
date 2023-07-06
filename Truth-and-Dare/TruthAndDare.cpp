#include<cstdlib>
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include <cstdio>

using namespace std;

void rule();

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
 			ofstream truth("truthanddare.txt", ios::app);
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
    		cout << "POINTS TABLE"<< endl;
    		cout << "Number" << '\t' << "Name" <<"\t\t"<< "Age"<<'\t'<<"Points"<<endl;
     		cout << "----------------------------------------" << endl;
     		while (truth>>number >> name>> age)
			{
     			cout << number << '\t' << name <<"\t\t"<<age<<'\t'<<p[(number-1)] <<endl ;
    		}
     		cin.get();    
     	}
     	
     	void deleteFile()
		{
    		ofstream truth("truthanddare.txt");
     	}
     	
     	int chechscore(int a)
     	{
     		int q;
     		if(a==0)
			{
			 	for(int j=0;j<6;j++)
				{
					if(p[j]<10)
					{
						q=-1;
					}
					else if(p[j]>=10)
					{
						j++;
						q=j;
						break;
					}	
				}
				return q;
			}
			else if(a==7)
			{
     			int max=-1;
     			int st=0;
     			for(int a=0;a<6;a++)
     			{
     				if(p[a]>=max)
     				{
     					max=p[a];
     					st=a;
					 }
				}
			return st;
			}
		}
		 
		void points(int b)
     	{
     		--b;
     		p[b]++;
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
			int n=rand()%60+1;
			cout<<"1\t2\t3\n\n";
			for(int i=1;i<=7;i++)
			{
				cout<<"  ";
				if((n<10)&&(n>=1))
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
				else if((n<20)&&(n>=10))
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
				else if((n<30)&&(n>=20))
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
				else if((n<40)&&(n>=30))
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
				else if((n<50)&&(n>=40))
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
				else if((n<=60)&&(n>=50))
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
			if((n<10)&&(n>=1))
			{
				return 25;
			}
			else if((n<20)&&(n>=10))
			{
				return 52;
			}
			else if((n<30)&&(n>=20))
			{
				return 14;
			}
			else if((n<40)&&(n>=30))
			{
				return 36;
			}
			else if((n<50)&&(n>=40))
			{
				return 41;
			}
			else if((n<=60)&&(n>=50))
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
					cout<<"\n Tell about your stangest dream\n ";
				break;
	
				case 2:
					cout<<"\n Have you ever wet your bed? \n";
				break;

				case 3:
					cout<<"\n Have you ever cheated in a exam? \n";
				break;

				case 4:
					cout<<"\n Tell You worst grades \n";
				break;

				case 5:
					cout<<"\n Name The Person you fear the most \n";
				break;

				case 6:
					cout<<"\n Tell about the craziest thing you have ever done \n";
				break;

				case 7:
					cout<<"\n What question would you like to ask to the person opposite to you? \n";
				break;

				case 8:
					cout<<"\n What animal are you afraid of the most? \n";
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
					cout<<"\n Spin around 10 times and then try to walk in a straight line\n";
				break;

				case 2:	
					cout<<"\n Dance with no music for 30 seconds\n";
				break;

				case 3:
					cout<<"\n Arm wrestle the player opposite to you\n";
				break;

				case 4:
					cout<<"\n Eat a tablespoon of butter\n";
				break;

				case 5:
					cout<<"\n Do the chicken dance\n";
				break;

				case 6:
					cout<<"\n Descibe everyone in 3 words\n";
				break;

				case 7:
					cout<<"\n Let the group give you a new hairstyle\n";
				break;

				case 8:
					cout<<"\n Moonwalk across the room\n";
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
					cout<<"\n What is you least favorite thing about the person on your left?\n";
				break;

				case 2:
					cout<<"\n Do you Google new people you meet? \n";
				break;

				case 3:
					cout<<"\n If you could Invent anything, What would it be? \n";
				break;	

				case 4:
					cout<<"\n Your biggestr fear?\n ";
				break;
	
				case 5:
					cout<<"\n Where is the strangest place you have peed? \n";
				break;

				case 6:
					cout<<"\n Describe yourself in 3 words\n ";
				break;

				case 7:
					cout<<"\n What's your most embarrassing nickname?\n ";
				break;

				case 8:
					cout<<"\n Have you ever worn the opposite sex's clothing?\n ";
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
					cout<<"\n Stay without your cellphone till your next turn\n";
				break;

				case 2:
					cout<<"\n Let the group give you a new hairstyle\n";
				break;

				case 3:
					cout<<"\n Let the group look through your phone for 2 mins\n";
				break;
				case 4:
					cout<<"\n Allow another player draw anything on your face\n";
				break;
				case 5:
					cout<<"\n Spin around in circle for one minute without stopping\n";
				break;
				case 6:
					cout<<"\n Do 20 situps\n";
				break;
				case 7:
					cout<<"\n Give a foot massage to another player\n";
				break;
	
				case 8:
					cout<<"\n Get slapped by everyone in the room\n";
				break;
			}	
		}

};

void rule()
{
	cout<<"\t\t\t   !!! WELCOME !!!\n";
	cout<<"\t\t\t\t  To\n";
	cout<<"\t\t\t Truth And Dare Game\n";
	cout<<"Rules:-\n";
	cout<<"\t1.The game is for 6 players\n";
	cout<<"\t2.First player to reach point 10 will win\n";
	cout<<"\t3.The Bottle is represented in form of an arrow\n";
	cout<<"\nSteps\n";
	cout<<"\t1.Enter your names and age\n";
	cout<<"\t2.Enter p to play or q to quit\n";
	cout<<"\t3.You have to choose a task (Truth or Dare)\n";
	cout<<"\t4.The questions or task will be asked according to your age\n";
	cout<<"\t5.If the answerer complete the task he/she will get one point \n";
	cout<<"\t6.else the asker will get one point\n";
	cout<<"\t7.To continue the game enter P or p \n";
	cout<<"\t8.To quit the game midway enter Q or q \n";
	cout<<"\t9. The highest scorer will be declared the winner\n\n";
	system("pause");
}

main()
{
	system("color F0");
	data_control obj;
	td ob;
	int d,s,a,p;
	char w=' ';
	string winner;
	rule();
	obj.deleteFile();
	obj.ini();
	system("cls");
	cout<<"\nEnter The Names and Age of the Players\n\n"; 
	for(int i=1;i<=6;i++)
	{
		obj.input(i);
	}
	q:
		system("cls");
		obj.displayall();
		system("pause");
		system("cls");
		cout<<"Enter (P/Q)\n\t P to play \n\tQ to Quit\n";
		cin>>w;
		if(w=='P'||w=='p')
		{
			d=ob.bottle();
			s=d%10;
			a=d/10;
			string asker=obj.searchname(s);
			string answer=obj.searchname(a);
			cout<<'\t'<<asker<<" will ask to "<<answer<<endl;
						z:
			       			cout<<"Enter (T/D)\nT for Truth\nD for Dare\n\t";
			       			cin>>w;
			       			int y=obj.searchage(a);
			       			if(w=='T'||w=='t')
			       			{
			       				if(y<13)
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
								if(y<13)
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
			       			cout<<"Enter (C/F) \n C for Task Completed \n F for Task forfeited\n\t";
			       			cin>>w;
			       			if(w=='C'||w=='c')
			       			{
				      			obj.points(a);
				      			p=obj.chechscore(0);
								cout<<'\t'<<answer<<" get the points\n";
				      			if(p>-1)
				      			{
				      				winner=obj.searchname(p);
				      				obj.displayall();
				      				
				      				cout<<'\n'<<winner<<" is the winner \n\n";
				      				cout<<"\t\t\t!! CONGRATULATIONS !!\n";
				      				exit;
								}
								else if(p==-1)
								{
									
									system("pause");
									goto q;
								}
			       			}
			       			
			       			else if(w=='F'||w=='f')
			       			{
				    			obj.points(s);
				    			p=obj.chechscore(0);
								cout<<'\t'<<asker<<" get the points\n";	    			
				      			if(p>-1)
				      			{
				      				winner=obj.searchname(p);
				      				obj.displayall();
				      				cout<<'\n'<<winner<<" is the winner \n";
				      				cout<<"\t\t\t!! CONGRATULATIONS !!\n";
				      				exit;
								}
								else if(p==-1)
								{
									system("pause");
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
			p=obj.chechscore(7);
			if(p<6)
			{
				winner=obj.searchname((p+1));
			}
			else
			{
				winner=obj.searchname(p);
			}
			obj.displayall();
			cout<<'\t'<<winner<<" is the winner\n";
			cout<<"\t\t\t!! CONGRATULATIONS !!\n";
			exit;
		}
		else
		{
			goto q;
		}				
}
