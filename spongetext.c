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

    // Copy the string to the clipboard
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == '\n')
            string[i] = '\0'; // This removes the trailing newline to prevent it from being copied to the clipboard
    }
    char cmd[100];
    sprintf(cmd, "printf '%s' | pbcopy", string);
    system(cmd);
    printf("Copied to clipboard.\n");

    // Exit
    return 0;
}