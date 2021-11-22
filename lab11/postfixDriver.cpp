/*********************************************************************
* Luisel A. Muller Rodriguez
* #S01394043
* 11/17/2021
* -------------------------------------------------------------------
* Description: This program lets the user choose to convert
* infix to postfix, infix to prefix or evaluate a postfix expression.
*********************************************************************/
#include <iostream>
#include <string>
#include "PrePostDefs.h"

using namespace std;

int main()
{
    /***********************************************************************************
    * Variables:
    *   Integers:
    *       choice -> Stores the users choice when picking from the menu.
    *   Strings:
    *       infix -> Stores the infix expression that the user enters.
    *       post  -> Stores the postfix expression after converting it with infpos().
    *                It also stores the postfix expression entered by the user when
    *                the user chooses to evaluate a postfix expression.
    *       pre   -> Stores the prefix expression after converting it infpre().
    *   Characters:
    *       ec  -> Stores the users choice after trying to exit the program. The
    *              user can choose to exit the program or not.
    ***********************************************************************************/
    int choice;
    string infix, post, pre;
    char ec;
 
    do
    {
        //Menu to allow the user to pick a choice.
        cout<<"\n========================================================\n"
                "                   Postfix Evaluator\n"
                "           Enter a number to make a choice.\n"
                "--------------------------------------------------------\n"
                "(characters like '[' or '{' will not work but doubles   \n"
                " will work as well as operands with more than one digit)\n"
                "========================================================\n\n"
                "1. Convert Infix to Postfix\n"
                "2. Convert Infix to Prefix\n"
                "3. Evaluate a Postfix expression\n>";
        cin>>choice; //Reading the users input for the choice.

        //If the choice is not one that is on the menu the user is asked to enter it again
        if (choice < 0 || choice > 3)
        {
            cout << "Enter a valid option.\n>";
            cin >> choice;
        }
            switch(choice)
            {
                /*********************************************************************************************
                *  If the users choice is 1, then the user is asked to enter the infix expression, when it's
                *  entered it gets converted to postfix using the infpos() function. After converting it 
                *  it gets stored in the post variable and printed with the eprint() function.
                *********************************************************************************************/
                case 1:
                    cout << "Enter the infix expression: ";
                    //Getting rid of the extra characters left from cin.
                    cin.ignore();           
                    getline(cin, infix);
                    cout << "\n";

                    cout << "Postfix: ";
                    post = infpos(infix);
                    cout << eprint(post, 0) << " ";
                    //Adding 2 extra lines under the output.
                    cout << "\n\n";     

                    //Pausing the console so that the user can view the results and decide when to continue.
                    system("pause");       
                break;

                /**********************************************************************************************
                *  If the users choice is 2, then the user is asked to enter the infix expression, when it's
                *  entered it gets converted to prefix using the infpre() function. After converting it
                *  it gets stored in the pre variable and printed with the eprint() function.
                **********************************************************************************************/
                case 2:
                    cout << "Enter the infix expression: ";
                    cin.ignore();        
                    //Getting rid of the extra characters left from cin.
                    getline(cin, infix);
                    cout << "\n";

                    cout << "Prefix: ";
                    pre = infpre(infix);
                    cout << eprint(pre, 0) << " ";
                    //Adding 2 extra lines under the output.
                    cout << "\n\n";      

                    //Pausing the console so that the user can view the results and decide when to continue.
                    system("pause");        
                break;

                /**********************************************************************************************
                *  If the users choice is 3, then the user is asked to enter a postfix expression, when it's
                *  entered it gets evaluated and then printed out to the console.
                **********************************************************************************************/
                case 3:
                    cout << "Enter the postfix expression (use spaces to separate operands): ";
                    cin.ignore();
                    //Getting rid of the extra characters left from cin.
                    getline(cin, post);
                    cout << "\n";

                    cout << "The result is: ";
                    cout << evalpos(post);
                    //Adding 2 extra lines under the output.
                    cout << "\n\n";

                    //Pausing the console so that the user can view the results and decide when to continue.
                    system("pause");
                break;

            }
    //If the choice is 0 the program exits the loop and then the user is given the choice to restart or exit.
    }while(choice != 0);

    /*******************************************************************************
    *  Allows the user to either exit the program or restart it after they enter 0
    *  as a choice.
    *******************************************************************************/
    cout << "Are you sure you want to exit the program? (y/n): ";
    cin >> ec;   
    return ec == 'n' ? main() : 0;
}