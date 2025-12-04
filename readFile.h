#include <stdio.h>

/// Returns 0 if successful, 1 if unsuccessful
static inline int readFile(FILE** fptr, char* filename) {
  *fptr = fopen(filename, "r");
  if (fptr == NULL){
    printf("File not found or is empty");
    return 1;
  }

  return 0;
}
