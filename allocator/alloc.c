#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 500

#include "alloc.h"

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

void* HEAP = NULL;

int bump_free(void) {
	fprintf(stdout, "bump_free() invoked\n");
	if (HEAP == NULL) return -1;
	int status = brk(HEAP);
	return status;
}

void* bump_alloc(intptr_t size) {
	if (!size || size < 1) return (void *)-1;
	void *allocated = sbrk(size);

	if (allocated == (void *)-1) {
		fprintf(stderr, "sbrk(): failed\n");
		return NULL;
	}

	if (HEAP == NULL) HEAP = allocated;
	return allocated;
}


