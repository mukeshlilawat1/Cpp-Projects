#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Student
{
private:
    int Student_RollNo;
    string Student_Name;
    char Student_Grade;

public:
    Student() : Student_RollNo(0), Student_Name(""), Student_Grade('\0') {}

    void setRollNo(int Student_RollNo)
    {
        this->Student_RollNo = Student_RollNo;
    }

    void setStudentName(string Student_Name)
    {
        this->Student_Name = Student_Name;
    }

    void setGrade(char Student_Grade)
    {
        this->Student_Grade = Student_Grade;
    }

    int getRollNo()
    {
        return Student_RollNo;
    }

    string getStudentName()
    {
        return Student_Name;
    }

    char getStudentGrade()
    {
        return Student_Grade;
    }
};

int main()
{
    Student Report_Card;

    bool exit = false;
    while (!exit)
    {
        system("cls");

        int val;

        cout << "Welcome To Student Report Card System : " << endl;
        cout << "---------------***********--------------" << endl;
        cout << "1. Report Card " << endl;
        cout << "2. Exit " << endl;
        cout << "Enter your Choice : " << endl;
        cin >> val;

        if (val == 1)
        {
            system("cls");
            int Student_RollNo;
            string Student_Name;

            cout << "Enter Your Roll No : " << endl;
            cin >> Student_RollNo;
            Report_Card.setRollNo(Student_RollNo);

            cout << "Enter Your Name : " << endl;
            cin >> Student_Name;
            Report_Card.setStudentName(Student_Name);

            int Math, Physics, Chemistry, Computer, Algorithm;
            int Marks_Avg;

            cout << "Enter Your Math Marks : " << endl;
            cin >> Math;
            cout << "Enter Your Physics Marks : " << endl;
            cin >> Physics;
            cout << "Enter Your Chemistry Marks : " << endl;
            cin >> Chemistry;
            cout << "Enter Your Computer Marks : " << endl;
            cin >> Computer;
            cout << "Enter Your Algorithm Marks : " << endl;
            cin >> Algorithm;

            system("cls");
            cout << "Student Report Card : " << endl;
            cout << "*************************" << endl;
            int total_Marks = Math + Physics + Chemistry + Computer + Algorithm;
            cout << "Total Marks of Student : " << total_Marks << endl;
            Marks_Avg = total_Marks / 5;
            cout << "Average Marks of Student : " << Marks_Avg << endl;

            if (Marks_Avg >= 90)
            {
                Report_Card.setGrade('A');
            }
            else if (Marks_Avg >= 80)
            {
                Report_Card.setGrade('B');
            }
            else if (Marks_Avg >= 70)
            {
                Report_Card.setGrade('C');
            }
            else if (Marks_Avg >= 60)
            {
                Report_Card.setGrade('D');
            }
            else if (Marks_Avg >= 33)
            {
                Report_Card.setGrade('F');
            }
            else
            {
                Report_Card.setGrade('F');
                cout << "Fail" << endl;
            }

            cout << "Grade Of Student : " << Report_Card.getStudentGrade() << endl;

            ofstream out("Student.txt", ios::app);
            if (out.is_open())
            {
                out << Report_Card.getRollNo() << " : " << Report_Card.getStudentName() << " : " << Report_Card.getStudentGrade() << endl;
                out.close();
                cout << "Report card is saved to file! " << endl;
            }
            else
            {
                cout << "Error: Unable to open file for writing." << endl;
            }
            Sleep(10000);
        }
        else if (val == 2)
        {
            system("cls");
            exit = true;
            cout << "Good Luck " << endl;
            Sleep(3000);
        }
    }
}
