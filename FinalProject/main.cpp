/*---------------------------------------------------
  Luisel A. Muller Rodriguez
  #S01394043
  11/28/2021

  This program is an Emergency Room Patients
  Healthcare System that keeps the patients records,
  visits, turns, diagnostics, treatments, etc.
---------------------------------------------------*/

#include <iostream>
#include <string>
#include "System.h"

using namespace std;

int main()
{
    /*
    *  Variables:
    *
    */
    int choice = -1, pschoice = -1;
    char ec;
    

    System system;

    do
    {
            //Menu to allow the user to make a choice.
            cout << "\n========================================================\n"
                    "  Emergency Room Patients Healthcare Management System  \n"
                    "--------------------------------------------------------\n"
                    "  Are you a Doctor or a Patient?:                       \n"
                    "  1. Doctor                                             \n"
                    "  2. Patient                                          \n\n"
                    "  0. Exit                                               \n"
                    "========================================================\n"
                    "  >";
            cin >> choice; //Reading the users input for the choice.

            //If the choice is not one that is on the menu the user is asked to enter it again
            if (choice < 0 || choice > 2)
            {
                cout << "Enter a valid option.\n>";
                cin >> choice;
            }

            switch(choice)
            {
                //OPTION : MAKE A SYSTEM CLASS THAT HAS FUNCTIONS TO MANAGE PATIENTS AND HAVE DOCTOR CLASS INHERIT IT
                /*********************************************************************************************
                *  
                *********************************************************************************************/
                case 1:
                    //if user is a doctor then ask for their name to register them in the system
                    //this name will be used in the patients records if the doctor is the one to make them
                    //once the doctor adds their name they can choose to add a patients record, add new physicians
                    //record, find a patient or physician, find the patients visit history, display the patients 
                    //registered in the system or print an invoice that includes the details of the visit and service
                    //done. the doctor can also change the patients turn

                    //NEEDS TO BE ABLE TO TAKE PATIENTS OUT OF QUEUE WHEN DOCTOR IS DONE ATTENDING THEM
                    {
                        string dans;
                        int didLogin = -1; 

                        cout << "Have you been registered in the system before? (yes/no)\n>";
                        cin.ignore();
                        getline(cin, dans);

                        if (dans == "no" || dans == "n" || dans == "NO")
                        {
                            system.addDoctor();
                        }
                        else
                        {
                            cout << "\nEnter your ID: ";
                            cin >> didLogin;
                            system.doctorLogin(didLogin, system.findDoctor(didLogin));
                        }
                    }
                break;

                /**********************************************************************************************
                *  
                **********************************************************************************************/
                case 2:

                    //NEED TO ADD DASHBOARD OPTIONS TO CHANGE INFO AND MAKE IT LOOK BETTER
                    //ALSO NEEDS TO BE ABLE TO FIND PHYSICIANS AND SEE THEIR INVOICES
                    
                {
                    string ans;
                    int pidLogin = -1;

                    cout << "Have you been registered in the system before? (yes/no)\n>";
                    cin.ignore();
                    getline(cin, ans);
                    if (ans == "no" || ans == "n" || ans == "NO")
                    {
                        system.addPatient();
                    }
                    else
                    {
                        cout << "\nEnter your ID: ";
                        cin >> pidLogin;
                        system.patientLogin(pidLogin, system.findPatient(pidLogin));
                    }
                }
                    
                    

                break;

            }
    //If the choice is 0 the program exits the loop and then the user is given the choice to restart or exit.
    }while(choice != 0);

    //Lets the user restart or exit the program.
    cout << "Are you sure you want to exit the program? (y/n): ";
    cin >> ec;   
    return ec == 'n' ? main() : 0;
}