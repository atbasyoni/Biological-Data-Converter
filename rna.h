#ifndef RNA_H
#define RNA_H
#include <iostream>
#include <string>
#include <cstring>
#include "sequence.h"
#include "dna.h"
#include "protein.h"
#include "codonstable.h"

using namespace std;

class DNA;
class Protein;
class CodonsTable;


enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
    public:
        // constructors and destructor
        RNA();
        RNA(char * _seq, RNA_Type _type);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();

    private:
        RNA_Type type;
};

#endif // RNA_H
