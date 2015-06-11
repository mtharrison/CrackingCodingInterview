// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include <stdio.h>
#include "hashmap_simple.h"
#include "hashmap_linked_list.h"

int main(int argc, char const *argv[])
{
	// HashmapSimple

    HashmapSimple* hashmap = HashmapSimpleNew();
    
    HashmapSimpleSet(hashmap, "First Name", "Matt");
    HashmapSimpleSet(hashmap, "Last Name", "Harrison");

    printf("%s\n", HashmapSimpleGet(hashmap, "First Name"));
    printf("%s\n", HashmapSimpleGet(hashmap, "Last Name"));

    free(hashmap);

    // HashmapLinkedList

    HashmapLinkedList* hashmap2 = HashmapLinkedListNew();

    HashmapLinkedListSet(hashmap2, "First Name", "Matt");
    HashmapLinkedListSet(hashmap2, "Last Name", "Harrison");

    printf("%s\n", HashmapLinkedListGet(hashmap2, "First Name"));
    printf("%s\n", HashmapLinkedListGet(hashmap2, "Last Name"));

    free(hashmap2);
    
    return 0;
}