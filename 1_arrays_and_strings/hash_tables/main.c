// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison
// Cracking the Coding Interview
// Chapter 1 - Arrays and Strings 
// Matt Harrison

#include <stdio.h>
#include "hashmap_simple.h"
#include "hashmap_linked_list.h"
#include "hashmap_fast.h"

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

    // HashmapFast

    HashmapFast* hashmap3 = HashmapFastNew();

    HashmapFastSet(hashmap3, "First Name", "Matt");
    HashmapFastSet(hashmap3, "Last Name", "Harrison");
    HashmapFastSet(hashmap3, "First Name", "Matthew");
    HashmapFastSet(hashmap3, "Last Name", "Hazza");

    printf("%s\n", HashmapFastGet(hashmap3, "First Name"));
    printf("%s\n", HashmapFastGet(hashmap3, "Last Name"));

    free(hashmap3);
    
    return 0;
}