#include<iostream>
using namespace std;
class A {
    private:
        int a;
    public:
        A(int a) {
            this->a = a;
        }
        void display() {
            cout << "A = " << a << endl;
        }
};
class B : public A {
    private:
        int b;
    public:
        B(int a, int b) : A(a) {
            this->b = b;
        }
        void display() {
            cout << "B = " << b << endl;
        }
};
int main() {
    B obj(10, 20);
    obj.display();
    obj.A::display();
    return 0;
}
/*
OUTPUT:
B = 20
A = 10
*/