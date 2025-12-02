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

    int dial = 50;
    int pwd = 0;

    char buffer[10];
    while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
        int len = 1;
        // Dial starts at 50

        char rorl = buffer[0];

        // get length of number
        for (len; buffer[len] != '\n'; len++);
        // parse number
        char* numPointer = &buffer[1];
        long int num = strtol(numPointer, NULL, 10);

        printf("num: %d", num);
        printf("\t\tdirection: %c", rorl);
        printf("\t\tdial: %d", dial);
        printf("\t\tbuffer: %s", buffer);
        
        if (rorl != 'L' && rorl != 'R') {
            printf("error reading first character: %c", rorl);
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