#include<iostream>
using namespace std;
int count = 0;
class temp
{
	private:
		int a;
	public:
		temp()
		{
			count++;
			cout << "No. of obj created   : " << count << endl;
		}
		~temp()
		{
			count--;
			cout << "No. of obj remaining : " << count << endl;
		}
};
int main()
{
	temp a, b, c, d;
	{
		temp e;
	}
	{
		temp f;
	}
	return 0;
}
/*
OUTPUT :
No. of obj created   : 1
No. of obj created   : 2
No. of obj created   : 3
No. of obj created   : 4
No. of obj created   : 5
No. of obj remaining : 4
No. of obj created   : 5
No. of obj remaining : 4
No. of obj remaining : 3
No. of obj remaining : 2
*/