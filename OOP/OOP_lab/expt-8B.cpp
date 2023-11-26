#include<iostream>
using namespace std;
template<class T>
class Vector {
    private:
        T *sptr;
        int length;
    public:
        Vector(int length = 0, T ini_val = 0) {
            this->length = length;
            sptr = new T[length];
            for(int i=0 ; i<length ; i++)
                sptr[i] = ini_val;
        }
        T& set_val(int index) {
            return sptr[index];
        }
        T get_val(int index) {
            return sptr[index];
        }
        void display() {
            cout << "[";
            for(int i=0 ; i<length ; i++) {
                if(i == length - 1)
                    cout << sptr[i] << "]" << endl;
                else 
                    cout << sptr[i] << ", ";
            }
            cout << "\n";
        }
};
int main() {
    Vector<int> vei(5, 0);
    Vector<char> vec(5, 'a');
    vei.set_val(2) = 4;
    vec.set_val(2) = 'b';
    cout << "Inteager Vector  : ";
    vei.display();
    cout << "Character Vector : ";
    vec.display();
    return 0;
}
/*
OUTPUT:
Inteager Vector  : [0, 0, 4, 0, 0]

Character Vector : [a, a, b, a, a] 
*/