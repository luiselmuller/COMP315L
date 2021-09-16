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

    int n;
    cout<<"Enter the number of students: ";
    cin>>n;

    sArr = new Student[n];

    for(int i = 0; i < n; i++)
    {
        sArr[i].display();
    }

    delete [] sArr;

}

Student::Student()
{
    cout<<"Enter a student name: ";
    cin>>student_name;
    cout<<"Enter a student id: ";
    cin>>studentid_number;
    cout<<"\n";
}

void Student::display()
{
    cout<<"Student name -> "<<student_name<<" | Student ID -> "<<studentid_number<<"\n";
}
