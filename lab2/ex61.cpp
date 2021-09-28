/*----------------------------------------
|Luisel A. Muller Rodriguez
|#S01394043
|This program lets an user enter info for
|two different loans and in the end get
|the monthly payment for both of them.
----------------------------------------*/
#include<iostream>
#include<cmath>
using namespace std;

struct Loan  // Loan is called structure tag
{
    int ID;         // assume an unique integer between 1111-9999
    float amount;   // $ amount of the loan
    float rate;     // annual interest rate
    int term;       // number of months, length of the loan
    float monthly_payment;  //moved this var here since it makes more since instead 
                            //of having to duplicate it each time you make a loan
};

float payment(Loan &l);
void initialize_loan(Loan &loan);

int main( )
{
    Loan loan1, loan2;
    initialize_loan(loan1);
    initialize_loan(loan2);
    
    //calculate the monthly payment
    loan1.monthly_payment = payment(loan1);
    loan2.monthly_payment = payment(loan2);

    //display the monthly payment for the loans
    cout << "The monthly payment for loan ID[" << loan1.ID << "] is: " << loan1.monthly_payment << endl;
    cout << "The monthly payment for loan ID[" << loan2.ID << "] is: " << loan2.monthly_payment << endl;

    //so the program doesn't end and close after displaying
    system("pause");
    return 0;
}

void initialize_loan(Loan &loan)
{
    for(int i = 1; i < 2; i++)
    {
    // Initialize the loan1 structure
    cout << "Enter the ID of the loan: ";
    cin >> loan.ID;
    cout  << "\n"; 

    cout << "Enter the amount of the loan: ";
    cin >> loan.amount;
    cout  << "\n";

    cout << "Enter the annual interest rate of the loan (in %): ";
    cin >> loan.rate;
    cout  << "\n";

    cout << "Enter the term (number of months, length of loan): ";
    cin >> loan.term;
    cout  << "\n";
    }

}
float payment(Loan &l)
{
    l.rate = l.rate/1200;  // To convert % yearly rate to monthly fraction
    return l.amount * l.rate * (pow((l.rate+1), l.term) / (pow((l.rate+1), l.term) -1));
}