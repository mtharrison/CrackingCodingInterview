// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include "hashmap_fast.h"

#define NUM_BUCKETS 1024

HashmapFast* HashmapFastNew() {

	// Allocate the actual hashmap's memory

	int size = NUM_BUCKETS;
	HashmapFast* hashmap = malloc(sizeof(HashmapFast));
	hashmap->size = size;

	// Allocate the container of the buckets

	hashmap->buckets = malloc(sizeof(HashmapFastNode) * size);

	// Allocate a root node for each bucket

	for (int i = 0; i < size; ++i)
	{
		HashmapFastNode* node = malloc(sizeof(HashmapFastNode));
		node->key = NULL;
		node->val = NULL;
		node->next = NULL;
		hashmap->buckets[i] = node;
	}

	return hashmap;
}

int getHashForKey(char* key) {
	return 0;
}

void HashmapFastSet(HashmapFast* hashmap, char* key, char* value) {

	int hash = getHashForKey(key);

	// Get the root node for this hash's bucket

	HashmapFastNode* root = hashmap->buckets[hash];

	// If this bucket is empty, we can use the root node and we're done

	if (root->key == NULL) {
		root->key = key;
		root->val = value;
		return;
	}

	HashmapFastNode* node = root;

	for (;;) {

		if (strcmp(node->key, key) == 0) {
			node->key = key;
			node->val = value;
			return;
		}

		if (node->next == NULL)
			break;

		node = node->next;
	}

	// Node is now the root node!

	HashmapFastNode* newNode = malloc(sizeof(HashmapFastNode));
	newNode->key = key;
	newNode->val = value;

	node->next = newNode;
}

char* HashmapFastGet(HashmapFast* hashmap, char* key) {

	int hash = getHashForKey(key);

	HashmapFastNode* node = hashmap->buckets[hash];

	for (;;) {

		if (strcmp(node->key, key) == 0) {
			return node->val;
		}

		if (node->next == NULL)
			break;

		node = node->next;
	}

	return NULL;
}