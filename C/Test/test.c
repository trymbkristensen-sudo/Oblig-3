#include <stdio.h>
#include <stdlib.h> // Required for atoi()

int main() {
    char charArray[] = "12345"; // A char array representing a number
    int integerValue;

    // Convert the char array to an int using atoi()
    integerValue = atoi(charArray);

    printf("The char array \"%s\" converted to an int is: %d\n", charArray, integerValue);
}