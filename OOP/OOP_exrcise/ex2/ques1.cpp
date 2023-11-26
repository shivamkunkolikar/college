#include<iostream>
using namespace std;
int main()
{
    int a[100], n, high = 0;
    cout << "Enter number of elements : ";
    cin >> n;
    for(int i=0 ; i<n ; i++)
    {
        cout << "Enter element " << i+1 << " : ";
        cin >> a[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] > high)
            high = a[i];
    }
    cout << "Highest Element is : " << high << endl;
    return 0;
}
/*
OUTPUT:
Enter number of elements : 5
Enter element 1 : 50
Enter element 2 : 30
Enter element 3 : 20
Enter element 4 : 40
Enter element 5 : 10
Highest Element is : 50
*/