#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    int fib[n] = {1,1};
    for(int i=2 ; i<n ; i++)
        fib[i] = fib[i-1] + fib[i-2];
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<(i + 1) ; j++)
            cout << fib[j] << " ";
        cout << endl;
    }
    return 0;
}
/*
OUTPUT :
Enter n : 5
1
1 1
1 1 2
1 1 2 3
1 1 2 3 5
*/