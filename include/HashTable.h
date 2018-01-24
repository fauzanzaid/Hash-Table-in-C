#ifndef INCLUDE_GUARD_A96B1493BC2D4A459F9C3D86DCEFDCEA
#define INCLUDE_GUARD_A96B1493BC2D4A459F9C3D86DCEFDCEA


/////////////////////
// Data Structures //
/////////////////////

/**
 * Opaque HashTable struct
 */
typedef struct HashTable HashTable;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

/**
 * Allocates space for and initializes a HashTable struct and returns a pointer
 * to it
 * @param  size          Fixed size for the hash table
 * @param  hash_function Pointer to a hash function that returns the hash for
 * the key whose pointer is passed as an argument
 * @param  key_compare   Pointer to a function that returns a 0 if both the keys
 * referenced by the passed pointers are equal
 * @return Pointer to a new HashTable struct
 */
HashTable *HashTable_new(int size, int (*hash_function)(void *), int (*key_compare)(void *, void *));

/**
 * Deallocate all internally allocated memory
 * @param  htable_ptr Pointer to a HashTable struct
 */
void *HashTable_destroy(HashTable *htable_ptr);


////////////////
// Manipulate //
////////////////

/**
 * Adds element into the hashtable
 * @param htable_ptr Pointer to HashTable struct
 * @param key        Pointer to the key which will be used for indexing
 * @param value      Pointer which will be stored at the key's index
 */
void HashTable_add(HashTable *htable_ptr, void *key, void *value);

/**
 * Searches the hashtable for a value indexed by key and returns the value
 * @param  htable_ptr Pointer to a HashTable struct
 * @param  key        Pointer to key which will be used to search
 * @return            Pointer to value if found, otherwise NULL
 */
void *HashTable_find(HashTable *htable_ptr, void *key);


#endif
