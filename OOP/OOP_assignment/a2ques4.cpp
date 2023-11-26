#include<iostream>
#include<string.h>
using namespace std;
class book {
    private:
        char *title;
        char *author;
        float price;
        int stock;
        void newPrice(float amount) {
            price = amount;
        }

    public:
        static int no_of_tr;
        static int no_of_utr;
        book(char strt[], char stra[], float amount = 0, int units = 0) {
            title = new char[strlen(strt) + 1];
            author = new char[strlen(stra) + 1];
            strcpy(title, strt);
            strcpy(author, stra);
            price = amount;
            stock = units;
        }
        book() {
            title = NULL;
            author = NULL;
            price = 0;
            stock = 0;
        }
        void in_BookData(char strt[], char stra[], float amount = 0, int units = 0) {
            title = new char[strlen(strt) + 1];
            author = new char[strlen(stra) + 1];
            strcpy(title, strt);
            strcpy(author, stra);
            price = amount;
            stock = units;
        }
        void updatePrice(float newAmount) {
            newPrice(newAmount);
        }
        bool checkBook(char strt[], char stra[]) {
            if((strcmp(title, strt) == 0) && (strcmp(author, stra) == 0)) {
                cout << "\n\n";
                cout << "------------------------------------------------------------" << endl;
                cout << "                         BOOK INFO                          " << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "   Name         : " << title << endl;
                cout << "   Author       : " << author << endl;
                cout << "   Amount       : " << price << endl;
                cout << "   Availability : ";
                if(stock == 0) 
                    cout << "Not Available " << endl;
                else if(stock < 5)
                    cout << "Limited in Stock " << endl;
                else 
                    cout << "Available " << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "\n\n";
                return true;
            }
            else
                return false;
        }
        void billBooks(int no_of_books) {
            if(no_of_books > stock) {
                cout << "\t\tRequired Copies Not in stock \n";
                return;
            }
            else {
                float billAmount = no_of_books * price;
                cout << "\n\n";
                cout << "------------------------------------------------------------" << endl;
                cout << "                           BILL                             " << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "   Name    : " << title << endl;
                cout << "   Author  : " << author << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "   amount per unit : " << price << endl;
                cout << "   Quantity        : " << no_of_books << endl;
                cout << "   Total Amount    : " << billAmount << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "\n\n";
                cout << "   If you want to buy press 1 or press 2";
                int op;
                cin >> op;
                if(op == 1) {
                    cout << "\n   Books buyed Successfully " << endl;
                    stock = stock - no_of_books;
                    no_of_tr = no_of_tr + 1;
                }
                else {
                    no_of_utr = no_of_utr + 1;
                }
            }

        }
};
int book::no_of_tr;
int book::no_of_utr;
int main() {
    book *bk;
    int n, choice, t_n;
    char t_title[30], t_author[30];
    float t_price, t_no_of_units;
    cout << "Enter no. of books : ";
    cin >> n;
    bk = new book[n];
    for(int i=0 ; i<n ; i++) {
        cout << "BOOK " << i+1 << " : " << endl;
        cout << "\tEnter book name   : ";
        cin >> t_title;
        cout << "\tEnter author name : ";
        cin >> t_author;
        cout << "\tEnter amount      : ";
        cin >> t_price;
        cout << "\tEnter stock units : ";
        cin >> t_no_of_units;
        bk[i].in_BookData(t_title, t_author, t_price, t_no_of_units);
        cout << "\n\n";
    }
    do {
        int cnt = 0;
        cout << "\n\n";
        cout << "Enter the following choice : \n";
        cout << "\t1. To Search or Buy Books " << endl;
        cout << "\t2. To Update Price " << endl;
        cout << "\t3. To show Details " << endl;
        cout << "\t4. To Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\t\tEnter Title  : ";
                cin >> t_title;
                cout << "\t\tEnter Author : ";
                cin >> t_author;
                for(int i=0 ; i<n ; i++) {
                    if(bk[i].checkBook(t_title, t_author)) {
                        cout << "\tDo You want to buy this book " << endl;
                        cout << "\t\t1. To Buy Now \n";
                        cout << "\t\t2. To Buy Later \n";
                        cout << "Enter choice : ";
                        cin >> choice;
                        switch(choice) {
                            case 1:
                                cout << "\t\tEnter no. of Books : ";
                                cin >> t_n;
                                bk[i].billBooks(t_n);
                                break;

                            case 2:
                                break;

                            default:
                                cout << "\t\tINVALID CHOICE !!! " << endl;
                                break;
                        }
                        break;
                    }
                    else cnt++ ;
                }
                if(cnt == n)
                    cout << "\t\tBook not found \n";
                break;

            case 2:
                cout << "\t\tEnter Title  : ";
                cin >> t_title;
                cout << "\t\tEnter Author : ";
                cin >> t_author;
                for(int i=0 ; i<n ; i++) {
                    if(bk[i].checkBook(t_title, t_author)) {
                        cout << "\tEnter new price : ";
                        cin >> t_price;
                        bk[i].updatePrice(t_price);
                        cout << "\tPrice updated succesfully " << endl;
                    }
                    else cnt++ ;
                }
                if(cnt == n) {
                    cout << "Book Not found " << endl;
                }
                break;

            case 3:
                cout << "\t\tDetails Of Transections : " << endl;
                cout << "\t\t\tNo. Of Successful transections   : " << bk->no_of_tr << endl;
                cout << "\t\t\tNo. Of Unsuccessful transections : " << bk->no_of_utr << endl;
                cout << "\n\n";
                break;

            case 4:
                break;

            default:
                cout << "\t\tInvalid Choice " << endl;
                break;
        }
    }while(choice != 4);
}
/*
OUTPUT :
Enter no. of books : 5
BOOK 1 : 
        Enter book name   : abcd
        Enter author name : efgh
        Enter amount      : 500
        Enter stock units : 100


BOOK 2 : 
        Enter book name   : hijk
        Enter author name : lmno
        Enter amount      : 400
        Enter stock units : 200


BOOK 3 : 
        Enter book name   : pqrs
        Enter author name : tuvw
        Enter amount      : 200
        Enter stock units : 100


BOOK 4 : 
        Enter book name   : xyza
        Enter author name : bcde
        Enter amount      : 100
        Enter stock units : 50


BOOK 5 : 
        Enter book name   : bcd
        Enter author name : efg
        Enter amount      : 60
        Enter stock units : 100




Enter the following choice : 
        1. To Search or Buy Books 
        2. To Update Price 
        3. To show Details 
        4. To Exit 
Enter choice : 1
                Enter Title  : abcd
                Enter Author : efgh


------------------------------------------------------------
                         BOOK INFO
------------------------------------------------------------
   Name         : abcd
   Author       : efgh
   Amount       : 500
   Availability : Available
------------------------------------------------------------


        Do You want to buy this book
                1. To Buy Now
                2. To Buy Later
Enter choice : 1
                Enter no. of Books : 50


------------------------------------------------------------
                           BILL
------------------------------------------------------------
   Name    : abcd
   Author  : efgh
------------------------------------------------------------
   amount per unit : 500
   Quantity        : 50
   Total Amount    : 25000
------------------------------------------------------------


   If you want to buy press 1 or press 21

   Books buyed Successfully


Enter the following choice :
        1. To Search or Buy Books
        2. To Update Price
        3. To show Details
        4. To Exit
Enter choice : 2
                Enter Title  : ijkl
                Enter Author : mnop
Book Not found


Enter the following choice :
        1. To Search or Buy Books
        2. To Update Price
        3. To show Details
        4. To Exit
Enter choice : 1
                Enter Title  : hijk
                Enter Author : lmno


------------------------------------------------------------
                         BOOK INFO
------------------------------------------------------------
   Name         : hijk
   Author       : lmno
   Amount       : 400
   Availability : Available
------------------------------------------------------------


        Do You want to buy this book
                1. To Buy Now
                2. To Buy Later
Enter choice : 1
                Enter no. of Books : 100


------------------------------------------------------------
                           BILL
------------------------------------------------------------
   Name    : hijk
   Author  : lmno
------------------------------------------------------------
   amount per unit : 400
   Quantity        : 100
   Total Amount    : 40000
------------------------------------------------------------


   If you want to buy press 1 or press 21

   Books buyed Successfully


Enter the following choice : 
        1. To Search or Buy Books
        2. To Update Price
        3. To show Details
        4. To Exit
Enter choice : 2
                Enter Title  : pqrs
                Enter Author : tuvw


------------------------------------------------------------
                         BOOK INFO
------------------------------------------------------------
   Name         : pqrs
   Author       : tuvw
   Amount       : 200
   Availability : Available
------------------------------------------------------------


        Enter new price : 400
        Price updated succesfully


Enter the following choice :
        1. To Search or Buy Books
        2. To Update Price
        3. To show Details
        4. To Exit
Enter choice : 3
                Details Of Transections :
                        No. Of Successful transections   : 2
                        No. Of Unsuccessful transections : 0




Enter the following choice :
        1. To Search or Buy Books
        2. To Update Price
        3. To show Details
        4. To Exit
Enter choice : 4
*/