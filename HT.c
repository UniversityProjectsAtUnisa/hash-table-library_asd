#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "HT.h"

THashtable *hashtable_create(int bucket_num)
{
    THashtable *ht = (THashtable *)malloc(sizeof(THashtable));
    assert(ht != NULL);
    ht->bucket = (TList *)malloc(sizeof(TList) * bucket_num);
    assert(ht->bucket != NULL);
    ht->bucket_num=bucket_num;

    for (int i = 0; i < bucket_num; i++)
    {
        ht->bucket[i] = list_create();
    }
    return ht;
}

void hashtable_destroy(THashtable *ht)
{
    for (int i = 0; i < ht->bucket_num; i++)
    {
        list_destroy(ht->bucket[i]);
    }
    free(ht->bucket);
    ht->bucket_num = 0;
    free(ht);
}

TValue *hashtable_search(THashtable *ht, TKey key)
{ //TInfo incompatibili tra Lista e Hash
    unsigned index = hash_function_one(key) % ht->bucket_num;
    //Creo un TInfo temporaneo per la ricerca
    TInfo temp;
    temp.key = key;
    TNode *n = list_search(ht->bucket[index], temp);
    if (n != NULL)
        return &(n->info.value);
    else
        return NULL;
}

void hashtable_print(THashtable *ht)
{
    for (int i = 0; i < ht->bucket_num; i++)
    {
        printf("bucket #%d: ", i);
        list_visit(ht->bucket[i]);
        puts("");
    }
}

void hashtable_insert(THashtable *ht, TKey key, TValue value)
{
    unsigned index = hash_function_one(key) % ht->bucket_num;
    TInfo temp = {key, value};
    TNode *node = list_search(ht->bucket[index], temp);
    if (node != NULL)
        node->info.value = value;
    else
        ht->bucket[index] = list_insert(ht->bucket[index], temp);
}

void hashtable_delete(THashtable *ht, TKey key)
{ //TInfo incompatibili tra Lista e Hash
    unsigned index = hash_function_one(key) % ht->bucket_num;
    TInfo temp;
    temp.key = key;
    ht->bucket[index] = list_delete_node(ht->bucket[index], temp);
}