#include<iostream>
using namespace std;
void test(int x) {
    try {
        if(x == 0) throw x;
        else if(x == 1) throw ((float)x);
        else if(x == -1) throw 'x';
        else cout << "Number is : " << x << endl;
    }
    catch(int) {
        cout << " Caught Int " << endl;
    }
    catch(float) {
        cout << " Caugth Float " << endl;
    }
    catch(char) {
        cout << " Caught Charecter " << endl;
    }
};
int main() {
    cout << " x = 2 " << endl;
    test(2);
    cout << " x = 0 " << endl;
    test(0);
    cout << " x = 1 " << endl;
    test(1);
    cout << " x = -1 " << endl;
    test(-1);
    return 0;   
}
/*
OUTPUT :
x = 2 
Number is : 2
 x = 0
 Caught Int
 x = 1
 Caugth Float
 x = -1
 Caught Charecter
*/