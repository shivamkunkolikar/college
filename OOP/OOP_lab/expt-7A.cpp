#include<iostream>
using namespace std;
int main() {
    cout.width(2);
    cout << "n";
    cout << "\t";
    cout.width(15);
    cout << "Inverse_of_n \t";
    cout.width(15);
    cout << "Sum_of_terms\n";
    float sum = 0;
    cout.precision(4);
    for(int i=1 ; i<=10 ; i++) {
        cout.setf(ios::right, ios::adjustfield);
        cout.width(2);
        cout << i;
        cout << "\t";
        
        cout.setf(ios::scientific, ios::floatfield);
        cout.setf(ios::left, ios::adjustfield);
        cout.width(15);
        cout << (1.0 / ((float)i));
        cout << "\t";

        cout.setf(ios::showpoint);
        cout.setf(ios::left, ios::adjustfield);
        cout.width(15);
        sum = sum + (1.0 / ((float)i));
        cout << sum;
        cout << "\n";
    }
    return 0;
}
/*
OUTPUT:
n       Inverse_of_n     Sum_of_terms
 1      1.0000e+00      1.0000e+00
 2      5.0000e-01      1.5000e+00     
 3      3.3333e-01      1.8333e+00
 4      2.5000e-01      2.0833e+00
 5      2.0000e-01      2.2833e+00
 6      1.6667e-01      2.4500e+00
 7      1.4286e-01      2.5929e+00
 8      1.2500e-01      2.7179e+00
 9      1.1111e-01      2.8290e+00
10      1.0000e-01      2.9290e+00

*/