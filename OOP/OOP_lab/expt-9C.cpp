#include<iostream>
#include<fstream>
#include<string.h>
#define IGN cin.ignore()
using namespace std;
class Student {
    private:
        char name[50];
        char branch[50];
        char address[100];
    public:
        char roll_no[3];
        void set_data(char roll[], char name[], char br[], char add[]) {
            strcpy(roll_no, roll);
            strcpy(this->name, name);
            strcpy(branch, br);
            strcpy(address, add);
        }
        char* get_name() { return name; }
        char* get_branch() { return branch; }
        char* get_address() { return address; }
        char* get_roll() { return roll_no; }
};
int main() {
    int choice;
    bool run = true;
    Student tmp;
    char roll[3];
    char name[50];
    char branch[50];
    char address[100];
    while(run) {
        cout << "\t1. Add a Student  " << endl;
        cout << "\t2. Show Details   " << endl;
        cout << "\t3. Edit Details   " << endl;
        cout << "\t4. To Exit        " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "\t\tEnter Roll No. : "; cin >> roll;
                cout << "\t\tEnter Name     : "; cin >> name;
                cout << "\t\tEnter Branch   : "; cin >> branch;
                cout << "\t\tEnter Address  : "; IGN; cin.getline(address, 100);
                tmp.set_data(roll, name, branch, address);
                ofstream fout(roll);
                fout.write((char*)&tmp, sizeof(tmp));
                fout.close();
                break;
            }
            case 2: {
                cout << "\t\tEnter Roll No. : "; cin >> roll;
                ifstream fin(roll);
                if(fin.bad()) {
                    cout << "No Records found \n";
                    break;
                }
                fin.read((char*)&tmp, sizeof(tmp));
                cout << "\t\tRoll No.  : " << tmp.get_roll() << endl;
                cout << "\t\tName      : " << tmp.get_name() << endl;
                cout << "\t\tBranch    : " << tmp.get_branch() << endl;
                cout << "\t\tAddress   : " << tmp.get_address() << endl;
                break;
            }
            case 3: {
                cout << "\t\tEnter Roll No. : "; cin >> roll;
                ofstream fout(roll);
                if(fout.bad()) {
                    cout << "No records Found \n";
                    break;
                }
                cout << "Enter new Data \n";
                cout << "\t\tEnter Roll No. : "; cin >> roll;
                cout << "\t\tEnter Name     : "; cin >> name;
                cout << "\t\tEnter Branch   : "; cin >> branch;
                cout << "\t\tEnter Address  : "; IGN; cin.getline(address, 100);
                tmp.set_data(roll, name, branch, address);
                fout.write((char*)&tmp, sizeof(tmp));
                break;
            }
            case 4:
                run = false;
                break;

            default:
                cout << "Invalid Options \n";
                break;
        }
    }
    return 0;
}
/*
OUTPUT:
 1. Add a Student  
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 1
                Enter Roll No. : 1
                Enter Name     : abcd
                Enter Branch   : computer
                Enter Address  : margao goa
        1. Add a Student
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 1
                Enter Roll No. : 2
                Enter Name     : efgh
                Enter Branch   : computer
                Enter Address  : panaji goa
        1. Add a Student
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 2
                Enter Roll No. : 1
                Roll No.  : 1
                Name      : abcd
                Branch    : computer
                Address   : margao goa
        1. Add a Student
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 3
                Enter Roll No. : 1
Enter new Data
                Enter Roll No. : 1
                Enter Name     : hijkl
                Enter Branch   : computer
                Enter Address  : margao goa
        1. Add a Student
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 2
                Enter Roll No. : 1
                Roll No.  : 1
                Name      : hijkl
                Branch    : computer
                Address   : margao goa
        1. Add a Student
        2. Show Details
        3. Edit Details
        4. To Exit
Enter choice : 4

*/