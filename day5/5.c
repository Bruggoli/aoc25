#include "../readFile.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned long min,
                max;
} valid_range;


int main() {
  FILE* fptr;
  readFile(&fptr, "input.txt");

  // i counted the range lines lmao
  valid_range *range = malloc(sizeof(valid_range) * 173);

  int rangeptr = 0;

  // we doing the naive solution here

  char buffer[200] = {'0'};

  
  while (fgets(buffer, sizeof(buffer), fptr) != NULL){

    // super naive
    // if any line starts with a newline, we move on to the next step.
    // :)
    if (buffer[0] == '\n')
      break;

    long int min = 0;
    long int max = 0;
    char delim = '-';

    sscanf(buffer, "%ld %c %ld", &min, &delim, &max);

    range[rangeptr].min = min;
    range[rangeptr].max = max;

    rangeptr++;

  }


  int fresh_wares = 0;

  while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    long int num = 0;
    sscanf(buffer, "%ld", &num);
    for (int i = 0; i < 173; i++) {
      if (num >= range[i].min && range[i].max >= num){
        fresh_wares++;
        break;
      }
    }
  }

  printf("fresh wares remaining: %d\n", fresh_wares);

  return 0;
}
