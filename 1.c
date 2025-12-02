#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fptr;
  fptr = fopen("input.txt", "r");
  if (fptr == NULL){
    printf("File not found or is empty");
    return 1;
  }

  // Dial starts at 50
  int dial = 50;
  int pwd = 0;

  char buffer[10];
  while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
    char rorl = buffer[0];

    // Parse number
    // Start from the second index, since the first one is always the 
    // direction
    char* numPointer = &buffer[1];
    long int num = strtol(numPointer, NULL, 10);

    if (rorl != 'L' && rorl != 'R') {
      printf("error reading first character: %c\n", rorl);
      return 1;
    }

    if (rorl == 'L') {
      dial = (dial - num) % 100;
    } else {
      dial = (dial + num) % 100;
    }

    if (dial == 0)
      pwd++;
  }

  printf("password: %d", pwd);

  fclose(fptr);

  return 0;
}
