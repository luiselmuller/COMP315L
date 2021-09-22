#include<iostream>
#include<cstdlib>

using namespace std;

class AltMoney
{
    public:
        AltMoney();
        AltMoney(int d, int c);
        friend AltMoney add(AltMoney m1, AltMoney m2);
        friend AltMoney subtract(AltMoney m1, AltMoney m2);
        void display_money();
        void read_money();
    private:
        int dollars;
        int cents;
};
        
int main()
{
    int d, c;
    AltMoney m1, m2, dollarsAdded, dollarsSub;

    dollarsAdded = AltMoney(0,0);

    m1.read_money();
    cout << "The first money is:";
    m1.display_money();

    m2.read_money();
    cout << "The second money is:";
    m2.display_money();

    dollarsAdded = add(m1, m2);
    cout << "The sum is:";
    dollarsAdded.display_money();

    dollarsSub = subtract(m1, m2);
    cout<<"The subtraction is: ";
    dollarsSub.display_money();

    return 0;
}

AltMoney::AltMoney()
{
}

AltMoney::AltMoney(int d, int c)
{
    dollars = d;
    cents = c;
}

void AltMoney::display_money()
{
    cout << "$" << dollars << ".";
    if(cents <= 9)
        cout << "0";  //to display a 0 in the left for numbers less than 10
    cout << cents << endl;
}

AltMoney add(AltMoney m1, AltMoney m2)
{
    AltMoney sum;
    int extra = 0;
    sum.cents = m1.cents + m2.cents;
    if(sum.cents >= 100)
    {
        sum.cents = sum.cents - 100;
        extra = 1;
    }
    sum.dollars = m1.dollars + m2.dollars + extra;

    return sum;
}

AltMoney subtract(AltMoney m1, AltMoney m2)
{
    AltMoney sub;
    int greater = 0;
    int lesser = 0;
    int extra = 0;

    //needs fix
    if(m1.dollars > m2.dollars)
    {
        greater = m1.dollars;
        lesser = m2.dollars;
    }
    else
    {
        greater = m2.dollars;
        lesser = m1.dollars;
    }

    sub.dollars = greater - lesser;

    if(m1.cents > m2.cents)
    {
        greater = m1.cents;
        lesser = m2.cents;
    }
    else
    {
        greater = m2.cents;
        lesser = m1.cents;
    
    }

        sub.cents = greater - lesser;

    return sub;
}

void AltMoney::read_money()
{
    cout << "Enter dollar \n";
    cin >> dollars;
    cout << "Enter cents \n";
    cin >> cents;
    if( dollars < 0 || cents < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
}