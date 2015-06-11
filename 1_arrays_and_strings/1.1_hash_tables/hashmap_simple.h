// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
//
// This is my naive implementation of a hashmap in C using a struct and arrays
//
// Features:
//
// * The hashmap can be dynamically resized when it outgrows itself
//
// Limitations:
//
// * Elements can only be added never removed
// * No detection of collisions
// * Can't replace a key's value

#include <stdlib.h>
#include <string.h>

typedef struct {
    char** keys;
    char** values;
    int ptr;
    int size;
} HashmapSimple;

HashmapSimple* HashmapSimpleNew();

// Adds a key => value pair to the hashmap

void HashmapSimpleSet(HashmapSimple* hashmap, char* key, char* value);

// Gets the index for a hash key

int HashmapSimpleIndexForKey(HashmapSimple* hashmap, char * key);

// Retrieves the value for a key from the hashmap

char* HashmapSimpleGet(HashmapSimple* hashmap, char* key);