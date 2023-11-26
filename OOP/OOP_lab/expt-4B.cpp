#include<iostream>
using namespace std;
class Temp {
    private:
        int a;
    public:
        Temp(int a = 0) {
            this->a = a;
        }
        friend int operator +(int num, Temp &obj) {
            return (num + obj.a);
        }
        int operator *(Temp &obj) {
            return (a * obj.a);
        }
        int operator -(int num) {
            return (a - num);
        }
        int disp_val() {
            return a;
        }
};
int main() {
    Temp x, y;
    x = 1;
    y = 2;
    cout << "Initial values \n" << "x = " << x.disp_val();
    cout << " y = " << y.disp_val() << endl; 
    x = 5 + y;
    cout << "x = 5 + y = " << x.disp_val() << endl;
    x = x * y;
    cout << "x = x * y = " << x.disp_val() << endl;
    x = y - 5;
    cout << "x = y - 5 = " << x.disp_val() << endl;
    return 0;
}
/*
OUTPUT:
Initial values 
x = 1 y = 2
x = 5 + y = 7
x = x * y = 14
x = y - 5 = -3
*/