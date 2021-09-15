/*---------------------------------------
|Luisel A. Muller Rodriguez 
|#S01394043
|
|--------------------------------------*/

#include <iostream>

using namespace std;

class Student
{
    public:
    Student();
    void display(Student array);

    private:
    string student_name, studentid_number;

};

int main()
{
    int n;
    cout<<"Enter the number of students in the database: ";
    cin>>n;

    Student *sArr;
    sArr = new Student[n];


    delete [] sArr;

}

Student::Student()
{
    cout<<"Enter the name for the student: ";
    cin>>student_name;

    cout<<"Enter the id for the student: ";
    cin>>studentid_number;
}

