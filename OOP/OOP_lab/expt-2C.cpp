#include<iostream>
#define PI 3.14
using namespace std;
float sqrt(float num)
{
	float ans = 1;
	for(int i=0 ; i<100 ; i++)
		ans = 0.5 * (ans + (num / ans));
	return ans;
}
float area(float radius)
{
	float ans;
	ans = PI * radius * radius;
	return ans;
}
float area(float length, float breadth)
{
	float ans;
	ans = length * breadth;
	return ans;
}
float area(float side1, float side2, float side3)
{
	float s, ans;
	s = (side1 + side2 + side3)/2;
	ans = sqrt(s * (s - side1)*(s - side2)*(s - side3));
	return ans;
}
int main()
{
	int choice;
	float a, b, c;
	do
	{
		cout << "\n\n";
		cout << "Enter Following code :- " << endl;
		cout << "\t1. Area of Circle     " << endl;
		cout << "\t2. Area of rectangle  " << endl;
		cout << "\t3. Area of triangle   " << endl;
		cout << "\t4. To Exit            " << endl;
		cout << "Enter choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\t\tEnter Radius   : ";
				cin >> a;
				cout << "\t\t        ANSWER : " << area(a) << endl;
				break;
				
			case 2:
				cout << "\t\tEnter Length   : ";
				cin >> a;
				cout << "\t\tEnter Breadth  : ";
				cin >> b;
				cout << "\t\t        ANSWER : " << area(a, b) << endl;
				break;
				
			case 3:
				cout << "\t\tEnter Side 1 : ";
				cin >> a;
				cout << "\t\tEnter Side 2 : ";
				cin >> b;
				cout << "\t\tEnter Side 3 : ";
				cin >> c;
				cout << "\t\t      ANSWER : " << area(a, b, c) << endl;
				break;
				
			case 4:
				break;
				
			default:
				cout << "\t\tINVALID CHOICE !!! \n";
				break;
		}
	}while(choice != 4); 
}
/*
OUTPUT:
Enter Following code :-
        1. Area of Circle
        2. Area of rectangle
        3. Area of triangle
        4. To Exit
Enter choice : 1
                Enter Radius   : 7
                        ANSWER : 153.86


Enter Following code :-
        1. Area of Circle
        2. Area of rectangle
        3. Area of triangle
        4. To Exit
Enter choice : 2
                Enter Length   : 4
                Enter Breadth  : 3
                        ANSWER : 12


Enter Following code :-
        1. Area of Circle
        2. Area of rectangle
        3. Area of triangle
        4. To Exit
Enter choice : 3
                Enter Side 1 : 3
                Enter Side 2 : 4
                Enter Side 3 : 5
                      ANSWER : 6


Enter Following code :-
        1. Area of Circle
        2. Area of rectangle
        3. Area of triangle
        4. To Exit
Enter choice : 4

*/