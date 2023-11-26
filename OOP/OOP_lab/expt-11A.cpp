#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1, str2;
    str1 = "Engineering";  //string assignment
    cout << "str1 after assignment       : " << str1 << endl;
    str2 = " College";
    str1 = str1 + str2;  // string concatination
    cout << "str1 + str 2 (concatination): " << str1 << endl;

    if(str1 == str2) cout << "str1 is equal to str2" << endl; //string comparision
    else cout << "str1 is not equal to str2 " << endl;

    string sub = str1.substr(0, 11); //substring 
    cout << "Substring from location 0 till 11 characters : " << sub << endl;

    char c = str1.at(8); //character at 8th location of str1
    cout << "Character at 8th location of str1 : " << c << endl;

    string a = "Engineering";
    string b = "College";
    //swaping a and b
    cout << "a = " << a << "\t" << "b = " << b << endl;
    string tmp = a;
    a = b;
    b = tmp;
    cout << "a = " << a << "\t" << "b = " << b << endl;
    return 0;
}
/*
OUTPUT:
str1 after assignment       : Engineering
str1 + str 2 (concatination): Engineering College
str1 is not equal to str2
Substring from location 0 till 11 characters : Engineering
Character at 8th location of str1 : i
a = Engineering b = College
a = College     b = Engineering

*/