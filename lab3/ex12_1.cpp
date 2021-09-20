/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This program takes an input of an
|areas value and the units, divides it
|by 2 and by 4 and displays both results
|--------------------------------------*/

#include <iostream>
using namespace std;

class Area
{
    public:
    Area();
    void display();

    private:
    string units;
    float area_value;
};

int main ()
{
    Area *area1;

    area1 = new Area; // Variables created using the new operator are called dynamic variables
    area1 -> display();
    
    delete area1; // Delete the dynamic variable p1 and return the memory occupied by p1 to the freestore to be reused.

   return 0;
}

//default constructor that initializes the class members
Area::Area()
{
    cout<<"Input the value of an area: ";
    cin>>area_value;
    cout<<"\nInput the units: ";
    cin>>units;
}

void Area::display()
{
    cout<<"One-half of the area: "<<area_value/2<<units<<endl;
    cout<<"One-quarter of the area: "<<area_value/4<<units<<endl;
}