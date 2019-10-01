#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello world!\n");

    /* variables: */
    char characterName[] = "John";  // instead of 'string characterName' in C++
    int characterAge = 67;
    printf("There is a man named %s with the age of %d.\n", characterName, characterAge);

    /* data types: */
    int age = 50;
    float gpa = 3.7;                // 4 Byte
    double num = 2.3;               // 8 Byte
    char grade = 'A';
    char phrase[] = "Bla blubb";    // instead of 'string phrase = "Bla blubb"' in C++;
    // bool isCorrect = true;   -   C doesn't have any built-in boolean types.

    /* printf */
    printf("Hello!\n\"Format specifyers:\"\n %d, %f, %f, %c and %s", age, gpa, num, grade, phrase);

    return 0;
}