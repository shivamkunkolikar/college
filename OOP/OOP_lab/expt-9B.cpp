#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class User {
    public:
        char name[50];
        char ph_no[11];
        void set_data(char name[], char ph_no[]) {
            strcpy(this->name, name);
            strcpy(this->ph_no, ph_no);
        }
        void show_data() {
            cout << "\t\tName   : " << name << endl;
            cout << "\t\tPh No. : " << ph_no << endl;
        }
};
int main() {
    int choice;
    bool run = true;
    User tmp;
    char name[50], ph_no[11];
    while(run) {
        cout << "Enter following options : " << endl;
        cout << "\t1. Enter user  " << endl;
        cout << "\t2. Search user " << endl;
        cout << "\t3. Edit user   " << endl;
        cout << "\t4. Exit        " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "\t\tEnter Name   : ";
                cin >> name;
                cout << "\t\tEnter ph no. : ";
                cin >> ph_no;
                ofstream fout(name);
                tmp.set_data(name, ph_no); 
                fout.write((char*) &tmp, sizeof(tmp));
                fout.close(); 
                break;
            }
            case 2: {
                cout << "\t\tEnter Name  : ";
                cin >> name;
                ifstream fin;
                fin.open(name);
                if(fin.bad() != 0) {
                    cout << " No Records Found \n\n";
                }
                else {
                    fin.read((char*)&tmp, sizeof(tmp));
                    tmp.show_data();
                }
                fin.close();
                break;
            }
            case 3: {
                cout << "\t\tEnter Name  : ";
                cin >> name;
                ifstream fin;
                fin.open(name);
                if(fin.bad() != 0) {
                    cout << " No Records Found \n\n";
                }
                else {
                    fin.close();
                    cout << "\t\tEnter new ph no. : ";
                    cin >> ph_no;
                    ofstream fout(name);
                    tmp.set_data(name, ph_no); 
                    fout.write((char*) &tmp, sizeof(tmp));
                    fout.close();
                }
                fin.close();
                break;
            }
            case 4:
                run = false;
                break;

            default:
                cout << "Invalid Choice \n";
                break;
        }
    }
}
/*
OUTPUT :
Enter following options : 
        1. Enter user
        2. Search user
        3. Edit user
        4. Exit
Enter choice : 1
                Enter Name   : abcd
                Enter ph no. : 1234567899
Enter following options :
        1. Enter user
        2. Search user
        3. Edit user
        4. Exit
Enter choice : 2
                Enter Name  : abcd
                Name   : abcd
                Ph No. : 1234567899
Enter following options :
        1. Enter user
        2. Search user
        3. Edit user
        4. Exit
Enter choice : 3
                Enter Name  : abcd
                Enter new ph no. : 9987654321
Enter following options :
        1. Enter user
        2. Search user
        3. Edit user
        4. Exit
Enter choice : 2
                Enter Name  : abcd
                Name   : abcd
                Ph No. : 9987654321
Enter following options :
        1. Enter user
        2. Search user
        3. Edit user
        4. Exit
Enter choice : 4

*/