#include "hashmap_simple.h"

// Hashmaps are created with this initial size
#define HASHMAP_INITIAL_SIZE 10
// Each time a hashmap needs more space, it is increased
// by this much
#define HASHMAP_RESIZE_INCREMENT 10

HashmapSimple* HashmapSimpleNew() {
    
    HashmapSimple* hashmap = malloc(sizeof(HashmapSimple));
    
    hashmap->keys = calloc(1, sizeof(char* [HASHMAP_INITIAL_SIZE]));
    hashmap->values = calloc(1, sizeof(char* [HASHMAP_INITIAL_SIZE]));
    hashmap->ptr = 0;
    hashmap->size = HASHMAP_INITIAL_SIZE;
    
    return hashmap;
}

// Increases the hashmap's capacity by HASHMAP_RESIZE_INCREMENT

void HashmapResize(HashmapSimple* hashmap) {
    
    // Make some new bigger arrays
    
    int newSize = hashmap->size + HASHMAP_RESIZE_INCREMENT;
    char** newKeys = calloc(1, sizeof(char* [newSize]));
    char** newVals = calloc(1, sizeof(char* [newSize]));
    
    // Copy the memory over from the old arrays
    
    memcpy(newKeys, hashmap->keys, sizeof(char* [hashmap->size]));
    memcpy(newVals, hashmap->values, sizeof(char* [hashmap->size]));
    
    // Free the memory from the old arrays
    
    free(hashmap->keys);
    free(hashmap->values);
    
    // Update the struct with the new values
    
    hashmap->keys = newKeys;
    hashmap->values = newVals;
    hashmap->size = newSize;
}

// Gets the index for a hash key

int HashmapSimpleIndexForKey(HashmapSimple* hashmap, char * key) {
    
    for (int i = 0; i < hashmap->size; ++i)
    {
        if (NULL != hashmap->keys[i] && strcmp(key, hashmap->keys[i]) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Adds a key => value pair to the hashmap

void HashmapSimpleSet(HashmapSimple* hashmap, char* key, char* value) {
    
    // First check if the key exists
    
    int i = HashmapSimpleIndexForKey(hashmap, key);
    
    // It does exist, so just replace the value for the index
    
    if (i > -1) {
        hashmap->values[i] = value;
        return;
    }
    
    hashmap->keys[hashmap->ptr] = key;
    hashmap->values[hashmap->ptr] = value;
    hashmap->ptr++;
    
    // If the hashmap is full, resize it up
    
    if (hashmap->ptr == hashmap->size) {
        HashmapResize(hashmap);
    }
}

// Retrieves the value for a key from the hashmap

char* HashmapSimpleGet(HashmapSimple* hashmap, char* key) {
    
    int i = HashmapSimpleIndexForKey(hashmap, key);
    
    if (i == -1) {
        return NULL;
    }
    
    return hashmap->values[i];
}