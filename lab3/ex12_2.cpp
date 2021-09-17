/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|This program makes a student "database"
|where the person can input the student
|name and id one by one and then view all
|of the data in the database.
|--------------------------------------*/

#include <iostream>

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
    Student *sArr;

    //this variable is used to determine the size of the array
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;

    sArr = new Student[n];//dynamic array with n amount of students

    //used to iterate through the dynamic array and display each object in it
    for(int i = 0; i < n; i++)
    {
        sArr[i].display();
    }
    
    //deletes the block of allocated memory for sArr
    delete [] sArr;

}

//default constructor used to initialize the class variables
Student::Student()
{
    cout<<"Enter a student name: ";
    cin.ignore();//removes extra characters left after using cin
    getline(cin, student_name);
    cout<<"Enter a student id: ";
    getline(cin, studentid_number);
    cout<<"\n";
}

//function used to display the variables
void Student::display()
{
    cout<<"Student name -> "<<student_name<<" | Student ID -> "<<studentid_number<<"\n";
}
