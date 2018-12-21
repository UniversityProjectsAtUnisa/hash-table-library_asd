#ifndef HT_H
#define HT_H

#include "stdbool.h"
#include "TInfo_ht.h"
#include "list.h"

typedef struct S_HashTable
{
    TList* bucket;
    int bucket_num;
}THashtable;

THashtable* hashtable_create(int bucket_num);
TValue* hashtable_search(THashtable* ht,TKey key);
void hashtable_insert(THashtable* ht,TKey key,TValue value);
void hashtable_print(THashtable* ht);
void hashtable_destroy(THashtable* ht);
void hashtable_delete(THashtable* ht,TKey k);





#endif