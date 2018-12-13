#include <iostream>
#include <string>
#include <cstring>
#include "rna.h"
#include "sequence.h"
#include "dna.h"
#include "protein.h"
#include "codonstable.h"

using namespace std;

class Protein;

RNA::RNA()
{

}

RNA::RNA(char* _seq, RNA_Type _type)
{
    seq = new char;
    seq = _seq;
    type = _type;
}

RNA::RNA(RNA& rhs)
{
    type = rhs.type;
    seq = new char;
    seq = rhs.seq;
}

RNA::~RNA()
{
    delete seq;
}

void RNA::Print()
{
    cout << "The RNA Strand = ";

    for (unsigned int i = 0 ; i < strlen(seq) ; i++)
    {
        cout << seq[i] << " ";
    }

    cout << endl;

    cout << "RNA Type = " ;

    switch(type){
case 0:
    cout<<"mRNA"<<endl;
    break;
case 1:
    cout<<"pre_mRNA"<<endl;
    break;
case 2:
    cout<<"mRNA_exon"<<endl;
    break;
case 3:
    cout<<"mRNA_intron"<<endl;
    break;
    }

    cout << endl;
}

DNA RNA::ConvertToDNA()
{
    int siz = strlen(seq);

    char* convrt;
    convrt = new char;

    for (int i = 0 ; i < siz ; i++)
    {
        if (seq[i] == 'U')
        {
            convrt[i] = 'T';
        }
        else
        {
            convrt[i] = seq[i];
        }
    }

    convrt[siz] = '\0';

    DNA result (convrt, motif);

    return result;
}

Protein RNA::ConvertToProtein(CodonsTable table)
{
    char* value;
    value = new char [4];

    int siz = strlen(seq) / 3;

    char* result;
    result = new char[siz + 1];

    Codon res;

    for (int i = 0 , k = 0 ; i < siz ; i+=3 , k++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            value[j] = seq[j+i];
        }

        res = table.getAminoAcid(value);
        result[k] = res.AminoAcid;
    }
    result[siz] = '\0';

    cout << result << endl;

    Protein P(result, Cellular_Function);

    return P;
}

