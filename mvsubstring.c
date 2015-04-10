#include <stdio.h>
#include <string.h>
void reverse(char* s,int from,int to){
	while(from < to){
		char tmp = s[from];
		s[from++] = s[to];
		s[to--] = tmp;
	}
}
void LeftRotateRight(char* s,int k,int n){
	k %= n; //非常重要，防止k大于n
	reverse(s,0,k - 1);
	reverse(s,k,n - 1);
	reverse(s,0,n - 1);
}
int main(int argc,char* argv[]){
	char s[100];
	if (argc != 2)
	{
		printf("参数错误！\n");
	}
	else{
		strcpy(s,argv[1]);
		printf("%s\n", s);
		LeftRotateRight(s,2,7);
		printf("%s\n", s);
	}
}