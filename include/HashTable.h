#ifndef INCLUDE_GUARD_A96B1493BC2D4A459F9C3D86DCEFDCEA
#define INCLUDE_GUARD_A96B1493BC2D4A459F9C3D86DCEFDCEA


/////////////////////
// Data Structures //
/////////////////////

typedef struct HashTable HashTable;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

HashTable *HashTable_new(int size, int (*hash_function)(void *));

void *HashTable_destroy(HashTable *htable);


////////////////
// Manipulate //
////////////////

void HashTable_add(HashTable *htable, void *key, void *value);

void *HashTable_find(HashTable *htable, void *key);


#endif
