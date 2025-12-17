#include "../readFile.h"
#include <stdio.h>
#include <string.h>

#define ARRLEN 136
#define MAX 3

enum contents {
  EMPTY = '.',
  TOILET_ROLL = '@',
};

int checkAdjacent(enum contents shelf[ARRLEN][ARRLEN], int col, int row) {
  int adjacent = 0;

  for (int i = col - 1; i <= col + 1; i++) {
    if (i < 0 || i >= ARRLEN - 1)
      continue;
    
    for (int j = row - 1; j <= row + 1; j++) {
      if (j < 0 || j >= ARRLEN - 1)
        continue;

      printf("%c", (i == col && j == row) ? 'x' : shelf[i][j]);
      if (shelf[i][j] == TOILET_ROLL && !(i == col && j == row)) {
        adjacent++;
      }
    }  

    printf("\n");
  }

  if (adjacent > MAX) {
    printf("Too many rolls nearby: %d\n", adjacent);
    return 0; 
  }

  return 1;
}

int canBeForklifted(enum contents shelf[ARRLEN][ARRLEN]) {
  int reachable = 0;

  for (int col = 0; col < ARRLEN; col++) {
    for (int row = 0; row < ARRLEN; row++) {
      
      if (shelf[col][row] == TOILET_ROLL && checkAdjacent(shelf, col, row)){
        reachable++;
        printf("Reached new toilet roll at %d, %d\n", col, row);
      }
      
    }
  }

  return reachable;
}

int main() {
  printf("Running!\n");
  FILE *fptr;

  readFile(&fptr, "input.txt");

  // each line is 135 characters long, plus newline and null terminator
  char buffer[ARRLEN + 1];

  // ROW, COLUMN
  enum contents shelf[ARRLEN][ARRLEN] = {0};

  int column = 0,
      row    = 0;
 
  while (fgets(buffer, sizeof(buffer), fptr) != NULL){
    
    // hacky way to ignore empty lines
    if (strlen(buffer) <= 1) {
      continue;
    }
  
    while(row < strlen(buffer) - 1) {
      shelf[column][row] = buffer[row];
      row++;
    } 

    row = 0;
    column++;
  }

  fclose(fptr);

  printf("Total rolls that can be fetched: %d\n", canBeForklifted(shelf));
}

