#ifndef TINFO
#define TINFO

#include <stdbool.h>

typedef int TValue;
typedef int TKey;
typedef struct STinfo
{
    TKey key;
    TValue value;
} TInfo;


bool info_greater(TInfo l, TInfo r);
bool info_lesser(TInfo l, TInfo r);
bool info_equal(TInfo l, TInfo r);
void info_print(TInfo info);
void info_copy(TInfo* l, TInfo* r);
void info_swap(TInfo* l,TInfo* r);
//unsigned hash_function(TKey key, int bucket_num)
unsigned hash_function_one(TKey a);
unsigned hash_function_two(TKey a);
//unsigned hash_function_three(TKey a);

#endif