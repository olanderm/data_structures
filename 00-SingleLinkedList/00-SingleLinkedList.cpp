// 00-SingleLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "00-SingleLinkedList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	KanList();
	LinkList mylist = SingleListTailCreate();
	//测试查询第三序号的值
	LNode *mysearch = GetElem(mylist, 3);
	printf("\n测试查询第三序号的值 : %d", mysearch->data.x);
	mysearch = GetElem(mylist, 0);
	printf("\n测试查询第一序号的值 : %d", mysearch->data.x);
	mysearch = LocateElem(mylist, ElemType(9));
	printf("\n测试值9 : %d", mysearch->data.x);

	LNode *newElem = new LNode(999);
	printf("\n测试在第一个节点后面插入999 :");
	InsertElemAt(mylist, newElem, 1);
	PrintList(mylist);
	DeleteElemAt(mylist, 1);
	printf("\n测试删除第一个节点 :");
	PrintList(mylist);
	getchar();
	return 0;
}

void PrintList(LinkList L)
{
	LNode *buff = L->next;
	while (buff != NULL)	//注意这个地方别再写->next 否则会少打印一个
	{
		printf("\t %d", buff->data.x);
		buff = buff->next;
	}
}

///头插法建立链表
/* 输出结果
9
8
7
6
5
4
3
2
1
0
*/

LinkList KanList()
{
	printf("\n 头插法");
	LNode *header = new LNode;
	header->next = NULL;

	for (int i = 0; i < 10; i++)
	{
		LNode *node = new LNode;
		node->data.x = i;

		node->next = header->next;
		header->next = node;
	}

	LNode *buff = header->next;
	while (buff != NULL)	//注意这个地方别再写->next 否则会少打印一个
	{
		printf("\t %d", buff->data.x);
		buff = buff->next;
	}

	return header;
}

///	尾插法建立单链表
/// 关键结点是尾节点
LinkList SingleListTailCreate()
{
	printf("\n 以下是尾插法");
	LNode *header = new LNode;
	header->next = NULL;
	LNode *tail = header;
	for (int i = 0; i < 10; i++)
	{
		LNode *node = new LNode;	
		node->data.x = i;//构造结点数据元素

		tail->next = node;
		tail = node;
	}
	tail->next =NULL;

	LNode *buff = header->next;
	while (buff != NULL)	//注意这个地方别再写->next 否则会少打印一个
	{
		printf("\t %d", buff->data.x);
		buff = buff->next;
	}

	return header;
}

///按序号查找结点值
///L 代表头结点，头结点通常不存储数据。	
/// i 是序号，从0开始技术, 从头结点开始计数,头结点为0
LNode *GetElem(LinkList L, int i)
{
	//这个地方应该先判断L是否有效，i必须 >= 0
	if (L == NULL || i < 0)
	{
		return NULL;
	}
	if (i == 0)
	{
		return L;
	}

	int j = 1; //计数。其实在节点里面保存序号，可能更好

	LNode *p = L->next;
	while(p != NULL && j != i)//序号相等直接退出程序
	{
		j++;
		p = p->next;
	}
	return p;//没有查询到，超出范围	   
}

///按值去查询
LNode *LocateElem(LinkList L, ElemType e)
{
	//这个地方应该先判断L是否有效，i必须 >= 0
	if (L == NULL)
	{
		return NULL;
	}

	LNode *p = L->next;
	while(p != NULL && e.x != p->data.x)//从头查询到尾部
	{
		p = p->next;
	}
	return p;//没有查询到，超出范围
}

///insertPos必须大于0
LinkList InsertElemAt(LinkList L, LNode *newElem, int insertPos)
{
	if (insertPos <= 0)
	{
		return L;
	}
	//查找前驱节点
	LNode *p = GetElem(L, insertPos-1);
	newElem->next = p->next;
	p->next = newElem;
	return L;
}

///deletePos必须大于0
LinkList DeleteElemAt(LinkList L, int deletePos)
{	 
	
	LNode * pre = GetElem(L, deletePos-1);//找到前驱
	LNode *deleted = pre->next;
	LNode *post = deleted->next;//后继节点
	pre->next = post;
	delete deleted; 
	return L;
}