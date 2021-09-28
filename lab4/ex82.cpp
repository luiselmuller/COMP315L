/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This program takes 2 amounts of money
|as input from the user and then displays
|the sum and subtraction.
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
    friend AltMoney operator +(AltMoney m1, AltMoney m2);
    friend AltMoney operator -(AltMoney m1, AltMoney m2);
    friend bool operator >(AltMoney m1, AltMoney m2);
    friend bool operator <(AltMoney m1, AltMoney m2);
    friend bool operator ==(AltMoney m1, AltMoney m2);
    void display_money();
    void read_money();
private:
    int dollars;
    int cents;
};

int main()
{
    int d, c;
    AltMoney m1, m2, sum, sub;

    m1.read_money();
    cout << "The first money is:";
    m1.display_money();

    m2.read_money();
    cout << "The second money is:";
    m2.display_money();

    sum = m1 + m2;
    cout << "The sum is:";
    sum.display_money();

    sub = m1 - m2;
    cout << "The subtraction is: ";
    sub.display_money();

    //this if statement first verifies if m1 and m2 are equal, if not then it checks if m1 is greater 
    //than m2 and then if m2 is greater than m1, if neither are true then it checks if either is less than the other
    //example: m1 = 2, m2 = 3 - output: Money 2 is greater than Money 1
    //m2 = 3, m1 = 2 - output: Money 1 is greater than Money 2 || m2 = 3, m1 = 3 - output: Both are equal
    if(m1 == m2)
    {
        cout<<">Money 1 and Money 2 are equal\n";
    }
    else
    {
        if(m1 > m2)
        {
            cout<<">Money 1 is greater than Money 2\n";
        }
        else if(m2 > m1)
        {
            cout<<">Money 2 is greater than Money 1\n";
        }
        else
        {
            if(m1 < m2)
                cout<<">Money 1 is less than Money 2\n";
            else if(m2 < m1)
                cout<<">Money 2 is less than Money 1\n";
        }
    
    }

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

AltMoney operator +(AltMoney m1, AltMoney m2)
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

AltMoney operator -(AltMoney m1, AltMoney m2)
{
    AltMoney sub;

    //converting the dollars and cents from both objects into one single double each and saving
    //the result of the subtraction to result
    double result = abs((m1.dollars + ((double)m1.cents / 100)) - (m2.dollars + ((double)m2.cents / 100)));

    //if cents are .569 the result will stay at .56 instead of .57 so this if statement makes the adjustment
    //first it takes the third decimal number and sees if it's greater or equal than 5, then it sums 1 if true
    sub.cents = (int)((result - trunc(result)) * 1000) % 10 >= 5 ? (int)((result - trunc(result)) * 100) + 1 
                : (int)((result - trunc(result)) * 100) ;
    sub.dollars = result;

    return sub;
}

//The if statement first verifies if the dollars are* equal, if they are equal then it checks if m1 is greater than m2
//if m1 is greater then true is returned, if not false. If the dollars are not* equal then it checks if the cents
//in m1 are greater than the ones in m2, if they are then true is returned if not then false
bool operator >(AltMoney m1, AltMoney m2)
{
    return m1.dollars != m2.dollars ? m1.dollars > m2.dollars ? true : false : m1.cents > m2.cents ? true : false;
}

//Works almost the same as the greater than operator if statement but instead of checking if dollars and cents
//are greater it checks if they are less
bool operator <(AltMoney m1, AltMoney m2)
{
    return m1.dollars != m2.dollars ? m1.dollars < m2.dollars ? true : false : m1.cents < m2.cents ? true : false;
}

//If everything is equal true is returned, if not false
bool operator ==(AltMoney m1, AltMoney m2)
{
    return m1.dollars == m2.dollars && m1.cents == m2.cents ? true : false;
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