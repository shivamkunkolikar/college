#include<iostream>
using namespace std;
#define DAT_T float
inline DAT_T add(DAT_T a, DAT_T b)
{
	return (a + b);
}
inline DAT_T subtract(DAT_T a, DAT_T b)
{
	return (a - b);
}
inline DAT_T multiply(DAT_T a, DAT_T b)
{
	return (a * b);
}
inline DAT_T divide(DAT_T a, DAT_T b)
{
	return (a / b);
}
int main()
{
	int choice;
	DAT_T a, b;
	do
	{
		cout << "\n\n";
		cout << "Enter Following code :- " << endl;
		cout << "\t1. Add Numbers      " << endl;
		cout << "\t2. Subtract Numbers " << endl;
		cout << "\t3. Multiply Numbers " << endl;
		cout << "\t4. Divide Numbers   " << endl;
		cout << "\t5. To Exit          " << endl;
		cout << "Enter choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\t\tEnter Number 1 : ";
				cin >> a;
				cout << "\t\tEnter Number 2 : ";
				cin >> b;
				cout << "\t\t        ANSWER : " << add(a, b) << endl;
				break;
				
			case 2:
				cout << "\t\tEnter Number 1 : ";
				cin >> a;
				cout << "\t\tEnter Number 2 : ";
				cin >> b;
				cout << "\t\t        ANSWER : " << subtract(a, b) << endl;
				break;
				
			case 3:
				cout << "\t\tEnter Number 1 : ";
				cin >> a;
				cout << "\t\tEnter Number 2 : ";
				cin >> b;
				cout << "\t\t        ANSWER : " << multiply(a, b) << endl;
				break;
				
			case 4:
				cout << "\t\tEnter Number 1 : ";
				cin >> a;
				cout << "\t\tEnter Number 2 : ";
				cin >> b;
				cout << "\t\t        ANSWER : " << divide(a, b) << endl;
				break;
				
			case 5:
				break;
				
			default:
				cout << "\t\tINVALID CHOICE !!! \n";
				break;
		}
	}while(choice != 5);
}
/*
OUTPUT :
Enter Following code :- 
        1. Add Numbers      
        2. Subtract Numbers 
        3. Multiply Numbers 
        4. Divide Numbers   
        5. To Exit
Enter choice : 1
                Enter Number 1 : 5
                Enter Number 2 : 2
                        ANSWER : 7


Enter Following code :-
        1. Add Numbers
        2. Subtract Numbers
        3. Multiply Numbers
        4. Divide Numbers
        5. To Exit
Enter choice : 2
                Enter Number 1 : 7
                Enter Number 2 : 5
                        ANSWER : 2


Enter Following code :-
        1. Add Numbers
        2. Subtract Numbers
        3. Multiply Numbers
        4. Divide Numbers
        5. To Exit
Enter choice : 3
                Enter Number 1 : 6
                Enter Number 2 : 3
                        ANSWER : 18


Enter Following code :-
        1. Add Numbers
        2. Subtract Numbers
        3. Multiply Numbers
        4. Divide Numbers
        5. To Exit
Enter choice : 4
                Enter Number 1 : 10
                Enter Number 2 : 4
                        ANSWER : 2.5


Enter Following code :-
        1. Add Numbers
        2. Subtract Numbers
        3. Multiply Numbers
        4. Divide Numbers
        5. To Exit
Enter choice : 5
*/
