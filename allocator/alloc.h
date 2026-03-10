#ifndef ALLOC_H
#define ALLOC_H

#include <stdint.h>

int bump_free(void);
void* bump_alloc(intptr_t size);

#endif
