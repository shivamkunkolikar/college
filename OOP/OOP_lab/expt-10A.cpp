#include<iostream>
using namespace std;

void divide(float a, float b) {
    try {
        if(b != 0) {
            cout << "Division : " << a / b << endl;
        }
        else {
            throw(b);
        }
    }
    catch(float) {
        cout << "EXCEPTION OCCURED (divide) : DIVIDED BY ZERO" << endl;
        throw;
    }
}

int main() {
    try {
        divide(20, 10);
        divide(20, 0);
    }
    catch(float) {
        cout << "EXCEPTION CAUGHT (main) : DIVIDED BY ZERO" << endl;
    }
    return 0;
}
/*
OUTPUT :
Division : 2
EXCEPTION OCCURED (divide) : DIVIDED BY ZERO
EXCEPTION CAUGHT (main) : DIVIDED BY ZERO
*/