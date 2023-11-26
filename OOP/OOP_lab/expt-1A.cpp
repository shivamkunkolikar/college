#include<iostream>
#include<stdlib.h>
using namespace std;
class student
{
    private:
        char name[50];
        char branch[50];
        int MATHS;
        int LD;
        int CO;
        int DS;
        int OOPS;
        int total_marks;
        int roll_no;
        float percentage;

    public:
        void getData(int roll);
        void showData();
        void clacTotalMarks();
};

void student::getData(int roll)
{
	cout << "\n";
	cout << "	Student " << roll << " : \n";
    cout << "		Enter Name   : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "		Enter Branch : ";
    cin >> branch;
    roll_no = roll;
    cout << "		Roll Number  : " << roll_no << endl; 
    cout << "		Enter marks of MATHS , LD, CO, DS, OOPS  : ";
    cin >> MATHS >> LD >> CO >> DS >> OOPS;
}

void student::showData()
{
    cout << "   	Name        : " << name << endl;
    cout << "   	Branch      : " << branch << endl;
    cout << "   	Roll Number : " << roll_no << endl; 
    cout << "   	Marks Obtained For following subjects :\n";
    cout << "		MATHS : " << MATHS << endl;
    cout << "		LD    : " << LD << endl;
    cout << "		CO    : " << CO << endl;
    cout << "		DS    : " << DS << endl;
    cout << "		OOPS  : " << OOPS << endl;
    cout << "		TOTAL MARKS     : " << total_marks << endl;
    cout << "		PERCENTAGE      : " << percentage << " %" << endl;
    
}

void student::clacTotalMarks()
{
    total_marks = MATHS + LD + CO + DS + OOPS;
    percentage = (float)total_marks;
    percentage = (percentage/500) * 100;
}


int main()
{
    student s[3];
    int n = 3; 
    bool data_filled = false;
    bool result_computed = false;
    int choice, roll;
    do
    {
		cout << "\n\n";
		cout << "------------------------------------------------------------\n";
        cout << "   1. Enter Details of Student \n";
        cout << "   2. To Calculate result \n";
        cout << "   3. To Dispaly details of all students \n";
        cout << "   4. To Exit \n";
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                for(int i=0 ; i<n ; i++)
                    s[i].getData(i+1);
                data_filled = true;
                break;

            case 2:
            	if(data_filled == false)
            	{
            		cout << "	Please fill data first \n";
            		break;
            	}
                for(int i=0 ; i<n ; i++)
                	   s[i].clacTotalMarks();
                result_computed = true;
                break;

            case 3:
            	if((data_filled == false) || (result_computed == false))
            	{
            		cout << "	Data not entered OR Results not Computed\n";
            		break;
            	}
                cout << "	Enter roll number : ";
                cin >> roll;
                if(roll > n)
                {
                	cout << "	Student Not found \n";
                	break;
                }
                s[roll-1].showData();

            case 4:
                //exit(1);
                break;
            
            default:
                cout << "INVALID OPTION !!! \n";
                break;
        }
    }while(choice != 4);
    return 0;
}
/*
OUTPUT :
------------------------------------------------------------
   1. Enter Details of Student
   2. To Calculate result
   3. To Dispaly details of all students
   4. To Exit
Enter choice : 1

        Student 1 : 
                Enter Name   : abcd efgh
                Enter Branch : Computer
                Roll Number  : 1
                Enter marks of MATHS , LD, CO, DS, OOPS  : 100 98 95 100 100

        Student 2 : 
                Enter Name   : ijkl mnop
                Enter Branch : Computer
                Roll Number  : 2
                Enter marks of MATHS , LD, CO, DS, OOPS  : 90 88 77 95 92

        Student 3 : 
                Enter Name   : qrst uvwx
                Enter Branch : Computer
                Roll Number  : 3
                Enter marks of MATHS , LD, CO, DS, OOPS  : 66 57 83 50 55


------------------------------------------------------------
   1. Enter Details of Student 
   2. To Calculate result 
   3. To Dispaly details of all students 
   4. To Exit 
Enter choice : 2


------------------------------------------------------------
   1. Enter Details of Student 
   2. To Calculate result 
   3. To Dispaly details of all students 
   4. To Exit 
Enter choice : 3
        Enter roll number : 2
        Name        : ijkl mnop
        Branch      : Computer
        Roll Number : 2
        Marks Obtained For following subjects :
                MATHS : 90
                LD    : 88
                CO    : 77
                DS    : 95
                OOPS  : 92
                TOTAL MARKS     : 442
                PERCENTAGE      : 88.4 %


------------------------------------------------------------
   1. Enter Details of Student
   2. To Calculate result
   3. To Dispaly details of all students
   4. To Exit
Enter choice : 4
*/