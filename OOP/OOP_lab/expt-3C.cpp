#include<iostream>
#include<string.h>
using namespace std;
class temp
{
	private:
		char *str;
		int len;
	public:
		temp(char *p)
		{
			len = strlen(p);
			str = new char[len + 1];
			strcpy(str, p);
		}
		temp()
		{
			len = 0;
			str = NULL;
		}
		void join(temp a, temp b)
		{
			len =  a.len + b.len;
			str = new char[len + 1];
			strcpy(str, a.str);
			strcat(str, b.str);
		}
		void display()
		{
			cout << str << endl;
		}
};
int main()
{
	char *f1 = "Goa";
	temp name1(f1), name2("College"), name3("Engineering"), s1, s2;
	s1.join(name1, name2);
	s2.join(s1, name3);
	s2.display();
	return 0;
}
/*
OUTPUT :
GoaCollegeEngineering
*/