#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TInfo_ht.h"

bool info_greater(TInfo l, TInfo r) {
    return l.key>r.key;
}

bool info_equal(TInfo l, TInfo r) {
    return l.key==r.key;
}

bool info_less(TInfo l, TInfo r) {
    return l.key<r.key;
}

void info_print(TInfo info) {
    printf("%d,%d  ", info.key, info.value);
}

void info_copy(TInfo *l, TInfo *r) {
    l->key=r->key;
    l->value=r->value;
}

void info_swap(TInfo* l, TInfo* r) {
	TInfo temp;
	info_copy(&temp,l);
	info_copy(l, r);
	info_copy(r, &temp);
}
/*
unsigned hash_function(TKey key, int bucket_num)
{							//chiave alfanumerica @Giandomenico
							//vale solo se TKey è alias di char*
    int sum=0;
	int len=strlen(key);
    for(int i=0;i<len;i++)
    {
        sum+=info[i];
    }
    return (unsigned)(sum*17)%bucket_num;
}*/

unsigned hash_function_one(TKey a)
{                           //Vale per chiavi intere generiche
    return (unsigned) a;	//La divisione per ht->bucket_num è prevista nel main.
}

unsigned hash_function_two(TKey a)
{                           //Vale solo per chiavi intere tutte pari
    return (unsigned) a/2;	//La divisione per ht->bucket_num è prevista nel main.
}

/*unsigned hash_function_three(TKey a)
{                           //chiave alfanumerica @Fabio
							//vale solo se TKey è alias di char*
    unsigned h=0;
    for(int i=0;k[i]!='\0';i++)
        h=h+k[i];
    return h;
}*/