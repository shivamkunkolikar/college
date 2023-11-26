#include<iostream>
#include<iomanip>
using namespace std;
class Customer
{
    private:
        char name[50];
        int units_consumed;
        float bill_amount;

    public:
        void get_data();
        void calculate_bill();
        void display_data();
};

void Customer::get_data()
{
    cout << "   Customer Name  : ";
    cin >> name;
    cout << "   Units Consumed : ";
    cin >> units_consumed;
}

void Customer::calculate_bill()
{
    if(units_consumed < 100)
        bill_amount = units_consumed * 0.6;
    else if(units_consumed >=100 && units_consumed < 300)
        bill_amount = (100 * 0.6) + ((units_consumed - 100) * 0.8);
    else if(units_consumed >= 300)
        bill_amount = (100 * 0.6) + (200 * 0.8) + ((units_consumed - 300) * 0.9);
    bill_amount = bill_amount + 50;
    if(bill_amount > 300)
        bill_amount = bill_amount + (0.15 * bill_amount);
}

void Customer::display_data()
{
    cout << "   Customer Name  : " <<  name << endl;
    cout << "   Bill Amount    : " << bill_amount << endl;
}
int main()
{
    int num;
    cout << "Enter number of Customers : ";
    cin >> num;
    Customer *cust = new Customer[num];
    cout << "Enter names and units consumed by customer : \n";
    for(int i=0 ; i<num ; i++)
    {
        cout << "Customer " << i+1 << " : \n";
        cust[i].get_data();
        cout << "\n\n";
    }
    for(int i=0 ; i<num ; i++)
        cust[i].calculate_bill();
    for(int i=0 ; i<num ; i++)
    {
        cust[i].display_data();
        cout << "\n";
    }
}
/*
OUTPUT :
Customer 1 : 
   Customer Name  : abcd
   Units Consumed : 60


Customer 2 : 
   Customer Name  : efghi
   Units Consumed : 150


Customer 3 : 
   Customer Name  : jklmn
   Units Consumed : 260


Customer 4 : 
   Customer Name  : pqrst
   Units Consumed : 330


Customer 5 : 
   Customer Name  : uvwxyz
   Units Consumed : 460


   Customer Name  : abcd
   Bill Amount    : 86

   Customer Name  : efghi
   Bill Amount    : 150

   Customer Name  : jklmn
   Bill Amount    : 238

   Customer Name  : pqrst
   Bill Amount    : 297

   Customer Name  : uvwxyz
   Bill Amount    : 476.1

*/