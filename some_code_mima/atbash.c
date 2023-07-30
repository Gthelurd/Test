#include <stdio.h>
#include <ctype.h>

void atbashCipher(char *text) {
    int i = 0;
    while (text[i]) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                printf("%c", 'z' - (text[i] - 'a'));
            } else {
                printf("%c", 'Z' - (text[i] - 'A'));
            }
        } else {
            printf("%c", text[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char text[256] = " ";
    
    printf("\texample:you can enter:\"Hello, World!\"\n\tthen you can get:\"Svool, Dliow!\"");
    fgets(text,sizeof(text),stdin);
    
    printf("Original text(strlens less than 256): %s\n", text);
    
    printf("Encoded text: ");
    atbashCipher(text);
    
    // printf("Decoded text: ");
    // atbashCipher(text);
    
    return 0;
}