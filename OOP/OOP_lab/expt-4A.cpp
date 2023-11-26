#include<iostream>
using namespace std;
class Temp {
    
    private:
        int a;

    public:
        Temp(int a = 0) {
            this->a = a;
        }
        Temp operator ++() {
            Temp ret(a);
            a = a + 1;
            return ret;
        }
        Temp operator ++(int) {
            a = a + 1;
            return *this;
        }
        Temp operator --() {
            Temp ret(a);
            a = a - 1;
            return ret;
        }
        Temp operator --(int) {
            a = a - 1;
            return *this;
        }
        void display() {
            cout << a << endl;
        }
};

int main() {
    Temp t(10);
    cout << "t = ";
    t.display();
    t++;
    t.display();
    ++t;
    t.display();
    --t;
    t.display();
    t--;
    t.display();
    return 0;
}
/*
OUTPUT:
t = 10
11
12
11
10
*/