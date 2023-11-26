#include<iostream>
using namespace std;
int main()
{
    int rnc;
    cout << "Enter rows and columns of matrix : ";
    cin >> rnc;
    int mat[100][100];
    for(int i=0 ; i<rnc ; i++)
    {
        for(int j=0 ; j<rnc ; j++)
            cin >> mat[i][j]; 
    }
    for(int i=0 ; i<rnc ; i++)
    {
        if(i != rnc-i-1)
        {
            mat[i][i] = mat[i][i] + mat[i][rnc - i - 1];
            mat[i][rnc - i - 1] = mat[i][i] - mat[i][rnc - i - 1];
            mat[i][i] = mat[i][i] - mat[i][rnc - i - 1];
        }
    }
    for(int i=0 ; i<rnc ; i++)
    {
        for(int j=0 ; j<rnc ; j++)
            cout << mat[i][j] << " ";
        cout << endl; 
    }
    return 0;
}
/*
OUTPUT :
Enter rows and columns of matrix : 3
1  0  0
0  1  0
0  0  1
0 0 1
0 1 0
1 0 0
*/