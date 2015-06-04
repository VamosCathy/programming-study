/*字符串的移动——三步反转法
要使字符串XY成为YX，只要想到：XY->(X^T*Y^T)^T=YX
在本代码中使用的数据结构为字符数组
*/
#include <stdio.h>
#include <string.h>
void reverse(char *s,int from,int to)
{
	while(from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void RotateString(char *s,int m)
{
	int n = strlen(s);
	m %= n;
	reverse(s,0,n - m - 1);
	reverse(s,n - m,n - 1);
	reverse(s,0,n - 1);
}

int main(int argc, char const *argv[])
{
	char a[100];
	int m = 0;
	printf("please input a string:\n");
	scanf("%s",a);
	printf("please input m:\n");
	scanf("%d",&m);
	RotateString(a,m);
	printf("%s\n", a);
	return 0;
}
