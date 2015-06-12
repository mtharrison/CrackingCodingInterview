#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

// 1.1 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

bool allUniqueSimple(const char* string) 
{

	int counts[256] = {0};
	int i = 0;

	while(string[i] != '\0') {
		int c = (int) string[i];
		counts[c]++;

		if (counts[c] > 1) {
			return false;
		}

		i++;
	}

	return true;
}

bool allUniqueBitVector(const char* string) 
{
	// If we count all letters uppercase and lowercase, we need 26 * 2 = 56 bits

	uint64_t bitVector = 0; // 00000..0 (64 bits)

	for (int i = 0; i < strlen(string); ++i)
	{
		uint64_t one = 1;
		uint64_t compare = one << (string[i] - 1);

		if ((bitVector & compare) != 0) {
			return false;
		}
		
		bitVector |= compare;
	}

	return true;
}

// 1.2 Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.

char* revString(char* str, char* rev) {

	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		rev[len - 1 - i] = str[i];
	}

	rev[len] = '\0';

	return rev;
}

int main(int argc, char const *argv[])
{
	// 1.1
	
	assert(allUniqueSimple("ABCDEFGHIJ") == true);
	assert(allUniqueSimple("ABCDEFAGJHIJ") == false);

	assert(allUniqueBitVector("ABCDEFGHIJ") == true);
	assert(allUniqueBitVector("ABCDEFGHIJZz") == true);
	assert(allUniqueBitVector("ABCDEFGHIJZZ") == false);

	// 1.2

	char rev1[3];
	char rev2[3];

	assert(strcmp(revString("ABC", rev1), "CBA") == 0);
	assert(strcmp(revString("123", rev2), "321") == 0);

	return 0;
}