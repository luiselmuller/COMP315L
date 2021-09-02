#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;


//prints the menu displaying user choices
void printMenu();

//takes in the radius of a circle as a parameter to calculate and return circle area
double circleArea(double r);

//takes in length and width of a rectangle to calculate and return rectangle area
double rectangleArea(double l, double w);

//takes in the base and height of a triangle to calculate and return the area
double triangleArea(double b, double h);

//takes in the radius of a circle to calculate and return the circumference
double circleCircumference(double r);

//takes in length and width of a rectangle to calculate and return perimeter
double rectanglePerimeter(double l, double w);

//takes in 3 sides of a triangle to calculate and return the perimeter
double trianglePerimeter(double s1, double s2, double s3);

//asks the user to continue or exit
void cont();

int main()
{
	int choice;
	double radius, side1, side2, side3, base, height, width, length;

	//makes cout print floats with a fixed number of decimals
	cout.setf(ios::fixed);

	do
	{
		printMenu();
		cin >> choice;
		if (choice < 0 || choice > 6)
		{
			cout << "Please enter a valid option.\n";
			system("pause");
			main();
		}
		else
		{
			switch (choice)
			{
			case 1:
				cout << "-Enter a radius: ";
				cin >> radius;
				cout << setprecision(4) << "The circle's area is " << circleArea(radius) << endl; //tested with radius 6, calculated result = 113.0973 - program result = 113.0973
				cont();
				break;

			case 2:
				cout << "-Enter a length: ";
				cin >> length;
				cout << "-Enter a width: ";
				cin >> width;
				cout << setprecision(4) << "The rectangle's area is " << rectangleArea(length, width) << endl; //tested with l = 10, w = 32, calculated result = 320 - program result = 320.0000
				cont();
				break;

			case 3:
				cout << "-Enter a base: ";
				cin >> base;
				cout << "-Enter a height: ";
				cin >> height;
				cout << setprecision(4) << "The triangle's area is " << triangleArea(base, height) << endl; //tested with b = 24, h = 53, calculated result = 636 - program result = 636.0000
				cont();
				break;

			case 4:
				cout << "-Enter a radius: ";
				cin >> radius;
				cout << setprecision(4) << "The circle's circumference is " << circleCircumference(radius) << endl; //tested with radius = 5.435, calculated result = 34.149192 - program result = 34.1491
				cont();
				break;

			case 5:
				cout << "-Enter a length: ";
				cin >> length;
				cout << "-Enter a width: ";
				cin >> width;
				cout << setprecision(4) << "The rectangle's perimeter is " << rectanglePerimeter(length, width) << endl; // tested with l = 5.56, w = -6.30, calculated result = -1.48 - program result = -1.4800
				cont();
				break;

			case 6:
				cout << "-Enter the value of side 1: ";
				cin >> side1;
				cout << "-Enter the value of side 2: ";
				cin >> side2;
				cout << "-Enter the value of side 3: ";
				cin >> side3;
				cout << setprecision(4) << "The triangle's perimeter is " << trianglePerimeter(side1, side2, side3) << endl; // tested with s1 = 55, s2 = 634, s3 = -34, calculated result = 655 - program result = 655.0000
				cont();
				break;
			}
		}
	} while (choice != 0);

}



void printMenu()
{
	cout << "\nThis is a geometry calculator \nChoose what you would like to calculate:" << endl;
	cout << "1. Find the area of a circle" << endl;
	cout << "2. Find the area of a rectangle" << endl;
	cout << "3. Find the area of a triangle" << endl;
	cout << "4. Find the circumference of a circle" << endl;
	cout << "5. Find the perimeter of a rectangle" << endl;
	cout << "6. Find the perimeter of a triangle" << endl;
	cout << "0.Exit" << endl;
	cout << "\nEnter the number of your choice > ";
}


//function definitions
double circleArea(double r)
{
	return M_PI * pow(r, 2);
}

double rectangleArea(double l, double w)
{
	return l * w;
}

double triangleArea(double b, double h)
{
	return .5 * (b * h);
}

double circleCircumference(double r)
{
	return 2 * M_PI * r;
}

double rectanglePerimeter(double l, double w)
{
	return (2 * l) + (2 * w);
}

double trianglePerimeter(double s1, double s2, double s3)
{
	return s1 + s2 + s3;
}

void cont()
{
	char q;
	cout << "\nWould you like to continue? y/n: ";
	cin >> q;
	if (tolower(q) == 'y')
		main();
	else
		exit(0);
}
