/*----------------------------------------
|Luisel A. Muller Rodriguez
|#S01394043
|This program lets an user enter info for
|loans and in the end get the monthly
|payment plus they can view the info
|entered.
----------------------------------------*/
#include<iostream>
#include <cmath>
using namespace std;

class Loan  // Loan is called structure tag
{
    public:
        Loan();
        Loan(int ID, float amount, float rate, int term);
        //void set(); moved this function to the body of the empty constructor
        void payment();
        void display();
    private:
        int ID;         // assume an unique integer between 1111-9999
        float amount;   // $ amount of the loan
        float rate;     // annual interest rate
        int term;       // number of months, length of the loan
        float monthly_payment;
};

int main()
{
    //initializing the loans
    Loan loan1, loan2;

    //calculating monthly payment
    loan1.payment();
    loan2.payment();

    //displays the loan information
    cout<<"Loan 1 information";
    loan1.display();

    cout<<"Loan 2 information";
    loan2.display();
    
    //so the program doesn't end and close after displaying
    system("pause");
    return 0;
}



void Loan::display() 
{
    cout << "\nID: " << ID << "\nAmount: " << amount << "\nRate: " << rate << "\nTerm: " << term << endl;
    cout << "Monthly Payment: " << monthly_payment << endl;
}

void Loan::payment()
{
    rate = rate/1200;  // To convert % yearly rate to monthly fraction
    monthly_payment = amount * rate * (pow((rate+1), term) / (pow((rate+1), term) -1));
}

//empty constructor for the loan class which asks the user for the values
Loan::Loan()
{
    // Initialize the loan1 object
    cout << "Enter the ID of this loan: ";
    cin >> ID;

    cout << "Enter the amount of this loan: ";
    cin >> amount;

    cout << "Enter the annual interest rate of this loan (in %): ";
    cin >> rate;

    cout << "Enter the term (number of months, length of the loan): ";
    cin >> term;
}

//constructor used to initialize a loan object with values directly
Loan::Loan(int i, float a, float r, int t)
{
    ID = i;
    amount = a;
    rate = r;
    term = t;
}