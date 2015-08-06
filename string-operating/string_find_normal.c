/* 带通配符的字符串匹配问题（最大匹配）
*/

#include <stdio.h>
#include <string.h>
char input_a[100];
char input_b[100];
char output[100];
int str_len(char *a){
    if(a == 0)
        return 0;
    char *t = a;
    for(; *t; ++t);
    return (int) (t - a);
}

void str_copy(char *a,const char *b,int len){
    for(;len > 0; --len,++b,++a){
        *a = *b;
    }
    *a = 0; //?
}

//连接字符串
char *str_join(char *a, const char *b, int lenb){
    char *t;
    if(a == 0){
        t = (char *)malloc(sizeof(char) * (lenb + 1));
        str_copy(t, b, lenb);
        return t;
    }
    else{
        int lena = str_len(a);
        t = (char *)malloc(sizeof(char) * (lena + lenb + 2);
        str_copy(t, a, lena);
        *(t + lena) = '';
        str_copy(t + lena + 1, b, lenb);
        free(a);
        return t;
    }
}

int canMatch(char *input, char *rule){ //返回最长匹配长度
    if(*rule == 0)
        return 0; //已经到达rule的底端
    int r = -1, may;
    if(*rule == '*'){
        r = canMatch(input, rule + 1);
        if(*input){
            may = canMatch(input + 1, rule);
            if((may >= 0) && (++may > 0)){
                r = may;
            }
        }
    }
    if(*input == 0){
        return r;
    }
    if((*rule == '?') || (*rule == *input)){
        may = canMatch(input + 1, rule + 1);
        if((may >= 0) && (++may > r)){
            r = may;
        }
    }
    return r;
}

char *my_find(char input[], char rule[]){
    int len = str_len(input);
    int *match = (int *)malloc(sizeof(char) * len);
    int i, max_pos = -1;
    char *output = 0;
    for(i = 0; i < len; ++i){
        match[i] = canMatch(input + i, rule);
        if((max_pos < 0) || (match[i] > match[max_pos]))
            max_pos = i;
    }
/* char* my_find(char input[],char rule[]){
    char* a = input;
    char* b = rule;
    while(*a != '\0'){
        if(*a != *b && *a != '\0'){
            a++;
        }
        else{
            b++;
            if(*b != '?' && *b != '*')
    }
} */

int main(int argc,char* argv[]){
    printf("input string a:\n");
    scanf("%s",input_a);
    /* printf("input string b:\n");
    scanf("%s",input_b);
    int len = strlen(input);
    printf("len = %d", len); */
    int len = str_len(input_a);
    return 0;
}
