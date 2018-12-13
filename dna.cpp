#include <iostream>
#include <string>
#include <cstring>
#include "dna.h"
#include "sequence.h"
#include "rna.h"

using namespace std;

DNA::DNA()
{

}

DNA::DNA(char* seq, DNA_Type type)
{
    this -> seq = seq;
    this -> type = type;

}

DNA::DNA(DNA& rhs)
{
    type = rhs.type;
    seq = new char;
    seq = rhs.seq;
}
DNA::~DNA()
{
    delete seq;
}
void DNA::Print()
{
    startIndex = 0;
    endIndex = strlen(seq);

    cout << "The First DNA Strand = ";
    for (int i = 0 ; i < endIndex ; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;

    cout << "The Second DNA Strand = ";
    for (int j = endIndex - 1 ; j >= startIndex ; j--)
    {
        cout << complementary_strand->seq[j] << " ";
    }
    cout << endl;

    cout << "DNA Type = " ;
    switch(type)
    {
    case 0:
        cout<<"promoter"<<endl;
        break;
    case 1:
        cout<<"motif"<<endl;
        break;
    case 2:
        cout<<"tail"<<endl;
        break;
    case 3:
        cout<<"noncoding"<<endl;
        break;
    }

    cout << endl;
}

void DNA::BuildComplementaryStrand()
{
    startIndex = 0;
    endIndex = strlen(seq);

    complementary_strand = new DNA;
    complementary_strand->seq = new char [strlen(seq)];

    for (int i = 0 ; i < endIndex ; i++)
    {
        switch (seq[i])
        {
        case 'A':
            complementary_strand->seq[i] = 'T';
            break;
        case 'T':
            complementary_strand->seq[i] = 'A';
            break;
        case 'G':
            complementary_strand->seq[i] = 'C';
            break;
        case 'C':
            complementary_strand->seq[i] = 'G';
            break;
        }
    }
}

RNA DNA::ConvertToRNA()
{
    int siz = strlen(seq);

    char* convrt;
    convrt = new char;

    for (int i = 0 ; i < siz ; i++)
    {
        if (seq[i] == 'T')
        {
            convrt[i] = 'U';
        }
        else
        {
            convrt[i] = seq[i];
        }
    }
    convrt[siz] = '\0';

    RNA result (convrt, mRNA);

    return result;
}
