#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ASSERT(x) if (!(x)) { printf("FAILED TEST: %s\n", x); }

// returns 0 if no palindrome is found
unsigned long long evenNumberPalindrome(char *rangeLow, char *rangeHigh) {
  // if the length of both parts is the same and they are of odd length
  // there is no valid palindrome
  if (strlen(rangeLow) == strlen(rangeHigh) && strlen(rangeLow) % 2 != 0){
    printf("range length odd, skipping: %d\n\n", strlen(rangeLow));
    return 0;
  }
  unsigned long long sum = 0;

  unsigned long long rangeLowInt = strtoull(rangeLow, NULL, 10);
  unsigned long long rangeHighInt = strtoull(rangeHigh, NULL, 10);

  for (rangeLowInt; rangeLowInt <= rangeHighInt; rangeLowInt++) {
    char* stringInt[32];
    // REMEMBER TO 
    sprintf(stringInt, "%llu", rangeLowInt);

    unsigned long long lengthOfInt = strlen(stringInt);

    long long int firstHalf = rangeLowInt / (int)pow(10, lengthOfInt/2);
    long long int secondHalf = rangeLowInt % (int)pow(10, lengthOfInt/2);

    if (firstHalf == secondHalf) {

      sum += rangeLowInt;
    }

    if (sum < 0)
      printf("sum overflow");
  }
  return sum;
}


void test() {
  ASSERT(evenNumberPalindrome("1", "11") == 11);
  ASSERT(evenNumberPalindrome("55", "65") == 55);
  ASSERT(evenNumberPalindrome("56", "65") == 0);
  ASSERT(evenNumberPalindrome("8888888888", "8888888889") == 8888888888ULL);
}


int main() {

  test();

  printf("looking for file...\n");

  FILE *fptr;
  fptr = fopen("input.txt", "r");
  if (fptr == NULL){
    printf("File not found or is empty\n");
    return 1;
  }

  char buffer[1000];

  unsigned long long sum = 0;
  int numRanges = 0;

  // read from file line by line (only one giga long line this time)
  if(fgets(buffer, sizeof(buffer), fptr) == NULL) {
    printf("file empty %s\n", buffer);
  }

  printf("%s\n", buffer);
  int *pointer;

  // ideally i should use strtok_r everywhere, but using strtok in one instance should be fine.
  // strtok has a global state, and does strange things if it is used with different delimiters
  char *token = strtok_r(buffer, ",", &pointer);
  // initialise token as 
  while (token != NULL) {

    char *rangeLowString = strtok(token, "-");
    char *rangeHighString = strtok(NULL, "-");

    sum += evenNumberPalindrome(rangeLowString, rangeHighString);
    numRanges++;
    token = strtok_r(NULL, ",", &pointer);

  }

  printf("Total sum: %lld\t\tRanges checked: %d\n\n", sum, numRanges);

  return 0;
}
