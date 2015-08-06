#include <stdio.h>
char *my_find(char input[],char rule[]){
    int len1,len2;
    for(len1 = 0; input[len1]; ++len1);
    for(len2 = 0; rule[len2]; ++len2);
    int MAXN = len1 > len2 ? (len1 + 1) : (len2 + 1);
    int **dp; //?指向二维数组？
