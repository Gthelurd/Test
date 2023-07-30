#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void a1z26Decoder(char *encoded) {
    int len = strlen(encoded);
    int i, num;
    char *token;
    
    token = strtok(encoded, " ");
    while (token != NULL) {
        num = atoi(token);
        if (num >= 1 && num <= 26) {
            printf("%c", num + 96);  // Convert number to corresponding letter
        } else {
            printf("\nInvalid input: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
        char a1z26Code[256];
    //printf("a1z26的字符串：");
    printf("\texample:you have the code:\"15 11 8 6 9 8 19 6\"\n\tthen you can have the str:okhfihsf\n");
    printf("\n\ta1z26's string(strlens less than 256):");
    fgets(a1z26Code, sizeof(a1z26Code), stdin);
    a1z26Decoder(a1z26Code);
    system("pause");
    return 0;
}