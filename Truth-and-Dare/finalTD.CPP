
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
class td
{
	private:
		int q[6];
		void ini()
		{
			for(int i=0;i<6;i++)
			{
				q[i]=0;
			}
		}

		int bottle()
		{
			srand(time(0));
			int n=rand()%8+1;
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
				return 25;
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
				return 52;
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
				return 14;
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
				return 36;
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
				return 41;
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



		int points(int a)
		{
			q[a]++;
			for(int i=0;i<6;i++)
			{
				if(q[i]<15)
				{
					return 0;
				}
				else
				{
					return (i+1);
				}
			}
		}


		void pt()
		{
			cout<<"The scores are\n";
			for(int i=0;i<6;i++)
			{
				cout<<i<<" = "<<q[i];
				cout<<endl;
			}
		}


	public:
		void play()
		{
			char w;
			int d,s,a,p;
			ini();
			q:
				cout<<"Enter (P/Q)\n P to play \nQ to Quit\n";
				cin>>w;
				if(w=='P'||w=='p')
				{
			       d=bottle();
			       s=d%10;
			       a=d/10;
			       cout<<s<<" will ask to "<<a<<endl;
						z:
			       			cout<<"Enter (T/D)\nT for Truth\nD for Dare\n";
			       			cin>>w;
			       			if(w=='T'||w=='t')
			       			{
								T_K();
								T_T();
			       			}
			       			else if(w=='D'||w=='d')
			       			{
								D_K();
								D_T();
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
				      			p=points(a);
				      			if(p==0)
								{
									pt();
									goto q;
								}
								else
								{
									pt();
									cout<<(p-1)<<" is the winner";
									exit;
								}
			       			}
			       			else if(w=='F'||w=='f')
			       			{
				    			p=points(s);
				    			if(p==0)
								{
									pt();
									goto q;
								}
								else
								{
									pt();
									cout<<(p-1)<<" is the winner";
									exit;
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
};


main()
{
	
	td ob;
	ob.play();
}
