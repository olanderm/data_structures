#include "01-DoubleLinkedList.h"

void DLinkInsert(DLinklist L, DNode *s, int pos)
{
	//����next������prior����֤˳�š����Ų�����
	DNode *p;//���ҵ�ǰ�����
	s->next = p->next;	//�����ĺ��
	p->next->prior = s;	//��̽��� prior
	s->prior = p;
	p->next = s;
}

void DLinkDeleteAt(DLinklist L)
{
	DNode *p;//���ҵ�ǰ�����
	DNode *c;  //��̽��
	p->next = c;
	c->prior = p;
}