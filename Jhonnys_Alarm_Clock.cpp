#include <iostream>
#include <fstream> //Might use a load previous time feature.. not sure yet
#include <string>
    

int main() {
using namespace std;
    
    //Variables
    
    int choice = 0;
    string current;
    string wake;

//I like my name.. lol.. so I put it in


    cout << "*************Johnny's Alarm Clock**********" << endl;
    cout << "Version 1.0" << endl;
    
    //MENU
    
 while (choice < 1 || choice > 3)
 {   
    cout << "1) Set a time to wake up to" << endl;
    cout << "2) Retrieve last used time to wake up to" << endl;
    cout << "3) Exit" << endl;
    cout << "What option would you like: ";
    cin >> choice;    

    switch (choice)
    {
    
    /*Here lies the problem.. I have no errors and its not complete yet
    but I can't get it to get the system time... and i've tried checking to
    see if it has it and it doens't.. what I need is the system time in
    a type of variable I thought i would need a string to avoid am/pm issues
    but this isn't working out..
    */
    case 1:
         system("cls");
          cout << "Be sure to set your windows time before doing this" << endl;
          system("pause");
          system("cls");
          cout << "The format is HH:MM am/pm for example 07:00 am" << endl;
          cout << "What time would you like to wake up? ";
          getline(cin, wake); // <-- UPDATED with "firedraco's" advice
          system("pause");
          system("time /t");
          getline (cin, current);
          system("cls");
          cout << "Current time is " << current;
          cout << "Wake up time is " << wake;
          system("pause");
          break;
          
          // DONT WORRY BOUT THIS PART YET
    case 2:
         system("cls");
          cout << "dont worry";
          break;
          //DONT WORRY ABOUT THE ABOVE YET
          
    case 3:
          cout << "Ok, Thank you!!!"; //Exit
          system("pause");
          return 0;
          break;
    default:
            cout << "That is not a number between one and 3" << endl;
            system("pause"); //In case number is outta range
            system("cls");
            break;
}
}
system("pause"); //End of program
return 0;
}
