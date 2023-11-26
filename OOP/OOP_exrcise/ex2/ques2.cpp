#include<iostream>
using namespace std;
int main()
{
    int num, tnum, rev = 0;
    cout << "Enter number : ";
    cin >> num;
    tnum = num;
    while(tnum != 0)
    {
        rev = (rev * 10) + (tnum % 10);
        tnum = tnum / 10;
    }
    if(num == rev)
        cout << "The number is palindrome" << endl;
    else
        cout << "The number is not palindrome" << endl;
    return 0;
}
/*
OUTPUT:
Enter number : 121
The number is palindrome
*/