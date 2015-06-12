// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct HashmapFastNode
{
	char* key;
	char* val;
	struct HashmapFastNode* next;
};

typedef struct HashmapFastNode HashmapFastNode;

struct HashmapFast
{
	int size;
	HashmapFastNode** buckets;
};

typedef struct HashmapFast HashmapFast;

HashmapFast* HashmapFastNew();

// Adds a key => value pair to the hashmap

void HashmapFastSet(HashmapFast* hashmap, char* key, char* value);

// Retrieves the value for a key from the hashmap

char* HashmapFastGet(HashmapFast* hashmap, char* key);