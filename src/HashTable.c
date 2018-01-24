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
	Node *table;

	int (*hash_function)(void *);
	int (*key_compare)(void *, void *);
} HashTable;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

HashTable *HashTable_new(int size, int (*hash_function)(void *), int (*key_compare)(void *, void *));{

}

void *HashTable_destroy(HashTable *htable_ptr){

}


////////////////
// Manipulate //
////////////////

void HashTable_add(HashTable *htable_ptr, void *key, void *value){

}

void *HashTable_find(HashTable *htable_ptr, void *key){

}


#endif
