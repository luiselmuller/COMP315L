/*---------------------------------------
|Luisel A. Muller Rodriguez
|#S01394043
|This program allows you to create pair
|objects of different types making use 
|of the Pair class, in this case it 
|creates grade and  name pairs. Then 
|the pair values are displayed.
|--------------------------------------*/

#include <iostream>
#include <string>
#include "Header.h" 

using namespace std;


int main()
{
    //Pairs initialized with constructor
    Pair<double> gradesP1(93.5, 78.9);
    Pair<string> namesP1("Tom", "Martha");

    //Displays the values of the first pairs 
    gradesP1.display_pairs();   //Expected output: 93 - 78.9
    namesP1.display_pairs();    //Expected output: Tom - Martha

    //Pairs initialized with set_element() function
    Pair<double> gradesP2;
    Pair<string> namesP2;

    //Initializing values of the second pair, if these pairs were not initialized this way and left with the empty 
    //constructor intialization the output would be 0 for gradesP2 and an empty string for namesP2
    gradesP2.set_element(1, 94);
    gradesP2.set_element(2, 87);
    namesP2.set_element(1, "John");
    namesP2.set_element(2, "Kate");

    //Displays the values of the second pairs
    gradesP2.display_pairs();   //Expected output: 94 - 87
    namesP2.display_pairs();    //Expected output: John - Kate
   
    //Pairs initialized with constructor and displayed with get_element and cout
    Pair<double> gradesP3(89, 78.9);
    Pair<string> namesP3("Carl", "Sam");

    //Displays the values of the third pairs
    cout << gradesP3.get_element(1) << " - " << gradesP3.get_element(2) << "\n"; //Expected output: 89 - 78.9
    cout << namesP3.get_element(1) << " - " << namesP3.get_element(2) << "\n"; //Expected output: Carl - Sam

    return 0;

}
