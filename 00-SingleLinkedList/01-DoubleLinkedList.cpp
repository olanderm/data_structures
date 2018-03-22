#include "01-DoubleLinkedList.h"

void DLinkInsert(DLinklist L, DNode *s, int pos)
{
	//两个next，两个prior，保证顺着、倒着不断链
	DNode *p;//先找到前驱结点
	s->next = p->next;	//插入点的后继
	p->next->prior = s;	//后继结点的 prior
	s->prior = p;
	p->next = s;
}

void DLinkDeleteAt(DLinklist L)
{
	DNode *p;//先找到前驱结点
	DNode *c;  //后继结点
	p->next = c;
	c->prior = p;
}