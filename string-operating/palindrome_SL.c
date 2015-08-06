//判断一条单链表是否为回文
//单链表带头结点
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	char value;
	struct ListNode* next;
}ListNode,*SingleList;

SingleList InitList(void)
{
	SingleList L;
	L = (SingleList)malloc(sizeof(ListNode));
	if (!L) //内存分配失败
	{
		printf("出错啦\n");
		FILE *fp = fopen("log.txt","a");
		fprintf(stderr, "存储空间分配失败\n");
		fclose(fp);
		exit(1);
	}
	L->next = NULL;
	return L;
}

SingleList ListInsert(SingleList L,char a){
	SingleList p;
	p = (SingleList)malloc(sizeof(ListNode));
	if (!p)
	{
		printf("出错啦\n");
		FILE *fp = fopen("log.txt","a");
		fprintf(stderr, "存储空间分配失败\n");
		fclose(fp);
		exit(1);
	}
	p->value = a;
	p->next = L->next;
	L->next = p;
	return L;
}

void ClearList(SingleList L){
	SingleList p;
	while(L != NULL){
		p = L->next;
		free(L);
		L = p;
	}
}

void outputList(SingleList L){//输出单链表所有值
	SingleList tmp;
	tmp = L->next;
	while(tmp){
		printf("%c ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int isPalindrome(SingleList L){
	SingleList p,q;
	p = L;
	q = L;
	while(p->next != NULL){
		p = p->next;
		if (p->next == NULL) //单链表中含有奇数个节点
		{
			q = q->next;
			break;
		}
		else{
			p = p->next;
			q = q->next;
		}

	}
	//逆置单链表后半段——头插法
	SingleList tmp;
	while(q->next != p){
		tmp = q->next;
		q->next = tmp->next;
		tmp->next = p->next;
		p->next = tmp;
	}
	outputList(L);

	//从链表头和中间进行对比
	p = L->next; //p从链表头开始
	q = q->next; //q从链表后半部分开始
	while(q != NULL){
		if(p->value != q->value)
			return 0;
		q = q->next;
		p = p->next;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	SingleList sl;
	char input[100];
	printf("请输入字符串：\n");
	scanf("%s",input);
	// printf("%s\n", input);
	if (input[0] == '\0')
	{
		exit(1);
	}
	sl = InitList();
	int i = 0;
	while(input[i]){
		ListInsert(sl,input[i]);
		i++;
	}
	outputList(sl);
	int flag;
	flag = isPalindrome(sl);
	if(flag == 1)
		printf("yes\n");
	else
		printf("no\n");
	ClearList(sl);
	return 0;
}