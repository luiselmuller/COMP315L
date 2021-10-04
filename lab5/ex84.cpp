// P84.cpp - This program is a driver written to demonstrate how we can use a
// class inside another one.
#include<iostream>
using namespace std;

class ID
{
   public:
      ID();
      ID(int, int, int);
      void display();
   private:
      int left;
      int middle;
      int right;
};

class Loan  // Loan is called structure tag
{
   public:
      Loan();
      Loan(ID id, float amount, float rate, int term);
      void set();
      float payment();
      void display();
      friend bool operator == (Loan ma, Loan mb);
   private:
      ID id;  // assume an unique integer between 1111-9999
      float amount; // $ amount of the loan
      float rate; // annual interest rate
      int term;  // number of months, length of the loan
};

int main()
{
   Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given
   Loan loan2;

   cout << "Display loan1 \n";
   loan1.display();

   loan2.set(); // set the values
   cout << "Display loan2 \n";
   loan2.display();

   if(loan1 == loan2)
    cout<<"The loans are equal";
   else
    cout<<"The loans are not equal";

   return 0;
}

ID::ID()
{
   // use default values
}

ID::ID(int l, int m, int r)
{
   left = l;
   middle = m;
   right = r;
}

void ID::display()
{
   cout << left << "-" << middle << "-" << right << endl;
}

Loan::Loan()
{
}

Loan::Loan(ID I, float am, float rt, int trm)
{
   id = I;
   amount = am;
   rate = rt;
   term = trm;
}

void Loan::set()
{
   int l, m, r;
   ID temp_id;
   // Initialize the loan1 object
   cout << "Enter the left part of the loan ID \n";
   cin >> l;
   cout << "Enter the middle part of the loan ID \n";
   cin >> m;
   cout << "Enter the right part of the loan ID \n";
   cin >> r;

   id = ID(l, m, r);

   cout << "Enter the amount of this loan \n";
   cin >> amount;

   cout << "Enter the annual interest rate of this loan (in %) \n";
   cin >> rate;

   cout << "Enter the term (number of months, length of the loan) \n";
   cin >> term;
   
}

void Loan::display()
{
   id.display();
   cout << amount << endl;
   cout << rate << endl;
   cout << term << endl;
}

bool operator == (Loan ma, Loan mb)
{
    return /*TODO:comparar los id*/ma.amount == mb.amount && ma.rate == mb.rate && ma.term == mb.term ? true : false;
}