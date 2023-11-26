#include<iostream>
using namespace std;
int accTemp = 10000;
class userAccount
{
    private:
        int accNum;
        char name[50];
        float balance;
        int no_of_withdraws;
        int no_of_deposits;
        int no_of_transections;
        bool transfer(userAccount &reciver, float amount)
        {
            if((balance - amount) > 500)
            {
                balance = balance - amount;
                reciver.balance = reciver.balance + amount;
                reciver.no_of_deposits++;
                reciver.no_of_transections++;
                return true;
            }
            else
                return false;
        }

    public:
        void set_acnum(int acnum)
        {
            accNum = acnum;
        }
        int get_acnum()
        {
            return accNum;
        }
        void set_user_account();
        void deposit_money();
        void withdraw_money();
        void check_balance();
        void transferBalance(userAccount user[], int num);
};

void userAccount::set_user_account()
{
    cout << "\t\tEnter User Name          : ";
    cin >> name;
    accNum = ++accTemp;
    cout << "\t\tEnter starting balance   : ";
    cin >> balance;
    no_of_deposits = 1;
    no_of_withdraws = 0;
    no_of_transections = no_of_deposits + no_of_withdraws;
    cout << "\t\tAccount number generated : " << accNum << endl;
    cout << "\n\n";
}

void userAccount::deposit_money()
{
    float tmpDeposit;
    cout << "\n\t\tName         : " << name << endl;
    cout << "\t\tEnter amount : ";
    cin >> tmpDeposit;
    balance = balance + tmpDeposit;
    cout << "\t\tAmount dposited successfully !!\n";
    cout << "\t\tNew Balance  : " << balance << endl;
    no_of_deposits++;
    no_of_transections++;
    cout << "       Transactions : " << no_of_transections << endl;
    cout << "           Deposits : " << no_of_deposits << endl;
    cout << "        Withdrawals : " << no_of_withdraws << endl;
}

void userAccount::withdraw_money()
{
    float tmpWith;
    cout << "\n\t\tName         : " << name << endl;
    cout << "\t\tEnter amount : ";
    cin >> tmpWith;
    if((balance - tmpWith) < 500)
    {
        cout << "\t\tAmount Cannot Be Withdrawn \n";
        cout << "\t\tSince it violates minimum balance requirement \n";
        return;
    }
    balance = balance - tmpWith;
    cout << "\t\tAmount withdrawn successfully !!\n";
    cout << "\t\tNew Balance  : " << balance << endl;
    no_of_withdraws++;
    no_of_transections++;
    cout << "       Transactions : " << no_of_transections << endl;
    cout << "           Deposits : " << no_of_deposits << endl;
    cout << "        Withdrawals : " << no_of_withdraws << endl;
}

void userAccount::check_balance()
{
    int tmpAccnum, i;
    cout << "\n            Name    : " << name << endl;
    cout << "            Balance : " << balance << endl;
    cout << "       Transactions : " << no_of_transections << endl;
    cout << "           Deposits : " << no_of_deposits << endl;
    cout << "        Withdrawals : " << no_of_withdraws << endl;
}

void userAccount::transferBalance(userAccount user[], int num)
{
    int accnum, i;
    float amount;
    cout << "\t\tName     : " << name << endl;
    cout << "\t\tBalanace : " << balance << endl;
    cout << "\t\tEnter Account number : ";
    cin >> accnum;
    for(i=0 ; i<num ; i++)
    {
        if(accnum == user[i].get_acnum())
            break;
    }
    if(i == num)
    {
        cout << "\t\tAccount Not Found \n";
        return;
    }
    cout << "\t\tReciever Name : " << user[i].name  << endl;
    cout << "\t\tEnter Amount  : ";
    cin >> amount;
    if(transfer(user[i], amount))
    {
        cout << "\t\tTransection Successfull !!! \n";
        cout << "\t\tCurrent Balance : " << balance << endl;
        no_of_withdraws++;
        no_of_transections++;
        return;
    }
    else
    {
        cout << "\t\tTransection Unsuccessful !!! \n";
        return;
    }
}

int main()
{
    int num, code, tmpAcc, j;
    cout << "Enter number of customers : ";
    cin >> num;
    userAccount *user = new userAccount[num];
    for(int i=0 ; i<num ; i++)
    {
        cout << "User " << i+1 << " : \n";
        user[i].set_user_account();
    }

    while(1)
    {
        cout << "\n\n\n";
        cout << "Enter the following code : \n";
        cout << "   1. Deposit          " << endl;
        cout << "   2. Withdrw          " << endl;
        cout << "   3. Check Balance    " << endl;
        cout << "   4. Transfer Balance " << endl;
        cout << "   5. Exit             " << endl;
        cout << "Enter code : ";
        cin >> code;

        switch(code)
        {
            case 1:
                cout << "\tEnter Account Number : ";
                cin >> tmpAcc;
                for(j=0 ; j<num ; j++)
                {
                    if(user[j].get_acnum() == tmpAcc)
                        break;
                }
                if(j == num)
                {
                    cout << "\tAccount Not Found \n";
                    break;
                }
                user[j].deposit_money();
                break;

            case 2:
                cout << "\tEnter Account Number : ";
                cin >> tmpAcc;
                for(j=0 ; j<num ; j++)
                {
                    if(user[j].get_acnum() == tmpAcc)
                        break;
                }
                if(j == num)
                {
                    cout << "\tAccount Not Found \n";
                    break;
                }
                user[j].withdraw_money();
                break;

            case 3:
                cout << "\tEnter Account Number : ";
                cin >> tmpAcc;
                for(j=0 ; j<num ; j++)
                {
                    if(user[j].get_acnum() == tmpAcc)
                        break;
                }
                if(j == num)
                {
                    cout << "\tAccount Not Found \n";
                    break;
                }
                user[j].check_balance();
                break;

            case 4:
                cout << "\tEnter Account Number : ";
                cin >> tmpAcc;
                for(j=0 ; j<num ; j++)
                {
                    if(user[j].get_acnum() == tmpAcc)
                        break;
                }
                if(j == num)
                {
                    cout << "\tAccount Not Found \n";
                    break;
                }
                user[j].transferBalance(user, num);
                break;

            case 5:
                exit(1);
                break;

            default:
                cout << "INVALID OPTION !!!" << endl;
                break;
        }
    }
    return 0;
}
/*
OUTPUT :
Enter number of customers : 4
User 1 : 
                Enter User Name          : abcd
                Enter starting balance   : 1000
                Account number generated : 10001


User 2 : 
                Enter User Name          : efghi
                Enter starting balance   : 2000
                Account number generated : 10002


User 3 : 
                Enter User Name          : jklmn
                Enter starting balance   : 3000
                Account number generated : 10003


User 4 : 
                Enter User Name          : opqrst
                Enter starting balance   : 4000
                Account number generated : 10004





Enter the following code : 
   1. Deposit
   2. Withdrw
   3. Check Balance    
   4. Transfer Balance 
   5. Exit
Enter code : 1
        Enter Account Number : 10001

                Name         : abcd
                Enter amount : 500
                Amount dposited successfully !!
                New Balance  : 1500
       Transactions : 2
           Deposits : 2
        Withdrawals : 0



Enter the following code :
   1. Deposit
   2. Withdrw
   3. Check Balance
   4. Transfer Balance
   5. Exit
Enter code : 2
        Enter Account Number : 10002

                Name         : efghi
                Enter amount : 500
                Amount withdrawn successfully !!
                New Balance  : 1500
       Transactions : 2
           Deposits : 1
        Withdrawals : 1



Enter the following code :
   1. Deposit
   2. Withdrw
   3. Check Balance
   4. Transfer Balance
   5. Exit
Enter code : 3
        Enter Account Number : 10003

            Name    : jklmn
            Balance : 3000
       Transactions : 1
           Deposits : 1
        Withdrawals : 0



Enter the following code :
   1. Deposit
   2. Withdrw
   3. Check Balance
   4. Transfer Balance
   5. Exit
Enter code : 4
        Enter Account Number : 10004
                Name     : opqrst
                Balanace : 4000
                Enter Account number : 10001
                Reciever Name : abcd
                Enter Amount  : 1000
                Transection Successfull !!!
                Current Balance : 3000



Enter the following code :
   1. Deposit
   2. Withdrw
   3. Check Balance
   4. Transfer Balance
   5. Exit
Enter code : 3
        Enter Account Number : 10001

            Name    : abcd
            Balance : 2500
       Transactions : 3
           Deposits : 3
        Withdrawals : 0



Enter the following code :
   1. Deposit
   2. Withdrw
   3. Check Balance
   4. Transfer Balance
   5. Exit
Enter code : 5
*/