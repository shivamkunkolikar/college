#include<iostream>
using namespace std;

template<class T>
void swap_val(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b;
    cout << "Enter int values of a and b : ";
    cin >> a >> b;
    swap_val(a, b);
    cout << "Values of int a and b : " << a << " " << b << endl;
    char c, d;
    cout << "Enter char value of c and d : ";
    cin >> c >> d;
    swap_val(c, d);
    cout << "Values of char c and d : " << c << " " << d << endl;
    return 0;
}
/*
OUTPUT:
Enter int values of a and b : 10 20
Values of int a and b : 20 10
Enter char value of c and d : x y
Values of char c and d : y x
*/