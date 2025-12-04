#include "../readFile.h"
#include <string.h>

enum contents {
  EMPTY = '.',
  TOILET_ROLL = '@',
};

int main() {
  FILE *fptr;

  readFile(&fptr, "input.txt");

  // each line is 135 characters long, plus newline and null terminator
  char buffer[137];

  // COLUMN, ROW
  char shelf[136][136];

  int column = 0,
      row = 0;
 
  while (fgets(buffer, sizeof(buffer), fptr) != NULL){
    
    // hacky way to ignore empty lines
    if (strlen(buffer) != 1) {
      continue;
    }

    printf("Row: %d\tColumn: %d\n", row, column);
    printf("Buffer contents: %s\n", buffer);
  
    while(row < strlen(buffer)) {
      shelf[row][column] = buffer[row];
      row++;
    } 

    row = 0;
    column++;
  }
}

int canBeForklifted(char **shelf) {
  int reachable = 0;
  int adjacent = 0;

  for ()

  return reachable;
}
