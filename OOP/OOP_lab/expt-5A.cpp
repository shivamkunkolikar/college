#include<iostream>
using namespace std;
class Student {
    private:
        int s;
    public:
        void set_s(int s) { this->s = s; }
        int get_s() { return s; }
};
class Arts : public Student {
    private:
        int a;
    public:
        void set_a(int a) { this->a = a; }
        void display() {
            cout << "Arts Student : " << endl;
            cout << "S : " << get_s() << endl;
            cout << "A : " << a << endl;
        }
};
class Engineering : public Student {
    private:
        int e;
    public:
        void set_e(int e) { this->e = e; }
        int get_e() { return e; }
};
class Comp : public Engineering {
    private:
        int c;
    public:
        void set_c(int c) { this->c = c; }
        void display() {
            cout << "Comp Student : " << endl;
            cout << "S : " << get_s() << endl;
            cout << "E : " << get_e() << endl;
            cout << "C : " << c << endl;
        }
};
class Mech : public Engineering {
    private:
        int m;
    public:
        void set_m(int m) { this->m = m; }
        void display() {
            cout << "Mech Student : " << endl;
            cout << "S : " << get_s() << endl;
            cout << "E : " << get_e() << endl;
            cout << "M : " << m << endl;
        }
};
class Etc : public Engineering {
    private:
        int t;
    public:
        void set_t(int t) { this->t = t; }
        void display() {
            cout << "Etc Student : "<< endl;
            cout << "S : " << get_s() << endl;
            cout << "E : " << get_e() << endl;
            cout << "T : " << t << endl;
        }
};
class Medicine : public Student {
    private:
        int d;
    public:
        void set_d(int d) { this->d = d; }
        void display() {
            cout << "Medicine Student : " << endl;
            cout << "S : " << get_s() << endl;
            cout << "D : " << d << endl; 
        }
};
int main() {
    Arts as;
    as.set_s(1);
    as.set_s(2);
    as.display();
    
    Comp cs;
    cs.set_s(3);
    cs.set_e(4);
    cs.set_c(5);
    cs.display();
    
    Mech ms;
    ms.set_s(6);
    ms.set_e(7);
    ms.set_m(8);
    ms.display();
    
    Etc  es;
    es.set_s(9);
    es.set_e(10);
    es.set_t(11);
    es.display();

    Medicine ds;
    ds.set_s(12);
    ds.set_d(13);
    ds.display();
}
/*
OUTPUT:
Arts Student : 
S : 2
A : 0
Comp Student :
S : 3
E : 4
C : 5
Mech Student :
S : 6
E : 7
M : 8
Etc Student :
S : 9
E : 10
T : 11
Medicine Student :
S : 12
D : 13
*/
