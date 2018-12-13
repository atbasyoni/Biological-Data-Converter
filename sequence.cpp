#include "sequence.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/// Sequence Default constructor
Sequence::Sequence()
{
    //ctor
}

/// Sequence destructor
Sequence::~Sequence()
{
    //ctir
}

/// Sequence constructor
Sequence::Sequence(int length)
{
    //ctor
}

/// Sequence constructor to make a copy of Sequence sequence
Sequence::Sequence(Sequence& rhs)
{
    seq = rhs.seq;
}

/// pure virtual function that should be overridden because every
/// type of sequence has its own details to be printed
void Sequence::Print()
{
    //ctor
}

/// friend function that will find the LCS (longest common
/// subsequence) between 2 sequences of any type, according to
/// polymorphism
/*char* Sequence::Align(Sequence * s1, Sequence * s2)
{
    int result;
    int siz1 = strlen(s1->seq) + 1 , siz2 = strlen(s2->seq) + 1;
    result = new int[siz1][siz2];

    for (int i = 0 ; i < siz1 ; i++)
    {
        for (int j = 0 ; j < siz2 ; j++)
        {
            if (i == 0 || j == 0)
            {
                result[i][j] = 0;
            }
            else if (s1->seq[i-1] == s2->seq[j-1])
            {
                result [i][j] = result [i-1][j-1] + 1;
            }
            else
            {
                result [i][j] = max(result[i-1][j], result[i][j-1]);
            }
        }
    }
}
*/


istream& operator >> (istream& in , Sequence* s)
{
    int length;

    cout << "Enter Sequence Length : ";
    cin >> length;

    s->seq = new char [length + 1];

    cout << "Enter The Sequence : " << endl;

    for (int i = 0 ; i < length ; i++)
    {
        in >> s->seq[i];
    }

    return in;
}

ostream& operator <<(ostream& out , Sequence* s)
{
    int length;

    cout << "Enter Sequence Length : ";
    cin >> length;

    s->seq = new char [length + 1];

    cout << "Enter The Sequence : " << endl;

    for (int i = 0 ; i < length ; i++)
    {
        out << s->seq[i] << " ";
    }

    return out;
}

/*Sequence operator == (Sequence* s)
{
    return;
}*/
