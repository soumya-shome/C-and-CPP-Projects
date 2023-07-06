#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>


using namespace std;

void setup(char);
int travel_dist=1;
int native_dist=0;
int stop=0,drink=0;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 
	
	cout<<"                        !!! Welcome to Camel Chase !!!"<<endl;
    
	cout<<"      You have stolen a camel to make your way across the great Mobi desert."<<endl;
    cout<<"      The natives want their camel back and are chasing you down! Survive your"<<endl;
    cout<<"                desert trek and outrun the natives."<<endl;
    char choice;
    
	while(travel_dist <= 60)
    {
    	if(travel_dist > native_dist)
		{
		cout<<"            A. Drink from your canteen."<<endl;
		cout<<"            B. Ahead moderate speed."<<endl;
        cout<<"            C. Ahead full speed."<<endl;
        cout<<"            D. Stop and rest."<<endl;
        cout<<"            E. Status check."<<endl;
        cout<<"            Q. Quit."<<endl;
        cout<<"Your choice? "<<endl;
        cin>> choice;
        if(choice=='Q'|| choice=='q')
        {
		cout<<"             You Quit"<<endl;
			break;
			
        }
		else
		{
		setup(choice);
		}
     	}
     	else
     	{
     		cout<<"             You Lost"<<endl;
     		cout<<"        The Natives Caught You"<<endl;
     		break;
		 }
		
        

	}

if(travel_dist>=58)
{
cout<<endl;
cout<<"                   !! Congratulations !!"<<endl;
cout<<"                    You Won The Game !!"<<endl;
cout<<"               You Survived The Harsh Mobi Desert"<<endl;
cout<<"               You Covered a distance of "<< travel_dist<<" miles"<<endl;
cout<<"               The Natives are at a distance of "<<travel_dist - native_dist<<" miles behind you"<<endl;
}
	
	return(0);
	system("pause");
}


void setup(char x)
{ int n,m;
    switch(x)
    {
    	case 'A':      //canteen
    	    cout<<"Stopped for a drink"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<"The Natives Can Be Seen Now.. Hurry !!"<<endl;
			drink=drink+1;
            srand(time(0));
            native_dist=native_dist+(rand()%5)+2;
            
			break;
        case 'B':     //morderate
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			srand(time(0));
            n = (rand()%9)+5;
            cout<<"You travelled "<<n<<" miles"<<endl;
            travel_dist=travel_dist+n;
            srand(time(0));
			native_dist= native_dist+(rand()%5)+2;
            break;
        case 'C':     //fast
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			srand(time(0));
            m = (rand()%17)+10;
            cout<<"You travelled "<<m<<" miles"<<endl;
            travel_dist= travel_dist+m;
            srand(time(0));
            native_dist=native_dist+(rand()%10)+7;
            break;
        case 'D':      //rest
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"The natives are getting closer.."<<endl;
        	native_dist=native_dist+(rand()%5)+1;
        	stop=stop+1;
        	break;
        case 'E':      //status
        	cout<<" Distance Covered "<<travel_dist<<" miles"<<endl;
        	cout<<"Natives Covered "<<native_dist<<" miles"<<endl;
        	cout<<"You stopped "<<stop<<" times"<<endl;
        	cout<<"You Drank "<< drink <<" times from the canteen"<<endl;
        	break;
        default:
        	cout<<"Wrong Choice"<<endl;
        	
    }
	
	
	}
