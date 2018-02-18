#include <stdlib.h>
#include <string.h>

#include "HashTable.h"


/////////////////////
// Data Structures //
/////////////////////

typedef struct Node Node;
struct Node{
	void *key;
	void *value;
	Node *next;
};

typedef struct HashTable{
	int size;
	Node **table;

	int (*hash_function)(void *);
	int (*key_compare)(void *, void *);
} HashTable;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

HashTable *HashTable_new(int size, int (*hash_function)(void *), int (*key_compare)(void *, void *)){
	HashTable *htable_ptr = malloc(sizeof(HashTable));

	htable_ptr->size = size;
	htable_ptr->table = malloc(size*sizeof(Node *));
	memset(htable_ptr->table, 0, size*sizeof(Node *));
	htable_ptr->hash_function = hash_function;
	htable_ptr->key_compare = key_compare;

	return htable_ptr;
}

void *HashTable_destroy(HashTable *htable_ptr){

	Node *node_cur, *node_next;

	for (int i = 0; i < htable_ptr->size; ++i)
	{
		node_cur = htable_ptr->table[i];

		while(node_cur != NULL)
		{
			node_next = node_cur->next;
			free(node_cur);
			node_cur = node_next;
		}
	}

	free(htable_ptr->table);
	free(htable_ptr);
}


////////////////
// Manipulate //
////////////////

void HashTable_add(HashTable *htable_ptr, void *key, void *value){
	Node *new = malloc(sizeof(Node));

	new->key = key;
	new->value = value;

	int index = htable_ptr->hash_function(key) % htable_ptr->size;

	new->next = htable_ptr->table[index];
	htable_ptr->table[index] = new;
}

void *HashTable_get(HashTable *htable_ptr, void *key){
	int hash = htable_ptr->hash_function(key);

	// Ensure hash is positive
	if(hash<0)	hash *= -1;
	int index = hash % htable_ptr->size;

	Node *node = htable_ptr->table[index];

	while(1)
	{
		if(node == NULL)
			return NULL;
		else if(htable_ptr->key_compare(key, node->key) == 0)
			return node->value;
		else
			node = node->next;
	}
}

void HashTable_set(HashTable *htable_ptr, void *key, void *value){
	int index = htable_ptr->hash_function(key) % htable_ptr->size;

	Node *node = htable_ptr->table[index];

	while(1)
	{
		if(node == NULL)
			return;
		else if(htable_ptr->key_compare(key, node->key) == 0){
			node->value = value;
			return;
		}
		else
			node = node->next;
	}	
}
