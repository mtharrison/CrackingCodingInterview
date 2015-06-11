// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct HashmapLinkedListPair {
	struct HashmapLinkedListPair* next;
	char* key;
	char* value;
} HashmapLinkedListPair;

typedef struct {
	HashmapLinkedListPair* first;
} HashmapLinkedList;

HashmapLinkedList* HashmapLinkedListNew();

// Adds a key => value pair to the hashmap

void HashmapLinkedListSet(HashmapLinkedList* hashmap, char* key, char* value);

// Retrieves the value for a key from the hashmap

char* HashmapLinkedListGet(HashmapLinkedList* hashmap, char* key);