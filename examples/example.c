#include <stdio.h>

#include "HashTable.h"


int hash_function(void *key);
int key_compare(void *key1, void *key2);


int main(int argc, char const *argv[])
{
	int keys[10] = {1,2,3,4,5,6,7,8,9,10};
	int values[10] = {32,12,54,23,87,23,123,54,76,-23};

	HashTable *table = HashTable_new(10, hash_function, key_compare);

	for (int i = 0; i < 10; ++i)
	{
		HashTable_add(table, &keys[i], &values[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		int value = *(int *)HashTable_get(table, &keys[i]);
		printf("[%d]\t%d\n", keys[i], value);
	}

	return 0;
}


int hash_function(void *key){
	return 7 + 11* (*(int *)(key));
}

int key_compare(void *key1, void *key2){
	return *(int *)(key1) - *(int *)(key2);
}
