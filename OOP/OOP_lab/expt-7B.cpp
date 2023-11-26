#include<iostream>
#include<iomanip>
using namespace std;
ostream& head(ostream &dout) {
    dout.width(10);
    dout.setf(ios::left, ios::adjustfield);
    return dout;
}
ostream& data(ostream &dout) {
    dout.width(10);
    dout.setf(ios::right, ios::adjustfield);
    return dout;
}
int main() {
    int n;
    cout << "Enter number of lines : ";
    cin >> n;
    char par[n][100000];
    cout << "Start writing paragraph : " << endl;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        cin.getline(par[i], 100000);
    }
    int no_of_words = 0, no_of_characters = 0;
    for(int i=0 ; i<n ; i++) {
        int j = 0;
        while(par[i][j] != '\0') {
            if(par[i][j] != ' ') {
                no_of_characters++;
            }
            else {
                no_of_words++;
                while(par[i][j] == ' ')
                    j++;
                j = j - 1;
            }
            j++;
        }
        no_of_words++;
        no_of_characters++;
    }
    cout << head << "Lines" << head << "Words" << head << "Characters" << endl;
    cout << data << n << data << no_of_words << data << no_of_characters << endl;
    return 0;
}
/*
OUTPUT :
Enter number of lines : 3
Start writing paragraph :
qwety uiop
asdf gh jkl
zxcv bnm
Lines     Words     Characters
         3         7        26

*/