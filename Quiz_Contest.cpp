#include<iostream>
using namespace std;
 main()
{
cout<<"************************quiz contest*************************"<<endl;
cout<<"*************************************************************"<<endl;
cout<<"########################rules#################################"<<endl;
cout<<"															"<<endl;
cout<<"1.the quiz contains 3 rounds ."<<endl;
cout<<"2.the round 1 & 2 contains 6 questions,while final round(round 3) contains 4 questions."<<endl;
cout<<"3.for each correct answer 5 marks are awarded and for each wrong answer 2 marks is deducted as negative marking."<<endl;
cout<<"4.in order to qualify for the round 2 the player has to score 15 points in round 1.in order to qualify for the round 3 one has to score above 25 points .in order to win the contest one has to score full marks in the last round ."<<endl;
cout<<"5.there is one bonus question after round 2 if score is above 45.if one is able to ans that question the player will be declared as the winner."<<endl;
cout<<"#######################best of luck#################################"<<endl;
cout<<"														"<<endl;
cout<<"************************round1************************************"<<endl;
cout<<"														"<<endl;
int a,b,c,score=0;
char ans=' ';
	cout<<"q1.what is the chemical name of tear gas?"<<endl<<"a.phenol"<<endl<<"b.chloroacetophenone"<<endl<<"c.acetophenone"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==b)
	{
		cout<<"correct answer\n";
		score=score +5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}
	
	cout<<"q2. which is the national flower of pakistan?"<<endl<<"a.rose"<<endl<<"b.sunflower"<<endl<<"c.jasmine"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==c)
	{
		cout<<"correct answer\n";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}

	cout<<"q3.which country is known as the 'land of cakes'?"<<endl<<"a.scotland"<<endl<<"b.thailand"<<endl<<"c.canada"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==a)
	{
		cout<<"correct answer\n";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}
	
	cout<<"q4.who was the first indian women olympic medal winner?"<<endl<<"a.saina nehwal"<<endl<<"b.sakshi malik"<<endl<<"karnam malleshwari"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==c)
	{
		cout<<"correct answer\n";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}
	
	cout<<"q5.murugappa gold cup is associated with which ports?"<<endl<<"a.cricket" <<endl<<"b.golf"<<endl<<"c.hockey"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==c)
	{
		cout<<"correct answer\n";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}
	
	cout<<"q6.in which year was the indian  national congress formed?"<<endl<<"a.1885"<<endl<<"b.1889"<<endl<<"c.1886"<<endl;
	cout <<"enter ans:";
	cin>>ans;
	if (ans==c)
	{
		cout<<"correct answer\n";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer\n";
		score=score-2;
	}
	
	cout<<"the total score in round1:"<<score;
	cout<<"…………………….round 1 ends…………………………………………"<<endl;
	cout<<"##############################################"<<endl;
	cout<<"##############################################";
	if(score >=15)
	{
			cout<<"@@@@@@@@@@@qualified@@@@@@@@@@"<<endl;
			cout<<"########################to######################"<<endl;
			cout<<"@@@@@@@@@@@round2@@@@@@@@@@@@@"<<endl;
			cout<<"………………………………………………………………………………………………………………………………"<<endl;
			cout<<"*************************round2**************************"<<endl;
			cout<<"…………………………………………………………………………………………………………………………………"<<endl;
			cout<<"q1.tropical storm in chinese sea is known as?"<<endl<<"a.typhoon"<<endl<<"b.tornado"<<endl<<"c.cyclone"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==a)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
			cout<<"q2.which is the oldest sports in the world?"<<endl<<"a.cricket"<<endl<<"b.archery"<<endl<<"c.hockey"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==b)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
			cout<<"q3.madhya pradesh shares border with how many states?"<<endl<<"a.3"<<endl<<"b.5"<<endl<<"c.6"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==b)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
			cout<<"q4.which is not an important plantation crop in india?"<<"a.grapes"<<endl<<"b.barley"<<endl<<"c.corn"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==a)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
			cout<<"q5.what is the nomal duration for a hockey game?"<<endl<<"a.80mins"<<endl<<"b.90mins"<<
			endl<<"c.70mins"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==c)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
			cout<<"q6.in which island of india is an active volcano found?"<<"a.havelock island"<<endl<<"b.barren island"<<endl<<"c.lakshadweep islands"<<endl;
			cout <<"enter ans:";
			cin>>ans;
			if (ans==b)
			{
				cout<<"correct answer";
				score=score+5;
			}
			else 
			{
				cout<<"wrong answer";
				score=score-2;
			}
		}
	else
	{
		cout<<">>>>>>>>>>>not qualified<<<<<<<<<<<<<<<<";
	}
	cout<<"the total score="<<score;
	if (score>=25)
	{
		cout<<"*****************qualified for the final round*************************"<<endl;
		cout<<"………………………………………………………………………………………………………………………………………"<<endl;
		cout<<"q1.who holds the record for most consecutive wins in best male playback singerflimfare  award?"<<endl<<"a.kishore kumar"<<endl<<"b.kumar sanu"<<endl<<"c.mohammed rafi"<<endl;
		cin>>ans;
	if (ans==b)
	{
		cout<<"correct answer";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer";
		score=score-2;
	}
		cout<<"q2.from which country does the airline viasia come     from?"<<endl<<"a.canada"<<endl<<"b.venezuela"<<endl<<"c.scotland"<<endl;
		cin>>ans;
	if (ans==b)
	{
		cout<<"correct answer";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer";
		score=score-2;
	}
	cout<<"q3.name the worlds biggest island."<<endl<<"a.greenland"<<"b.iceland"<<endl<<"c.andaman and nicobar"<<endl;
	cin>>ans;
	if (ans==a)
	{
		cout<<"correct answer";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer";
		score=score-2;
	}
	cout<<"q4.when did the cold war end?"<<endl<<"a.1987"<<endl<<"b.1989"<<endl<<"c.1985"<<endl;
	cin>>ans;
	if (ans==b)
	{
		cout<<"correct answer";
		score=score+5;
	}
	else 
	{
		cout<<"wrong answer";
		score=score-2;
	}
	}
		else
		{ cout<<"******************not qualified for final round*********************"<<endl;
		
		if (score>=45)
		{
		cout<<"##############you get a bonus question###############"<<endl;
		cout<<"q4.What is the full form of virus?"<<endl<<"a.very important resources under storage"<<endl<<"b.vital important Resources under storage"<<endl<<"c.very important resource under storage"<<endl;
		
		
		
		if (ans==b)
		{cout<<"correct answer";
		cout<<"######################congratulations###############################"<<endl;
		cout<<">>>>>>>>>>>>>>>>>>>>winner<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		}
		}
		system("pause");
		}
	}

		
		
		

