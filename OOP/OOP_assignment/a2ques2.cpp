#include<iostream>
#include<stdlib.h>
using namespace std;
class vector
{
    private:
        float *start_pointer;
        int length;
    public:
        vector(int size = 0, float initial_value = 0)
        {
            start_pointer = new float[size];
            for(int i=0 ; i<size ; i++)
                start_pointer[i] = initial_value;
            length = size;
        }
        int size()
        {
            return length;
        }
        void append_element(float element);
        void multiply_scalar(float scalar);
        void modify_value(int index, int data);
        int get_value(int index);
        void display_vector();
};
int  vector::get_value(int index)
{
    int value = start_pointer[index];
    return value;
}
void vector::modify_value(int index, int data)
{
    if(index >= 0 && index <= length) {
        start_pointer[index] = data;
    }
    else return;
}
void vector::append_element(float element)
{
    length++;
    start_pointer = (float*)realloc(start_pointer, length * sizeof(float));
    start_pointer[length - 1] = element;
}
void vector::multiply_scalar(float scalar)
{
    for(int i=0 ; i<length ; i++)
        start_pointer[i] = start_pointer[i] * scalar;
}
void vector::display_vector(void)
{
    cout << " ( ";
    for(int i=0 ; i<length-1 ; i++)
        cout << start_pointer[i] << ", ";
    cout << start_pointer[length - 1] << " )" << endl;
}
vector add_vectors(vector &a, vector &b)
{
    vector answer;
    int element;
    if(a.size() == b.size())
    {
        for(int i=0 ; i<a.size() ; i++)
        {
            element = a.get_value(i) + b.get_value(i);
            answer.append_element(element);
        }
    }
    return answer;
}
int main()
{
    vector a, b;
    //vector A
    a.append_element(10);
    a.append_element(20);
    a.append_element(30);
    a.append_element(40);
    a.append_element(50);

    //vector B
    b.append_element(10);
    b.append_element(20);
    b.append_element(30);
    b.append_element(40);
    b.append_element(50);

    cout << "Vector A   : ";
    a.display_vector();
    cout << "Vector B   : ";
    b.display_vector();

    vector c = add_vectors(a, b);
    cout << "Vector C   : ";
    c.display_vector();

    a.multiply_scalar(5);
    cout << "Vector A*5 : ";
    a.display_vector();

    b.modify_value(1, 10);
    cout << "Vector B   : ";
    b.display_vector();
    return 0;
}
/*

OUTPUT: 
Vector A   :  ( 10, 20, 30, 40, 50 )
Vector B   :  ( 10, 20, 30, 40, 50 )
Vector C   :  ( 20, 40, 60, 80, 100 )
Vector A*5 :  ( 50, 100, 150, 200, 250 )
Vector B   :  ( 10, 10, 30, 40, 50 )
*/
