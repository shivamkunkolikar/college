#include<iostream>
#include<stdlib.h>
using namespace std;
class Vector {
    private:
        int *v;
        int length;
    public:
        Vector(int length = 0, int ini_val = 0) {
            this->length = length;
            v = new int[length];
            for(int i=0 ; i<length ; i++)
                v[i] = ini_val;
        }
        int& val(int index) {
            if(index >= length || index < 0) {
                cout << "Error \n";
                return v[index];
            }
            else {
                return v[index];
            }
        }
        Vector operator *(int num) {
            for(int i=0 ; i<length ; i++)
                v[i] = v[i] * num;
            return *this;
        }
        Vector operator +(Vector vec) {
            Vector v1(length);
            if(length == vec.length) {
                for(int i=0 ; i<length ; i++) {
                    v1.v[i] = v[i] + vec.v[i];
                }
                return v1;
            }
        }
        int get_val(int index) {
            if(index >= length || index < 0) {
                cout << "nan";
                return -1; 
            }
            return v[index];
        }
        friend ostream& operator <<(ostream &dout, Vector &vec) {
            dout << "[";
            for(int i=0 ; i<vec.length ; i++) {
                if(i == vec.length - 1)
                    dout << vec.v[i] << "]";
                else
                    dout << vec.v[i] << ", ";
            }
            return dout;
        }
};
int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    Vector v1(n), v2(n);
    cout << "enter values of v1 : \n";
    for(int i=0 ; i<n ; i++) {
        cout << "Val " << i+1 << " : ";
        cin >> v1.val(i);
    }
    cout << "Vector v1 is    : " << v1 << endl;
    v2 = v1 * 5;
    cout << "Vector v1 * 5   : " << v2 << endl;
    v2 = v1 + v2;
    cout << "Vector v1 + v2  : " << v2 << endl;
    return 0;
}
/*
OUTPUT:
Enter n : 5
enter values of v1 :
Val 1 : 10
Val 2 : 20
Val 3 : 30
Val 4 : 40
Val 5 : 50
Vector v1 is    : [10, 20, 30, 40, 50]
Vector v1 * 5   : [50, 100, 150, 200, 250]
Vector v1 + v2  : [100, 200, 300, 400, 500]
*/