#include <stdio.h>
#include <string.h>
 void decodeMorseCode(const char* morseCode) {
    // 定义莫斯电码字符与对应字母的映射关系
    const char* morseAlphabet[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
     // 定义莫斯电码数字与对应数字的映射关系
    const char* morseNumeralTable[] = {
        "-----", ".----","..---","...--","....-",".....","-....","--...","---..","----."
    };
     // 定义莫斯电码标点符号与对应标点符号的映射关系
    const char* morsePunctuationTable[] = {
        ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.", "-.-.", "---", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-.", "--..--", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.", "-.-.", "---", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
     // 分割莫斯电码字符串
    char* token = strtok((char*)morseCode, " ");
    while (token != NULL) {
        // 在映射关系中查找对应字母、数字或标点符号
        int i;
        for (i = 0; i < 26; i++) {
            if (strcmp(token, morseAlphabet[i]) == 0) {
                printf("%c", 'a' + i);
                break;
            }
        }
        if (i == 26) {
            for (i = 0; i < 10; i++) {
                if (strcmp(token, morseNumeralTable[i]) == 0) {
                    printf("%d", i);
                    break;
                }
            }
        }
        if (i == 10) {
            for (i = 0; i < 41; i++) {
                if (strcmp(token, morsePunctuationTable[i]) == 0) {
                    const char* punctuationList = ".,?';!-/()&:=\"+@$_";
                    printf("%c", punctuationList[i]);
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }
}
 int main() {
    // 输入莫斯电码字符串
    char morseCode[256];
    // printf("请输入莫斯电码字符串：");
    printf("\texample:you enter the code:.. -....- .-.. --- ...- . -....- -.-- --- ..-\n\tthen you can get the str:i\"love\"you\n");
    printf("\n\tPlease enter the Morse code string:");
    fgets(morseCode, sizeof(morseCode), stdin);
     // 去除换行符
    morseCode[strcspn(morseCode, "\n")] = '\0';
     // 解码莫斯电码
    decodeMorseCode(morseCode);
     return 0;
}