#include<iostream>
using namespace std;
int main()
{
    int num, fd, ld;
    cout << "Enter num : ";
    cin >> num;
    ld = num % 10;
    while(num != 0)
    {
        if(num/10 == 0)
            fd = num;
        num = num / 10;
    }
    cout << "First Digit : " << fd << endl;
    cout << "Last Digit  : " << ld << endl;
    return 0;
}
/*
OUTPUT:
Enter num : 1234
First Digit : 1
Last Digit  : 4
*/