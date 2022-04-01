#ifdef __GNUC__
    #define GNU
#else
    #define WINDOWS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef WINDOWS
    #define WIN32_MEAN_AND_LEAN
    #include <Windows.h>
#endif

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
    #ifdef GNU
        sprintf(cmd, "printf '%s' | pbcopy", string);
        system(cmd);
    #else
        const size_t len = strlen(string) + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), string, len);
        GlobalUnlock(hMem);
        OpenClipboard(0);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
    #endif

    printf("Copied to clipboard.\n");

    // Exit
    return 0;
}