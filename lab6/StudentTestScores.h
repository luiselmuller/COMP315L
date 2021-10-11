/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This Class contains functions used to 
|create and manage objects that store 
|student information.
|--------------------------------------*/
#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H

#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScore
{
private:
	string studentName;	//The student's name
	double* testScores; //Point to array of test scores
	int numTestScores;	//Number of test scores

	// Private member function to create an
	// array of test scores.
	void createTestScoresArray(int size)
	{
		numTestScores = size;
		testScores = new double[size];
		for (int i = 0; i < size; i++)
			testScores[i] = DEFAULT_SCORE;
	}

public:
	// Constructor
	StudentTestScore(string name, int numScore)
	{
		studentName = name;
		createTestScoresArray(numScore);
	}

	// Copy constructor
	// YOU MUST IMPLEMENT THIS FUNCTION
	StudentTestScore(const StudentTestScore& obj)
	{
		// PLACE YOU CODE HERE
		//we define the size of the new array as the size of the argument objects array size, then we create
		//the new array with that size and initialize the data in the new array with the data of the other 
		//objects array
        numTestScores = obj.numTestScores;
		studentName = obj.studentName;
        testScores = new double[numTestScores];
		for(int i = 0; i < numTestScores; i++)
        	testScores[i] = obj.testScores[i];
	}

	// Destructor
	// YOU MUST IMPLEMENT THIS FUNCTION
	~StudentTestScore()
	{
		// PLACE YOU CODE HERE
        delete [] testScores;
	}

	// The setTestScore function sets a specific
	// test score's value.
	void setTestScore(double score, int index)
	{
		testScores[index] = score;
	}

	// Set the student's name.
	void setStudentName(string name)
	{
		studentName = name;
	}

	// Get the student's name.
	string getStudentName() const
	{
		return studentName;
	}

	// Get the number of test scores.
	int getNumTestScores() const
	{
		return numTestScores;
	}

	// Get a specific test score.
	double getTestScore(int index) const
	{
		return testScores[index];
	}

	// Overloaded = operator
	// YOU MUST IMPLEMENT THIS FUNCTION
	const StudentTestScore operator=(const StudentTestScore& right)
	{ 
		// PLACE YOU CODE HERE
		//same process as in the copy constructor
		if(this == &right) //if equal returns the value of the left side
			return *this;
		numTestScores = right.numTestScores;
		testScores = new double[numTestScores];
		studentName = right.studentName;
		for(int i = 0; i < numTestScores; i++)
        	testScores[i] = right.testScores[i];
	}
};
#endif