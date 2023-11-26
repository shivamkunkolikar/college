#include<iostream>
using namespace std;
class Temp {
    private:
        int num;
    public:
        Temp(int num = 0) {
            this->num = num;
        }
        friend istream& operator >>(istream &din, Temp &obj) {
            int num;
            din >> num;
            obj.num = num;
            return din;
        }
        friend ostream& operator <<(ostream &dout, Temp &obj) {
            dout << obj.num;
            return dout;
        } 
};
int main() {
    Temp x, y;
    cout << "Enter values of x and y : ";
    cin >> x >> y;
    cout << "The values of x and y : \n";
    cout << x << " " << y << endl;
    return 0;
}
/*
OUTPUT:
Enter values of x and y : 10 20
The values of x and y :
10 20
*/