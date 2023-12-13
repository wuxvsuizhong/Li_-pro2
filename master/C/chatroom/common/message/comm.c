#include "comm.h"

void Free(void **ptr) {
    void *dstPtr = (*ptr);
    free(dstPtr);
    *ptr = NULL;
}