#include<iostream>
using namespace std;
int fact(int num)
{
	int ans = 1;
	for(int i=1 ; i<=num ; i++)
		ans = ans * i;
	return ans;
}
void krishnamurthy(int &num)
{
	int tmp = num, ans = 0;
	while(tmp != 0)
	{
		ans = ans + fact(tmp % 10);
		tmp = tmp / 10;
	}
	if(ans == num)
		cout << "Entered number is Krishnamurthy Number" << endl;
	else
		cout << "Entered number is Not Krishnamurthy Number" << endl;
}
int main()
{
	int number;
	cout << "Enter Number : ";
	cin >> number;
	krishnamurthy(number);
	return 0;
}
/*
OUTPUT 1 :
Enter Number : 145
Entered number is Krishnamurthy Number

OUTPUT 3 :
Enter Number : 500
Entered number is Not Krishnamurthy Number
*/