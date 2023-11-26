#include<iostream>
#include<string.h>
using namespace std;
class Student {
    public:
        char name[30];
        void set_name(char str[]) {
            strcpy(name, str);
        }
};
class Test : virtual public Student {
    public:
        int sub1, sub2;
        void set_sub_mks(int a, int b) {
            sub1 = a;
            sub2 = b;
        }
};
class TermWork : virtual public Student {
    public:
        int m1, m2;
        void set_mk_mks(int a, int b) {
            m1 = a;
            m2 = b;
        }
};
class Result : public Test, public TermWork {
    public:
        int total;
        void calc_total() {
            total = sub1 + sub2 + m1 + m2;
        }
        void display() {
            cout << "Name         : " << name << endl;
            cout << "Total Marks  : " << total << endl; 
        }
};
int main() {
    Result r;
    r.set_name("abc");
    r.set_sub_mks(89, 92);
    r.set_mk_mks(24, 21);
    r.calc_total();
    r.display();
    return 0;
}
/*
OUTPUT:
Name         : abc
Total Marks  : 226
*/
