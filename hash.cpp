/* Hash.cpp
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *     Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "hash.h"



static NListPtr hashTable[HASH_TABLE_SIZE];
int sizeArr[HASH_TABLE_SIZE]; //Array to hold Bucket sizes

    //  Prototypes
static char *Strdup( const char * );  //  in cstring, but....



/*  Hash
 *  Generate hash value for string s
 */

unsigned Hash( const char *s )
{
    unsigned hashVal;
    
    for( hashVal = 0 ; *s != '\0' ; s++ )
        hashVal = *s + 31 * hashVal;
        
    return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
 *  Look for s in hashTable
 */

NListPtr Lookup( const char *s )
{
    NListPtr np;
    
    for( np = hashTable[Hash(s)] ; np != NULL ; np = np->next )
    {
        if( strcmp(s, np->name) == 0 )
            return np;    //  found
    }
    
    return NULL;          //  not found
}

/*  Insert
 *  Put (name, defn) in hash table
 */
 
NListPtr Insert( const char *name)
{
    unsigned hashVal;
    NListPtr np;
    
    if( (np = Lookup(name)) == NULL )  // not found
    {
        np = (NListPtr) malloc(sizeof(*np));
        if( np == NULL || (np->name = Strdup(name)) == NULL )
            return NULL;
        hashVal = Hash(name);
        np->next = hashTable[hashVal];
        hashTable[hashVal] = np;
		sizeArr[hashVal]++;
    }
    else
    {      //  remove previous definition
        //free( (void *)np->defn );
    }
    
    //if( (np->defn = Strdup(defn)) == NULL )
    //    return NULL;
    
    return np;
}


/*  PrintHashTable
 *  Print the hash table contents
 */

void PrintHashTable()
{
    NListPtr np;

    cout << "Hash table contents:" << endl;
    cout << "--------------------\n" << endl;

    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
    {
        np = hashTable[i];
        while( np != NULL )
        {
             cout << setw(3) << i << ":    ";
             cout << np->name;
             cout << endl;
             np = np->next;
        }
    }
}


/*  Strdup
 *  Make a duplicate copy of s
 */

static char *Strdup( const char *s )
{
    char *p;
	
    p = (char *) malloc(strlen(s)+1);  /*  +1 for '\0'  */
    if( p != NULL )
        strcpy_s(p, strlen(s) + 1,s); //Compiler did not like old strcpy, So I used this func.

    return p;
}

void buckets() {
	int max, min, empty = 0;
	max = min = sizeArr[0]; //Sample array for min,max
	cout << "Bucket Analysis:" << endl;
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (sizeArr[i] == 0)
			empty++;
		if (sizeArr[i] < min)
			min = sizeArr[i];
		if (sizeArr[i] > max)
			max = sizeArr[i];
	}
	cout << "Minimum bucket size: " << min << endl;
	cout << "Maximum bucket size: " << max << endl;
	cout << "Number of empty buckets: " << empty << endl << endl;
}

void search(const char* s) {
	NListPtr np;
	int count = 0;
	for (np = hashTable[Hash(s)]; np != NULL; np = np->next)
	{	
		count++;
		if (strcmp(s, np->name) == 0)
			cout << "Word \"" << s << "\" found in " << count << " probes." << endl;
	}
}
