// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison
//
// This is my naive implementation of a hashmap in C using a struct and arrays.
// The Hashmap is a struct containing two arrays, one for keys and one for values
// The indices of each are used to find the partner. New elements are always added
// on the end of the hashmap's arrays
//
// Features:
//
// * The hashmap can be dynamically resized when it outgrows itself
//
// Limitations:
//
// * Elements can only be added, never removed

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char** keys;
    char** values;
    int ptr;
    int size;
} HashmapSimple;

HashmapSimple* HashmapSimpleNew();

// Adds a key => value pair to the hashmap

void HashmapSimpleSet(HashmapSimple* hashmap, char* key, char* value);

// Retrieves the value for a key from the hashmap

char* HashmapSimpleGet(HashmapSimple* hashmap, char* key);