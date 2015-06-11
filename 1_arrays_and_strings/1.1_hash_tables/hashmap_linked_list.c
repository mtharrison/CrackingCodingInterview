// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include "hashmap_linked_list.h"

HashmapLinkedList* HashmapLinkedListNew() {

	return malloc(sizeof(HashmapLinkedList));
}

void HashmapLinkedListSet(HashmapLinkedList* hashmap, char* key, char* value) {

	// Create new hashmap pair
	HashmapLinkedListPair* pair = malloc(sizeof(HashmapLinkedListPair));
	pair->key = key;
	pair->value = value;

	// Is this the first element

	if (hashmap->first != NULL) {
		pair->next = hashmap->first;
	}

	hashmap->first = pair;
}

char* HashmapLinkedListGet(HashmapLinkedList* hashmap, char* key) {

	HashmapLinkedListPair* next = hashmap->first;

	while(next != NULL) {
		if (strcmp(next->key, key) == 0) {
			return next->value;
		}
		next = next->next;
	}

	return NULL;
}