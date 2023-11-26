#include<iostream>
using namespace std;
ostream& first(ostream &dout) {
    dout.fill('*');
    dout.width(23);
    return dout;
}
ostream& second(ostream &dout) {
    dout.fill('.');
    dout.setf(ios::internal, ios::adjustfield);
    dout.setf(ios::showpos);
    dout.width(5);
    return dout;
}
ostream& third(ostream &dout) {
    dout.fill('.');
    dout.precision(4);
    dout.setf(ios::right, ios::adjustfield);
    dout.setf(ios::showpoint);
    dout.width(23);
    return dout;
}

int main() {
    cout << "VALUE" << first << "MULT OF VALUE" << endl;
    for(int i=1 ; i<=4 ; i++) {
        cout << second << i << third << (2.0*((float)i)) << endl;
    }
}
/*
VALUE**********MULT OF VALUE
+...1.................+2.000
+...2.................+4.000
+...3.................+6.000
+...4.................+8.000
*/