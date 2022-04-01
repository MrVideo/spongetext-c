#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {

    // Get input
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    // Convert to lowercase
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }

    // Spongify text
    for (int i = 0; i < strlen(string); i+=2) {
        if(string[i] != ' ' && string[i] != '\n')
            string[i] -= 32;
    }

    // Print spongified text
    printf("\nSpongified text: %s\n", string);

    // Exit
    return 0;
}