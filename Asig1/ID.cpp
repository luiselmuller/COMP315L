#include "ID.h"
#include <iostream>

using namespace std;

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