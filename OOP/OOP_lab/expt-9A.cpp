#include<iostream>
#include<fstream>
using namespace std;
int main() {
    int n1, n2, data;
    ofstream fout;
    fout.open("file1.txt");
    cout << "Enter no. of units in file 1 : ";
    cin >> n1;
    cout << "\tEnter the following : \n";
    for(int i=0 ; i<n1 ; i++) {
        cout << "\tEnter num " << i+1 << " : ";
        cin >> data;
        fout << data << endl;
    }
    fout.close();

    fout.open("file2.txt");
    cout << "Enter no. of units in file 2 : ";
    cin >> n2;
    cout << "\tEnter the following : \n";
    for(int i=0 ; i<n2 ; i++) {
        cout << "\tEnter num " << i+1 << " : ";
        cin >> data;
        fout << data << endl;
    }
    fout.close();

    int arr1[n1], arr2[n2], arr3[n1 + n2];
    ifstream fin;
    fin.open("file1.txt");
    for(int i=0 ; i<n1 ; i++) fin >> arr1[i];
    fin.close();
    fin.open("file2.txt");
    for(int i=0 ; i<n2 ; i++) fin >> arr2[i];
    fin.close();
    int a = 0, b = 0, c = 0;
    while(a < n1 && b < n2) {
        if(arr1[a] < arr2[b]) {
            arr3[c] = arr1[a];
            a++; c++;
        }
        else if(arr2[b] < arr1[a]) {
            arr3[c] = arr2[b];
            b++; c++;
        }
        else {
            arr3[c] = arr1[a];
            a++; c++;
            arr3[c] = arr2[b];
            b++; c++;
        }
    }
    while(a != n1) {
        arr3[c] = arr1[a];
        a++; c++;
    }
    while(b != n2) {
        arr3[c] = arr2[b];
        b++; c++;
    }

    fout.open("file3.txt");
    for(int i=0 ; i<n1 + n2 ; i++) fout << arr3[i] << endl;
    fout.close();

    cout << " Contents of file 3 : \n";
    fin.open("file3.txt");
    while(fin.eof() == 0) {
        fin >> data;
        cout << data << endl;
    }
    fin.close();

    return 0;
}
/*
OUTPUT :
Enter no. of units in file 1 : 5
        Enter the following :
        Enter num 1 : 10
        Enter num 2 : 30
        Enter num 3 : 50
        Enter num 4 : 70
        Enter num 5 : 90
Enter no. of units in file 2 : 5
        Enter the following :
        Enter num 1 : 20
        Enter num 2 : 40
        Enter num 3 : 60
        Enter num 4 : 80
        Enter num 5 : 100
 Contents of file 3 :
10
20
30
40
50
60
70
80
90
100
*/