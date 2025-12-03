#include "../readFile.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
    int bank[100];
    int *first,
        *second;
    int length;
} Battery;

int findBestCombo(Battery *b) {

    int index;

    // find the index of the largest number
    // the first instance of the largest number cannot be at the last position in the array
    for (int i = 0; i < b->length - 1; i++) {
        if (b->first < b->bank[i]){
            b->first = b->bank[i];
            index = i;
        }
    }
    // find the index of the largest number after the largest number
    for (int j = index + 1; j < b->length; j++) {
        if (b->second < b->bank[j])
            b->second = b->bank[j];
    }
        
    // concatenate and return the numbers
    int concat[2];
    sprintf(concat, "%d%d", b->first, b->second);

    return strtol(concat, NULL, 10);

}

int main() {
    FILE* fptr;
    readFile(&fptr, "input.txt");

    // buffer is of length 101, because it always needs space for
    // the null terminator (\0) at the end
    char buffer[101];

    int sum = 0;

    // loop over each "battery bank"
    while (fgets(buffer, sizeof(buffer), fptr) != NULL){
        // every other iteration seems to just be one newline or something
        // hacky way to get around the issue
        if (strlen(buffer) < 100 ) {
            continue;
        }

        Battery *b = malloc(sizeof(Battery));

        b->length = strlen(buffer);
        
        for (int i = 0; i < b->length; i++){
            b->bank[i] = buffer[i] - '0';
        }
        b->first = 0;
        b->second = 0;

        sum += findBestCombo(b);

        free(b);

    }
    printf("\t\tSum: %d", sum);
}