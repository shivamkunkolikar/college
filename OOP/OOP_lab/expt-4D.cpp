#include<iostream>
using namespace std;
class String {
    private:
        char *sptr;
        int str_len;
    public:
        String(char str[] = "") {
            str_len = 0;
            while(str[str_len] != '\0') str_len++;
            sptr = new char[str_len + 1];
            for(int i=0 ; i<str_len ; i++) sptr[i] = str[i];
            sptr[str_len] = '\0';            
        }
        int size() {
            return str_len;
        }
        char* operator +(String &str) {
            char *ptr = new char[str_len + str.size()];
            for(int i=0 ; i<str_len ; i++) 
                ptr[i] = sptr[i];
            for(int i=0 ; i<str.size() ; i++) 
                ptr[str_len + i] = str.sptr[i];
            return ptr;
        }
        friend ostream& operator <<(ostream &dout, String &s) {
            cout << s.sptr;
            return dout;
        }
};
int main() {
    String s1 = "Engeenering ";
    String s2 = "College";
    String s3 = s1 + s2;
    cout << s3 << endl;
    if(s1.size() < s2.size()) {
        cout << "s1 is smaller" << endl;
        cout << s1 << endl;
    }
    else {
        cout << "s2 is smaller" << endl;
        cout << s2 << endl;
    }
    return 0;
}
/*
OUTPUT:
Engeenering College
s2 is smaller
College
*/