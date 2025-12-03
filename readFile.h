#ifndef READFILE_H
#define READFILE_H

#include <stdio.h>

static inline int readFile(FILE **fptr, char* filename) {
    printf("looking for file...\n");
    *fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("File not found or is empty\n");
    return 1;
  }
  return 0;
}

#endif