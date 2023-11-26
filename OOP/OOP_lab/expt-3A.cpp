#include<iostream>
using namespace std;
class complex
{
	private:
		float real;
		float imag;

	public:
		complex(float a, float b);
		friend complex sum(complex a, complex b);
		void display();
};
complex::complex(float a=0.0, float b=0.0)
{
	real = a;
	imag = b;
}
complex sum(complex a, complex b)
{
	complex ans;
	ans.real = a.real + b.real;
	ans.imag = a.imag + b.imag;
	return ans;
}
void complex::display()
{
	cout << real;
	if(imag < 0)
		cout << " " << imag << "i" << endl;
	else
		cout << " + " << imag  << "i" << endl;
}
int main()
{
	complex a(1.1, 1.2);
	complex b = complex(1.3, 1.4);
	complex c;
	c = sum(a, b);
	c.display();
	return 0;
}
/*
OUTPUT :
2.4 + 2.6i
*/