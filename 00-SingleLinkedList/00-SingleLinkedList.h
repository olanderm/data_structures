#pragma once

typedef struct ElemType
{
public:
	ElemType(){};
	ElemType(int x1){x = x1;}
	int x;
}ElemType;

typedef struct LNode{
public:
	LNode(){}
	LNode(int x){data.x = x;}

	ElemType data;
	struct LNode *next;	    
}LNode, *LinkList;


LinkList KanList();
LinkList SingleListTailCreate();
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, ElemType e);
LinkList InsertElemAt(LinkList L, LNode *newElem, int insertPos);
LinkList DeleteElem(LinkList L, int deletePos);
void PrintList(LinkList L);