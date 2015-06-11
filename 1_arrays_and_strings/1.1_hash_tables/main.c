#include <stdio.h>
#include "hashmap_simple.h"

int main(int argc, char const *argv[])
{

	// HashmapSimple

    HashmapSimple* hashmap = HashmapSimpleNew();
    
    HashmapSimpleSet(hashmap, "Name", "Matt");
    HashmapSimpleSet(hashmap, "BirthYear", "1986");
    HashmapSimpleSet(hashmap, "Name", "Matt");
    HashmapSimpleSet(hashmap, "BirthYear", "1986");
    HashmapSimpleSet(hashmap, "Name", "Matt");
    HashmapSimpleSet(hashmap, "BirthYear", "1986");
    HashmapSimpleSet(hashmap, "Name", "Matt");
    HashmapSimpleSet(hashmap, "BirthYear", "1986");
    HashmapSimpleSet(hashmap, "Name", "Matt");
    HashmapSimpleSet(hashmap, "BirthYear", "1986");

    printf("%s\n", HashmapSimpleGet(hashmap, "Name"));
    printf("%s\n", HashmapSimpleGet(hashmap, "BirthYear"));

    free(hashmap);
    
    return 0;
}