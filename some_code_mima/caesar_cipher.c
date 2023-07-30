#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu(void);
int Caesarcode(char word[255],char code[255]);
int Discode(char word[255],char code[255]);
//example is as below:
//code:KRVW DVVLPLDOWHG PRWKHU FROROB HVWDEDLVKHG SUHSDULQJ WKH UHFRQQHFWLRQ
//word:HOST ASSIMILATED MOTHER COLONY ESTABLISHED PREPARING THE RECONNECTION

int main(void)
{
    menus();
    int flag=1;
    char word[255]= {};
    char code[255]= {};
    while(flag)
    {
        memset(word,0,255);
        memset(code,0,255);
        printf("Please input your choice!:");
        scanf("%d",&flag);
        scanf("%*[^\n]");
        scanf("%*c");
        switch (flag)
        {
        case 1:
            printf("Please input your word:");
            gets(word);
//            scanf("%*[^\n]");
//            scanf("%*c");
            Caesarcode(word,code);
            break;
        case 2:
            printf("Please input your code:");
            gets(code);
            Discode(word,code);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Error input!\n\n");
            break;
        }

    }
    return 0;
}

void menus(void)
{
    printf("1.Encode!\n");
    printf("2.Discode!\n");
    printf("0.Exit!\n\n");
    return ;
}

int Caesarcode(char word[255],char code[255])
{
    int i=0;
    int n=0;
    printf("please input your code-number:");
    scanf("%d",&n);
//    scanf("%*[\n]");
//    scanf("%*c");
    for(i=0; i<strlen(word); i++)
    {
        char ch=word[i];
        if(ch<='z'&&ch>='a')
        {
            code[i]=(ch-'a'+n)%26+'a';
        }
        else if(ch<='Z'&&ch>='A')
        {
            code[i]=(ch-'A'+n)%26+'A';
        }
        else
        {
            code[i]=ch;
        }
    }
    printf("Your code text is below:\n");
    printf("%s\n",code);
    printf("the code number here is:%d\n",n);
    return 0;
}

int Discode(char word[255],char code[255])
{
    char temp[255];
    printf("Your code number is :");
    int n=0;
    scanf("%d",&n);
//    scanf("%*[\n]");
//    scanf("%*c");

//    scanf("%*[\n]");
//    scanf("%*c");
    int i=0;
    for(i=0; i<strlen(code); i++)
    {
        char ch=code[i];
        if(ch<='Z'&&ch>='A')
        {
            temp[i]=(ch-n-'Z')%26+'Z';
        }
        else if(ch<='z'&&ch>='a')
        {
            temp[i]=(ch-n-'z')%26+'z';
        }
        else
        {
            temp[i]=code[i];
        }
    }
    printf("the word is:%s\n",temp);
    memset(temp,0,255);
    return 0;
}
/*凯撒密码是比较简单的，只是进行单表代换，实现起来也比较容易，破解起来也不难，是很不安全的密码。
凯撒密码是没有密匙的，即使没有密匙也能将它破解出来，因为凯撒移位密码只有25种密匙，最多就是将这
25种可能性挨个检测一下可以了，这就是我们所说的暴力破解法。
当然，还可以使用频度分析法分析每个字母出现的频率，从而知道凯撒密码的移位数。
“如果我们知道一条加密信息所使用的语言，那么破译这条加密信息的方法就是找出同样的语言写的一篇其
他文章，大约一页纸长，然后我们计算其中每个字母的出现频率。我们将频率最高的字母标为1号，频率排
第2的标为2号，第三标为3号，依次类推，直到数完样品文章中所有字母。然后我们观察需要破译的密文，
同样分类出所有的字母，找出频率最高的字母，并全部用样本文章中最高频率的字母替换。第二高频的字母
用样本中2号代替，第三则用3号替换，直到密文中所有字母均已被样本中的字母替换。”——（360百科）
*/
/*1.加密算法
对于某一明文字母m来说，假设其ASCII码为x，往后移了i位，则新得到的密文c的ASCII码为x + i，考虑加
密为26个字母周期性加密，则需将ASCII码对26取模，举例小写字母如下：

c = (m - 'a' + i) % 26 + 'a';
2.解密算法
同理，解密算法也是一个意思，对于某一密文字母m来说，假设其ASCII码为x，往前移了i位，则新得到的密
文c的ASCII码为x - i，考虑加密为26个字母周期性加密，则需将ASCII码对26取模，再考虑到且（x-i）可能
为负数，取’z’进行计算，举例小写字母如下：

m = (c - 'z' - i) % 26 + 'z';
*/