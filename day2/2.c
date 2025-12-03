#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  FILE *fptr;
  fptr = fopen("input.txt", "r");
  if (fptr == NULL){
    printf("File not found or is empty");
    return 1;
  }

  char buffer[1000];

  // read from file line by line (only one giga long line this time)
  while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
  
    // set the delimiter so we can split the long ass line
    char* token = strtok(buffer, ",");
    while (token) {
      char* strpointer = &buffer[0];

    }
    

    
  }

  return 0;
}

// returns 0 if no palindrome is found
int evenNumberPalindrome(char* a, char* b) {
  
  // if the length of both parts is the same and they are of odd length
  // there is no valid palindrome
  if (strlen(a) == strlen(b) && strlen(a) % 2 != 0)
    return 0;




  long int sum = 0;


  return sum;
}

char** splitRange(char* input) {

  char** token = 

  return
}
