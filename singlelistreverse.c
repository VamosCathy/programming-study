#include <stdio.h>
#include <stdlib.h> //malloc()
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

LNode *InitList(void)
{
	LNode *LinkList;
	LinkList = (LNode*)malloc(sizeof(LNode));
	if (LinkList == NULL)
	{
		exit(1);
	}
	LinkList->next = NULL;
	return LinkList;
}

void DestroyList(LNode* L)
{
	LNode* q;
	while(L != NULL)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

LNode* NodeInsert(LNode* L,int e)
{
	LNode* s;
	s = (LNode*)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = L->next;
	L->next = s;
	return L;
}
LNode* Reverse(LNode* L,int from,int to)
{
	if (from >= to)
	{
		return L;
		printf("return\n");
	}
	int i = 0;//计数器
	int j = to - from;
	LNode *h,*f,*q,*r,*t;
	t = L;
	while(t && i < to)
	{
		if (i + 1 == from)
			h = t;
		t = t->next;
		i++;
		if (i == from)
			f = t;
	}
	while(j != 0)
	{
		q = f->next;
		r = q->next;
		q->next = h->next;
		h->next = q;
		f->next = r;
		j--;
	}
	return L;
}

int main(int argc, char const *argv[])
{
	int k = 0;
	LNode* L;
	L = InitList();
	for(int i = 6;i >= 1;i--)
		L = NodeInsert(L,i);
	printf("please input k:\n");
	scanf("%d",&k);
	L = Reverse(L,1,k);
	L = Reverse(L,k + 1,6);
	LNode* p = L->next;
	while(NULL != p)
	{
		printf("%d", p->data);
		p = p->next;
		printf("->");
	}
	DestroyList(L);
	return 0;
}