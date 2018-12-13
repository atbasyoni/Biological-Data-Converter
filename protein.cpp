#include "protein.h"
#include <iostream>
#include <string>
#include <cstring>
#include "sequence.h"
#include "rna.h"
#include "dna.h"

using namespace std;

/// Protein Default constructor
Protein::Protein()
{
    //ctor
}

/// Protein constructor to store sequence and DNA type
Protein::Protein(char * p, Protein_Type _type)
{
    seq = new char;
    seq = p;
    type = _type;
}

/// Protein destructor
Protein::~Protein()
{
    //ctor
}

/// Protein constructor to make a copy of Protein sequence
Protein::Protein(Protein& rhs)
{
    type = rhs.type;
    seq = new char;
    seq = rhs.seq;
}
/// function to print Protein sequence information to user
void Protein::Print()
{
    cout << "The Protein Data = ";
    cout << seq << endl;
    cout << endl;
}

/// return an array of DNA sequences that can possibly
/// generate that protein sequence
DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{

}
