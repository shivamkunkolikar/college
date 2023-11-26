#include <iostream>
using namespace std;
class DB;
class DM
{
    private:
        int metres;
        int centimetres;

    public:
        DM(int m = 0, int cm = 0)
        {
            metres = m;
            centimetres = cm;
        }
        void display()
        {
            cout << metres << "m " << centimetres << "cm " << endl;
        }
        void readValue(int m, int cm)
        {
            metres = m;
            centimetres = cm;
        }
        friend DM add(DM a, DB b);
};
class DB
{
    private:
        int feet;
        int inches;

    public:
        DB(int f = 0, int inch = 0)
        {
            feet = f;
            inches = inch;
        }
        void display()
        {
            cout << feet << "ft " << inches << "inch "<< endl;
        }
        void readValue(int f, int inch)
        {
            feet = f;
            inches = inch;
        }
        friend DM add(DM a, DB b);
};
DM add(DM a, DB b)
{
    double cms = 2.54 * ((b.feet * 12) + b.inches);
    DM tmp;
    tmp.metres = cms / 100;
    tmp.centimetres = ((int)cms) % 100;
    tmp.metres = tmp.metres + a.metres;
    tmp.centimetres = tmp.centimetres + a.centimetres;
    return tmp;
}
int main()
{
    int q1, q2;
    DM a, sum;
    DB b;
    cout << "Enter Distance 1 in metre and cms : ";
    cin >> q1 >> q2;
    a.readValue(q1, q2);
    cout << "Enter Distance 2 in feet and inch : ";
    cin >> q1 >> q2;
    b.readValue(q1, q2);
    sum = add(a, b);
    cout << "Sum of Distance 1 and Distance 2  : ";
    sum.display();  
    return 0;
}
/*
OUTPUT :
Enter Distance 1 in metre and cms : 2 20
Enter Distance 2 in feet and inch : 5 4
Sum of Distance 1 and Distance 2  : 3m 82cm
*/
