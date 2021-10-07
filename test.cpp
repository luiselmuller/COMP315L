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
	Test t1, t2;
	Test t3;
	t3.print();

	t1 += t2;

	t1.print();

	return 0;
}


