#ifndef PROTEIN_H
#define PROTEIN_H
#include <iostream>
#include <string>
#include <cstring>
#include "sequence.h"
#include "rna.h"
#include "dna.h"

using namespace std;

class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
    public:
        // constructors and destructor
 	 	Protein();
 	 	Protein(char * p, Protein_Type _type);
 	 	~Protein();
 	 	Protein(Protein& rhs);
 	 	void Print();
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);

    private:
        Protein_Type type;
};

#endif // PROTEIN_H
