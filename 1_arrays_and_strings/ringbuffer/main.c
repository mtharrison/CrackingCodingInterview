#include <stdio.h>
#include <stdlib.h>

struct RingbufferCell
{
	int value;
	struct RingbufferCell* next;
	struct RingbufferCell* last;
};

typedef struct RingbufferCell RingbufferCell;

struct Ringbuffer
{
	RingbufferCell* currentPtr;
};

typedef struct Ringbuffer Ringbuffer;

Ringbuffer* RingbufferNew(int size) {

	Ringbuffer* ring = malloc(sizeof(Ringbuffer));
	ring->currentPtr = NULL;

	RingbufferCell* first;

	for (int i = 0; i < size; ++i)
	{
		RingbufferCell* newCell = malloc(sizeof(RingbufferCell));

		// Save the first one

		if (i == 0) {
			first = newCell;
		}

		newCell->last = ring->currentPtr;

		if (ring->currentPtr != NULL) {
			ring->currentPtr->next = newCell;
		}

		ring->currentPtr = newCell;

		if (i == size - 1) {
			newCell->next = first;
			first->last = newCell;
		}
	}

	return ring;
}

void RingbufferWrite(Ringbuffer* ring, int value) {

	ring->currentPtr = ring->currentPtr->next;
	ring->currentPtr->value = value;
}

int RingbufferRead(Ringbuffer* ring) {

	RingbufferCell* curr = ring->currentPtr;
	ring->currentPtr = ring->currentPtr->last;

	return curr->value;
}

void printData(int* data, int size) {

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", data[i]);
	}
}

int main(int argc, char const *argv[])
{
	
	Ringbuffer* ring = RingbufferNew(5);

	RingbufferWrite(ring, 1);
	RingbufferWrite(ring, 2);
	RingbufferWrite(ring, 3);
	RingbufferWrite(ring, 4);
	RingbufferWrite(ring, 5);
	RingbufferWrite(ring, 6);

	printf("%d\n", RingbufferRead(ring));
	printf("%d\n", RingbufferRead(ring));
	printf("%d\n", RingbufferRead(ring));
	printf("%d\n", RingbufferRead(ring));
	printf("%d\n", RingbufferRead(ring));
	printf("%d\n", RingbufferRead(ring));

	return 0;
}