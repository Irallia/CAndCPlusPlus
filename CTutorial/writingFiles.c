#include <stdio.h>
#include <stdlib.h>

#include <cstring>

int main() {

    FILE * fpointer = fopen("test.txt", "w");   // r: read, w: write, a: append
                                                // An absolute path would be something like: C:test.txt
    fprintf(fpointer, "Jim, 5\nTom, 3\nAnna, 7");

    fclose(fpointer);                           // Make sure that you close the file again.

    FILE * fpointer2 = fopen("test.txt", "a");  // append:
    fprintf(fpointer2, "\nTim, 6");             // Tim, 6
    fclose(fpointer2);

    const int MAX_SIZE = 255;
    char line[MAX_SIZE];
    char text[MAX_SIZE][MAX_SIZE]; // row x column
    int index = 0;

    FILE * fpointer3 = fopen("test.txt", "r");
    while(fgets(line, MAX_SIZE, fpointer3) != NULL) {
        printf("Reading: \"%s\"", line);
        strcpy(text[index], line);
        index++;
    }
    fclose(fpointer3);

    FILE * fpointer4 = fopen("test.txt", "w");
    fprintf(fpointer4, "overwritten");
    fclose(fpointer4);

    printf("\nSaved:\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        if (text[i] != "" && text[i] != NULL && text[i] != "\n" && text[i] != " "){
            printf("%s", text[i]);
        }
    };

    return 0;
}