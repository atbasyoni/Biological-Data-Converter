#include "codonstable.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "sequence.h"
#include "rna.h"
#include "dna.h"

using namespace std;

/// CodonsTable Default constructor
CodonsTable::CodonsTable()
{
    //ctor
}

/// CodonsTable destructor
CodonsTable::~CodonsTable()
{
    //ctor
}

/// function to load all codons from the given text file
void CodonsTable :: LoadCodonsFromFile(string codonsFileName)
{
    fstream fin;

    fin.open(codonsFileName, ios::in);

    if (!fin)
    {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }
    else
    {
        cout << "File Opened" << endl;

        int i = 0 ;

        while (!fin.eof())
        {
            fin >> codons[i].value;
            fin >> codons[i++].AminoAcid;
        }

        for(int j = 0; j < 64 ; j++)
        {
            for(int k = 0 ; k < 4 ; k++)
            {
                cout << codons[j].value[k];
            }
            cout << " " << codons[j].AminoAcid << endl;
        }
    }

    fin.close();
}

/// function to get AminoAcid from the given text file
char CodonsTable::getAminoAcid(char * value)
{
    value = new char;

    for (int m = 0 ; m < 64 ; m++)
    {
        int cont = 0;
        for (int n = 0 ; n < 3 ; n++)
        {
            if(value[n] == codons[m].value[n])
            {
                cont++;
            }
            if (cont == 3)
            {
                return codons[m].AminoAcid;
            }
        }
    }
}

/// function to store value , AminoAcid & index
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        resCodon.value[i] = value[i];
    }
    resCodon.AminoAcid = AminoAcid;
}
