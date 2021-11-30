/*---------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This program is an Emergency Room Patients
  Healthcare System that keeps the patients records,
  visits, turns, diagnostics, treatments, etc.
---------------------------------------------------*/

#include <iostream>

using namespace std;

int main()
{
    /*
    *  Variables:
    *
    */
    char ec;

    do
    {
        //Menu to allow the user to make a choice.
        cout<<"\n========================================================\n"
                
                "--------------------------------------------------------\n"
                
                "========================================================\n\n";
        cin>>choice; //Reading the users input for the choice.

        //If the choice is not one that is on the menu the user is asked to enter it again
        if (choice < 0 || choice > 0)
        {
            cout << "Enter a valid option.\n>";
            cin >> choice;
        }
            switch(choice)
            {
                /*********************************************************************************************
                *  
                *********************************************************************************************/
                case 1:
    
                break;

                /**********************************************************************************************
                *  
                **********************************************************************************************/
                case 2:
      
                break;

                /**********************************************************************************************
                *  
                **********************************************************************************************/
                case 3:

                break;

            }
    //If the choice is 0 the program exits the loop and then the user is given the choice to restart or exit.
    }while(choice != 0);

    //Lets the user restart or exit the program.
    cout << "Are you sure you want to exit the program? (y/n): ";
    cin >> ec;   
    return ec == 'n' ? main() : 0;
}