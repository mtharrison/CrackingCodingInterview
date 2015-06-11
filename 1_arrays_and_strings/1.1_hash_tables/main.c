#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_MAX_SIZE 10

typedef struct {
    char* keys[HASHMAP_MAX_SIZE];
    char* values[HASHMAP_MAX_SIZE];
    int ptr;
} Hashmap;

Hashmap* HashmapNew() {
    
    Hashmap* hashmap = malloc(sizeof(Hashmap));
    hashmap->ptr = 0;
    
    return hashmap;
}


void HashmapAdd(Hashmap* hashmap, char* key, char* value) {
    
    hashmap->keys[hashmap->ptr] = key;
    hashmap->values[hashmap->ptr] = value;
    hashmap->ptr++;
}

int HashmapIndexForKey(Hashmap* hashmap, char * key) {
    
    for (int i = 0; i < HASHMAP_MAX_SIZE; ++i)
    {
        if (NULL != hashmap->keys[i] && strcmp(key, hashmap->keys[i]) == 0) {
            return i;
        }
    }
    
    return -1;
}

void HashmapRemove(Hashmap* hashmap, char* key) {
    
    int i = HashmapIndexForKey(hashmap, key);
    
    if (i > -1) {
        hashmap->keys[i] = NULL;
        hashmap->values[i] = NULL;
    }
}

char* HashmapGet(Hashmap* hashmap, char* key) {
    
    int i = HashmapIndexForKey(hashmap, key);
    
    if (i == -1) {
        return NULL;
    }
    
    return hashmap->values[i];
}

int main(int argc, char const *argv[])
{
    
    Hashmap* hashmap = HashmapNew();
    
    HashmapAdd(hashmap, "Name", "Matt");
    HashmapAdd(hashmap, "BirthYear", "1986");
    
    char* name = HashmapGet(hashmap, "Name");
    char* birthYear = HashmapGet(hashmap, "BirthYear");

    printf("%s\n", name);
    printf("%s\n", birthYear);
    
    HashmapRemove(hashmap, "Name");
    
    name = HashmapGet(hashmap, "Name");
    printf("%s\n", name);
    
    return 0;
}