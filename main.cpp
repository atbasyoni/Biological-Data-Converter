#include <iostream>
#include <string>
#include <cstring>
#include "sequence.h"
#include "rna.h"
#include "dna.h"
#include "codonstable.h"

using namespace std;

/*char menu ()
{
    Sequence* D1;
    D1 = new DNA;

    Sequence* D2;
    D2 = new DNA;

    Sequence* D3;
    D3 = new DNA;

    Sequence* R1;
    R1 = new RNA;

    Sequence* R2;
    R2 = new RNA;

    Sequence* R3;
    R3 = new RNA;

    while (true)
    {
        char option;

        cout << "Welcome to our program :)" << endl;
        cout << "1 - cin >> DNA" << endl;
        cout << "2 - cout << DNA" << endl;
        cout << "3 - Build Complementary Strand Of DNA" << endl;
        cout << "4 - Convert DNA to RNA" << endl;
        cout << "5 - Print DNA" << endl;
        cout << "6 - DNA 1 == DNA 2" << endl;
        cout << "7 - DNA 1 != DNA 2" << endl;
        cout << "8 - DNA 1 + DNA 2" << endl;
        cout << "9 - cin >> RNA" << endl;
        cout << "10 - cout << RNA" << endl;
        cout << "11 - Convert RNA to DNA" << endl;
        cout << "12 - Convert RNA to Protein" << endl;
        cout << "13 - Print RNA" << endl;
        cout << "14 - RNA 1 == RNA 2" << endl;
        cout << "15 - RNA 1 != RNA 2" << endl;
        cout << "16 - RNA 1 + RNA 2" << endl;
        cout << "17 - GetDNAStrandsEncodingMe" << endl;

        switch(option)
        {
        case '1':
            cout << "Enter The Sequence of DNA : ";
            cin >> D1;
            break;
        case '2':
            cout << "The Sequence of DNA : ";

            for (int i = 0 ; i < strlen(D1) ; i++)
            {
                cout << D1->seq[i] << " ";
            }
            break;
        case '3':
            ((DNA*)D1)->BuildComplementaryStrand();
            break;
        case '4':
            break;
        case '5':
            ((DNA*)D1)->print();
            break;
        case '6':
            if (D1 == D2)
            {
                cout << "The Sequence of first DNA = The Sequence of second DNA" << endl;
            }
            else
            {
                cout << "The Sequence of first DNA != The Sequence of second DNA" << endl;
            }
            break;
        case '7':
            if (D1 != D2)
            {
                cout << "The Sequence of first DNA != The Sequence of second DNA" << endl;
            }
            else
            {
                cout << "The Sequence of first DNA = The Sequence of second DNA" << endl;
            }
            break;
        case '8':
            D3 = D1 + D2;
            cout << D3 << endl;
            break;
        case '9':
        case '10':
        case '11':
        case '12':
        case '13':
        case '14':
        case '15':
        case '16':
        case '17':
        case '18':

        }
    }
}
*/

int main()
{

    char* seq ("ACCTAC");
    char* seq2 ("ACGUACGUA");

    Sequence * D1 = new DNA(seq, noncoding);
    Sequence * D2;

    Sequence * R1 = new RNA(seq2, mRNA);
    Sequence * R2;
/*
    ((DNA*)D1)->BuildComplementaryStrand();
    ((DNA*)D1)->Print();

    D2 = ((DNA*)D1)->ConvertToRNA();
    ((DNA*)D2)->Print();

    ((RNA*)R1)->Print();
    R2 = ((RNA*)R1)->ConvertToDNA();
    ((DNA*)R2)->BuildComplementaryStrand();
    ((DNA*)R2)->Print();



*/
    CodonsTable T;
    T.LoadCodonsFromFile("ASA.txt");

    Sequence * P1 = new Protein;
    Sequence * P2;

    P2 = ((RNA*)R1)->ConvertToProtein(T);


/*
    Protein P;
    P = R.ConvertToProtein(T);
    P.Print();


    Sequence* s;
    s = new DNA();

    cin >> s;
    cout << s;
*/
    return 0;
}
