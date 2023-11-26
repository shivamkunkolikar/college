#include<iostream>
using namespace std;
class Election
{
    private:
        int count[6];
        int no_of_voters;

    public:
        void start_voting();
        void show_results();
};
void Election::start_voting()
{
    for(int i=0 ; i<6 ; i++)
        count[i] = 0;
    int vote;
    cout << "Enter number of voters : ";
    cin >> no_of_voters;
    for(int i=0 ; i<no_of_voters ; i++)
    {
        cout << "Enter vote " << i+1 << " : ";
        cin >> vote;
        if(vote <= 0 || vote >= 6)
            count[5]++;
        else
            count[vote - 1]++;
    }
}

void Election::show_results()
{
    for(int i=0 ; i<5 ; i++)
        cout << " Candidate " << i+1 << " : " << count[i] << endl;
    cout << " Spoilet Ballot  : " << count[5] << endl;
}

int main()
{
    Election e1;
    e1.start_voting();
    e1.show_results();
    return 0;
}
/*
OUTPUT :
Enter number of voters : 30
Enter vote 1 : 1
Enter vote 2 : 2
Enter vote 3 : 1
Enter vote 4 : 1
Enter vote 5 : 2
Enter vote 6 : 3
Enter vote 7 : 2
Enter vote 8 : 2
Enter vote 9 : 2
Enter vote 10 : 5
Enter vote 11 : 6
Enter vote 12 : 2
Enter vote 13 : 3
Enter vote 14 : 4
Enter vote 15 : 6
Enter vote 16 : 8
Enter vote 17 : 2
Enter vote 18 : 2
Enter vote 19 : 1
Enter vote 20 : 2
Enter vote 21 : 2
Enter vote 22 : 2
Enter vote 23 : 3
Enter vote 24 : 5
Enter vote 25 : 5
Enter vote 26 : 3
Enter vote 27 : 2
Enter vote 28 : 1
Enter vote 29 : 2
Enter vote 30 : 2
 Candidate 1 : 5
 Candidate 2 : 14
 Candidate 3 : 4
 Candidate 4 : 1
 Candidate 5 : 3
 Spoilet Ballot  : 3
*/
