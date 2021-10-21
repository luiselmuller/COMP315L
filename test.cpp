#include<iostream>
#include<cstdlib>

using namespace std;


class Test {
private:
	int mx;
	float my;
	int medata; //some extra data

public:
	Test() {mx = 2; my = 2;}
	

	void print() { cout << "x = " << mx << " y = " << my << endl; }

	Test operator += ( Test& other)
	{
		
		this->mx = this->mx + other.mx;
		this->my = this->my + other.my;
		return other;
	}
	};


    int main()  
    {  
        int   var;  
        int   count;  
        float salary;  
          
        int    *varptr;     // declare a pointer variable to an integer  
        int    *countptr;   // declare a pointer variable to an integer  
        float  *salaryptr;  // declare a pointer variable to a float  
      
        varptr = &count;  
        countptr = &var; 
        salaryptr = &salary; 
      
        *varptr = 6;  
        *countptr = 980;  
        *salaryptr = 3200;  
      
        cout << var << endl;  
        cout << count << endl;  
        cout << salary << endl;  
      
       return 0;  
    }  



