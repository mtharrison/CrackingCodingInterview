#include <stdio.h>
#include "hashmap_simple.h"

int main(int argc, char const *argv[])
{
	// HashmapSimple

    HashmapSimple* hashmap = HashmapSimpleNew();
    
    HashmapSimpleSet(hashmap, "First Name", "Matt");
    HashmapSimpleSet(hashmap, "Last Name", "Harrison");
    HashmapSimpleSet(hashmap, "First Name", "Matthew"); // Should override

    printf("%s\n", HashmapSimpleGet(hashmap, "First Name"));
    printf("%s\n", HashmapSimpleGet(hashmap, "Last Name"));

    free(hashmap);
    
    return 0;
}