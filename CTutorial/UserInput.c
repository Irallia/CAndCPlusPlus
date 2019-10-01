
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* User Input */
    int number;
    double d;
    char c;
    char name[20];                  // You need to tell how long this variable is.
    printf("Enter your number: ");
    scanf("%d", &number);
    printf("Enter a double: ");
    scanf("%lf", &d);
    /*
    * The %c conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in
    * the input stream (from a previous entry, for example) the scanf call will consume it immediately.
    * One way around the problem is to put a blank space before the conversion specifier in the format string:
    */
    printf("Enter a char: ");       // The blank in the format string tells scanf to skip leading whitespace, and the
    scanf(" %c", &c);               // first non-whitespace character will be read with the %c conversion specifier.
    printf("Enter your name: ");
    scanf("%s", name);              // It grabs the string up to the first space. If you enter Jo Su its just saving Jo.
    printf("Your number is %d, the double is %f, the char is %c and your name is %s \n", number, d, c, name);
    /* scanf doesn't consume the newline and is thus a natural enemy of fgets. Don't put them together without a good hack. */
    char tmp[50];
    fgets(tmp, 50, stdin);          // clean up
    printf("Enter your name again: ");
    fgets(name, 20, stdin);         // Takes the whole line up to 20 chars from the standard input.
    printf("Your name is: %s", name);
    char nameF[20];
    char nameL[20];
    printf("Enter your name again: ");
    scanf("%s%s", nameF, nameL);         // Takes the whole line up to 20 chars from the standard input.
    printf("Your name is: %s %s\n", nameF, nameL);

    return 0;
}