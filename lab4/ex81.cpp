/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This program takes 2 amounts of money
|as input from the user and then displays
|the sum and subtraction. It also outputs
|if money 1 is greater, less or equal
|to money 2.
|--------------------------------------*/
#include<iostream>
#include<cstdlib>
#include<cmath>

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
    cout << "The subtraction is: ";
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
    if (cents <= 9)
        cout << "0";  //to display a 0 in the left for numbers less than 10
    cout << cents << endl;
}

AltMoney add(AltMoney m1, AltMoney m2)
{
    AltMoney sum;
    int extra = 0;
    sum.cents = m1.cents + m2.cents;
    if (sum.cents >= 100)
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

    //converting the dollars and cents from both objects into one single double each and saving
    //the result of the subtraction to result
    double result = abs((m1.dollars + ((double)m1.cents / 100)) - (m2.dollars + ((double)m2.cents / 100)));
    //if cents are .569 the result will stay at .56 instead of .57 so this if statement makes the adjustment
    //trunc() - if we have 3.4 then trunc(3.4) will return 3
    sub.cents = (int)((result - trunc(result)) * 1000) % 10 >= 5 ? (int)((result - trunc(result)) * 100) + 1 
                : (int)((result - trunc(result)) * 100) ;
    sub.dollars = result;

    return sub;
}

void AltMoney::read_money()
{
    cout << "Enter dollar \n";
    cin >> dollars;
    cout << "Enter cents \n";
    cin >> cents;
    if (dollars < 0 || cents < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
}