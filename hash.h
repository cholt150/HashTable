/*  hash.h
 */

#ifndef HASH_H
#define HASH_H

struct nList     /*  table entry:  */
{
   char *name;          /*  defined name         */
   struct nList *next;  /*  next entry in chain  */
};
typedef struct nList *NListPtr;

const int HASH_TABLE_SIZE = 49937;

unsigned Hash( const char *s );
NListPtr Lookup( const char *s );
NListPtr Insert( const char *name);

void PrintHashTable();
void buckets();
void search(const char* s);

#endif  /*  HASH_H  */
