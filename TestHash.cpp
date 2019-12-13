/* TestHash.cpp
 *   Test the Hash table code.
 *   Modified By Cory Holt, Nov. 2019
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "hash.h"
using namespace std;

int main()
{  
	string filename;
	ifstream fIn; //Create a new filestream
	cout << "Running Dictionary Hash Table.\nTable Size is " << HASH_TABLE_SIZE << "." << endl;
	//cout << "Enter the dictionary to use:" << endl;
	//getline(cin, filename);
	fIn.open("dict4.txt"); // Uncomment above lines and change dict4.txt to filename if we want user input.

	char word[46]; //Longest word in any dictionary is 45 letters long

	while (!fIn.eof()) {
		fIn >> word;
		(void)Insert(word);
	}

	buckets();

	search("absciss");
	search("parallelepipedic");
	search("essence");
	search("maple");
	search("ouabain");
	search("purlin");
	search("soundless");
	search("spaniel");
	search("Tyrannosaurus");
	search("zootoxin");
         
   return EXIT_SUCCESS;
}
 