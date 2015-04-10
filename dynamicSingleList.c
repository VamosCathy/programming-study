/*来源：单链表维基百科：http://zh.wikipedia.org/wiki/单向链表 */

//存储结构
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//带有头节点的静态单链表基本操作
void InitList(LinkList L)
{//操作结果：构造一个空的线性表
	*L = (LinkList)malloc(sizeof(struct LNode));//产生头节点，并使L指向此头节点
	if (!*L)//存储分配失败
		exit(OVERFLOW);
	(*L)->next = NULL;//指针域为空
}

void DestroyList(LinkList *L)
{//初始条件：线性表L已存在。操作结果：销毁线性表L
	LinkList q;//建立一个指向线性表的指针
	while(*L){
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}

void ClearList(LinkList L)
{//将L置为空表
	LinkList q;
	p = L->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

Status ListEmpty(LinkList L)
{//查看L是否为空
	return L->next == NULL;
}

int LIstLength(LinkList L)
{//返回L中数据元素的个数
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L,int i,ElemType *e)
{//返回第i个节点的元素值
	int j = 1;//j为计数器
	LinkList p = L->next;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{//compare()为数据元素判定函数（满足为1，否则为0），返回L中第一个雨e满足关系compare()的元素的位置
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if(compare(p->data,e))
		{
			return i;
		}
	}
	return 0;
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
{//返回数据元素cur_e的前驱
	LinkList q,p = L->next;
	while(p->next)
	{
		q = p->next;//q为后继
		if (q->data == cur_e)
		{
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return INFEASIBLE;
}

Status ListInsert(LinkList L,int i,ElemType e)
{//在L中第i个位置之前插入元素e
	int j = 0;
	LinkList p = L,s;
	while(p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList L,ElemType *e,int i)
{
	int j = 0;
	LinkList p = L,q;
	while(p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) //删除位置不合理
		return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}