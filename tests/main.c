#include <stdio.h>
#include <string.h>

#include "allocator/alloc.h"

int main(void) {
	char* data = "this is a text string to see whether the allocator works or not";
	size_t size = strlen(data) + 1;

	char* cpy = bump_alloc((intptr_t)size);
	if (cpy == NULL) {
		fprintf(stderr, "bump_alloc(): failed\n");
		return 1;
	}

	memcpy(cpy, data, size);

	printf("copied data to new allocated var: %s\n", cpy);

	if (bump_free()) {
		printf("allocated HEAP freed\n");
	}
}
