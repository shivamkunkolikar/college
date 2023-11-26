#include<iostream>
using namespace std;
class A
{
	private:
		int numA;
	public:
		A(A& obj1)
		{
			numA = obj1.numA;
		}
		A(int num = 0)
		{
			numA = num;
		}
		void display()
		{
			cout << "Contents of Obj : " << numA << endl;
		}
};
int main()
{
	A obj1(5);
	A obj2(obj1);
	obj1.display();
	obj2.display();
	return 0;
}
/*
OUTPUT :
Contents of Obj : 5
Contents of Obj : 5
*/