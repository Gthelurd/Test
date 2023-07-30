
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//example is as below:
//Words:    CRYPTO IS SHORT FOR CRYPTOGRAPHY
//Enc:      CSASXT IT UKSWT GQU GWYQVRKWAQJB
//KEY-word: ABCDEF AB CDEFA BCD EFABCDEFABCD

#include <stdio.h>
#include <string.h>
#include <ctype.h>
 int main(void) {
    char str1[255];
    char str2[255];
    char str3[255];
    int str1_length, str2_length;
    int i, j;
     printf("Please input your Words here:\n");
    fgets(str1, sizeof(str1), stdin);
    str1_length = strlen(str1);
    if (str1[str1_length - 1] == '\n') {
        str1[str1_length - 1] = '\0'; // remove newline character
        str1_length--;
    }
     printf("Please input your Keywords here:\n");
    fgets(str2, sizeof(str2), stdin);
    str2_length = strlen(str2);
    if (str2[str2_length - 1] == '\n') {
        str2[str2_length - 1] = '\0'; // remove newline character
        str2_length--;
    }
     // Convert the keyword to lowercase
    for (i = 0; i < str2_length; i++) {
        str2[i] = tolower(str2[i]);
    }
     // Encrypt the message
    j = 0;
    for (i = 0; i < str1_length; i++) {
        if (isalpha(str1[i])) {
            if (isupper(str1[i])) {
                str3[i] = ((str1[i] - 'A') + (str2[j] - 'a')) % 26 + 'A';
            } else if (islower(str1[i])) {
                str3[i] = ((str1[i] - 'a') + (str2[j] - 'a')) % 26 + 'a';
            }
            j = (j + 1) % str2_length;
        } else {
            str3[i] = str1[i];
        }
    }
    str3[i] = '\0'; // add null terminator
     printf("Your Enc is below:\n\n");
    printf("%s\n", str3);
     return 0;
}