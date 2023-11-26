#include<iostream>
#include<string.h>
using namespace std;
class mechStudent;
class compStudent
{
    private:
        int roll_no;
        char name[50];
        int tot_marks;
    
    public:
        void getdata();
        void showdata();
        friend void swap(compStudent &a, mechStudent &b);
};
class mechStudent
{
    private:
        int roll;
        char name[50];
        int total;

    public:
        void getdata();
        void showdata();
        friend void swap(compStudent &a, mechStudent &b);
};

void swap(compStudent &a, mechStudent &b)
{
    compStudent tmp = a;
    a.roll_no = b.roll;
    strcpy(a.name, b.name);
    a.tot_marks = b.total;

    b.roll = tmp.roll_no;
    strcpy(b.name, tmp.name);
    b.total = tmp.tot_marks;
}

void compStudent::getdata()
{
    cout << "\tEnter Roll No. : ";
    cin >> roll_no;
    cout << "\tEnter Name     : ";
    cin >> name;
    cout << "\tEnter Marks    : ";
    cin >> tot_marks;
}
void compStudent::showdata()
{
    cout << "\tRoll No.    : " << roll_no << endl;
    cout << "\tName        : " << name << endl;
    cout << "\tTotal Marks : " << tot_marks << endl;
}

void mechStudent::getdata()
{
    cout << "\tEnter Roll No. : ";
    cin >> roll;
    cout << "\tEnter Name     : ";
    cin >> name;
    cout << "\tEnter Marks    : ";
    cin >> total;
}
void mechStudent::showdata()
{
    cout << "\tRoll No.    : " << roll << endl;
    cout << "\tName        : " << name << endl;
    cout << "\tTotal Marks : " << total << endl;
}

int main()
{
    compStudent cs;
    mechStudent ms;
    cout << "Enter Details of Comp Student : " << endl;
    cs.getdata();
    cout << "Enter Details of Mech Student : " << endl;
    ms.getdata();
    swap(cs, ms);
    cout << "\n\n";
    cout << "-------------------------------------------------------------\n\n";
    cout << "Details of Comp Student  : " << endl;
    cs.showdata();
    cout << "Details of Mech Student  : " << endl;
    ms.showdata();
    return 0;
}
/*
OUTPUT:
Enter Details of Comp Student : 
        Enter Roll No. : 1
        Enter Name     : abcde
        Enter Marks    : 80
Enter Details of Mech Student : 
        Enter Roll No. : 2
        Enter Name     : efghi
        Enter Marks    : 85


-------------------------------------------------------------

Details of Comp Student  : 
        Roll No.    : 2
        Name        : efghi
        Total Marks : 85
Details of Mech Student  : 
        Roll No.    : 1
        Name        : abcde
        Total Marks : 80
*/