#pragma once
#include "00-SingleLinkedList.h"

typedef struct DNode
{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinklist;

void DLinkInsert(DLinklist L, int pos);