// P83.cpp - This program adds money of two different people
// It reads the amounts for two people from an
// input file in_file.dat and writes the result into a file out_file.dat

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class AltMoney
{
    public:
        AltMoney();
        friend istream& operator >>(istream& ins, AltMoney& m);
        friend AltMoney operator +(AltMoney m1, AltMoney m2);
        friend ofstream& operator <<(ofstream& ous, AltMoney m);
    private:
        int dollars;
        int cents;
};

istream& operator >>(istream& ins, AltMoney& m);
void get_streams(ifstream& ins, ofstream& ous);
ofstream& operator <<(ofstream& ous, AltMoney m);

int main()
{
    ifstream ins;
    ofstream ous;
    AltMoney m1, m2, sum;

    get_streams(ins, ous);

    ins>>m1;
    ous << "The first money is:";
    ous<<m1;

    ins>>m2;
    ous << "The second money is:";
    ous<<m2;

    sum = m1 + m2;
    ous << "The sum is:";
    ous<<sum;

    ins.close();
    ous.close();

    return 0;
}

AltMoney::AltMoney()
{
}

ofstream& operator <<(ofstream& ous, AltMoney m)
{
    ous << "$" << m.dollars << ".";
    if (m.cents <= 9)
        ous << "0";  //to display a 0 on the left for numbers less than 10
    ous << m.cents << endl;
}

AltMoney operator +(AltMoney m1, AltMoney m2)
{
    AltMoney temp;
    int extra = 0;
    temp.cents = m1.cents + m2.cents;
    if (temp.cents >= 100)
    {
        temp.cents = temp.cents - 100;
        extra = 1;
    }
    temp.dollars = m1.dollars + m2.dollars + extra;

    return temp;
}

istream& operator >>(istream& ins, AltMoney& m)
{
    int d, c;
    ins >> d;
    ins >> c;
    if (d < 0 || c < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
    m.dollars = d;
    m.cents = c;
}

void get_streams(ifstream& ins, ofstream& ous)
{
    ins.open("in_file.dat");
    if (ins.fail())
    {
       cout << "Failed to open the input file. \n";
       exit(1);
    }

    ous.open("out_file.dat");
    if (ous.fail())
    {
       cout << "Failed to open the output file. \n";
       exit(1);
    }
}