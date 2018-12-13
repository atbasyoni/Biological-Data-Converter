#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <string>
#include <cstring>
#include "sequence.h"
#include "rna.h"

using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
    public:
        // constructors and destructor
        DNA();
        ~DNA();
        DNA(char * seq, DNA_Type type);
        DNA(DNA& rhs);
 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();

    private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
};

#endif // DNA_H
