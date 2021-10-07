// This program demonstrates the overloaded = operator
// the destructor, and the copy constructor.
#include <iostream>
#include "StudentTestScores.h"
using namespace std;

//Function prototype
void displayStudent(StudentTestScore);

int main()
{
	// Create a StudentTestScores object and
	// assign test scores.
	StudentTestScore student1("Kelly Thorton", 3);
	student1.setTestScore(100.0, 0);
	student1.setTestScore(95.0, 1);
	student1.setTestScore(80, 2);

	// Create another StudentTestScore object
	// with default test scores.
	StudentTestScore student2("Jimmy Griffin", 5);

	// Assign the student1 object to student2
	student2 = student1;

	StudentTestScore student3("Some student", 6);
	student3.setTestScore(100.0, 0);
	student3.setTestScore(95.0, 1);
	student3.setTestScore(90, 2);
	student3.setTestScore(60, 3);
	student3.setTestScore(93, 4);

	student3 = student2;
	// Display both objects. They should
	// contain the same data.
	student1.displayStudent();
	student2.displayStudent();
	student3.displayStudent();
	//replaced displayStudent(student1); and displayStudent(student2); with a function defined inside of the class
	//since displayStudent() was not displaying the names properly
	return 0;
}

// The displayStudent function accepts a
// StudentTestScores object's data.
void displayStudent(StudentTestScore s)
{
	cout << "Name: " << s.getStudentName() << endl;
	cout << "Test Scores: ";
	for (int i = 0; i < s.getNumTestScores(); i++)
		cout << s.getTestScore(i) << " ";
	cout << endl;
}