#include "comm.h"

void Free(void **ptr) {
    dstPtr = (*ptr);
    free(dstPtr);
    *prt = NULL;
}