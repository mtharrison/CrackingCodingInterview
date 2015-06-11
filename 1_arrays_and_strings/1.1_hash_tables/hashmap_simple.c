#include "hashmap_simple.h"

// Hashmaps are created with this initial size
#define HASHMAP_INITIAL_SIZE 10
// Each time a hashmap needs more space, it is increased
// by this much
#define HASHMAP_RESIZE_INCREMENT 10

HashmapSimple* HashmapSimpleNew() {
    
    HashmapSimple* hashmap = malloc(sizeof(HashmapSimple));

    hashmap->keys = malloc(sizeof(char* [HASHMAP_INITIAL_SIZE]));
    hashmap->values = malloc(sizeof(char* [HASHMAP_INITIAL_SIZE]));
    hashmap->ptr = 0;
    hashmap->size = HASHMAP_INITIAL_SIZE;
    
    return hashmap;
}

// Adds a key => value pair to the hashmap

void HashmapSimpleSet(HashmapSimple* hashmap, char* key, char* value) {
    
    hashmap->keys[hashmap->ptr] = key;
    hashmap->values[hashmap->ptr] = value;
    hashmap->ptr++;
}

// Gets the index for a hash key

int HashmapSimpleIndexForKey(HashmapSimple* hashmap, char * key) {
    
    for (int i = 0; i <= hashmap->size; ++i)
    {
        if (NULL != hashmap->keys[i] && strcmp(key, hashmap->keys[i]) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Retrieves the value for a key from the hashmap

char* HashmapSimpleGet(HashmapSimple* hashmap, char* key) {
    
    int i = HashmapSimpleIndexForKey(hashmap, key);
    
    if (i == -1) {
        return NULL;
    }
    
    return hashmap->values[i];
}