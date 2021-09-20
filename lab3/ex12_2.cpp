/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This program makes a student "database"
|where the person can input the student
|name and id one by one and then view all
|of the data in said "database".
|--------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student();
    void display();

private:
    string student_name, studentid_number;
};

int main()
{
    Student* sArr;

    //variable used to determine the size of the array
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    sArr = new Student[n];//dynamic array with n amount of students

    //used to iterate through the dynamic array and display each object in it
    for (int i = 0; i < n; i++)
    {
        sArr[i].display();
    }

    //deletes the block of allocated memory for sArr
    delete[] sArr;

    return 0;
}

//default constructor used to initialize the class variables
Student::Student()
{
    cin.ignore();//removes extra characters left after using cin
    cout << "Enter a student name: ";
    getline(cin, student_name);
    cout << "Enter a student id: ";
    getline(cin, studentid_number);
    cout << "Press enter to continue...";
    cout << "\n";
}

//function used to display the variable values
void Student::display()
{
    cout << "+-------------------------------------------------------------------------------+\n";
    cout << " Student Name | " << student_name << " \n";
    cout << " Student ID   | " << studentid_number << " \n";
}
