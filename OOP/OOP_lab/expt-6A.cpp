#include<iostream>
using namespace std;
class Media {
    private:
        int m;
    public:
        Media(int m) {
            this->m = m;
        }
        virtual void display() {
            cout << "M = " << m << endl;
        }
};
class Book : public Media {
    private:
        int b;
    public:
        Book(int m, int b) : Media(m) {
            this->b = b;
        }
        void display() {
            cout << "B = " << b << endl;
        }
};
class Tape : public Media {
    private:
        int t;
    public:
        Tape(int m, int t) : Media(m) {
            this->t = t;
        } 
        void display() {
            cout << "T = " << t << endl;
        }
};
int main() {
    Book b(10, 20);
    Tape t(30, 40);
    Media *m;
    m = &b;
    m->display();
    m = &t;
    m->display();
    return 0;
}
/*
OUTPUT:
B = 20
T = 40
*/