// 00-SingleLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef struct ElemType
{
	int x;
}ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;	    
}LNode, *LinkList;


void KanList();

int _tmain(int argc, _TCHAR* argv[])
{
	KanList();
	getchar();
	return 0;
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

void KanList()
{
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
		printf("\n %d", buff->data.x);
		buff = buff->next;
	}
}

