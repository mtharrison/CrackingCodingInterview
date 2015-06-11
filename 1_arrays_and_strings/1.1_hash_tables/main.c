#include <stdio.h>
#include <string.h>

static char* keys[10];
static char* values[10];
static int hashmapPtr = 0;

void HashmapAdd(char* key, char* value) {
	keys[hashmapPtr] = key;
	values[hashmapPtr] = value;

	hashmapPtr++;
}

char* HashmapGet(char* key) {
	for (int i = 0; i < 10; ++i)
	{
		if (NULL != keys[i] && strcmp(key, keys[i]) == 0) {
			return values[i];
		}
	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	HashmapAdd("NameXXXXXX", "Matt");
	HashmapAdd("BirthYearX", "1986");

	char* name = HashmapGet("Name");
	char* birthYear = HashmapGet("BirthYear");

	printf("%s\n", name);
	printf("%s\n", birthYear);

	return 0;
}