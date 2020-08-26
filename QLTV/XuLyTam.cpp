#include "XuLyTam.h"

void taoTempL(ListTL &l) {
	l.pHead = l.pTail = NULL;
}

NodeTL* GetNodeTempL(int index, int MADG) {
	NodeTL *p = new NodeTL;
	if (p == NULL) {
		return NULL;
	}
	p->tl.index = index;
	p->tl.MADG = MADG;
	p->pNext = NULL;
	return (p);
}

void themCuoiListTL(ListTL &l, int index, int MADG) {
	// tao Node
	NodeTL *p = GetNodeTempL(index, MADG);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;

	}
}

NodeTL * getMid(NodeTL *start, NodeTL *last) {
	if (start == NULL)
		return NULL;
	NodeTL * slow = start;
	NodeTL * fast = start->pNext;

	while (fast != last) {
		fast = fast->pNext;
		if (fast != last) {
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}

NodeTL * BSort_TempL(ListTL l, int index) {
	NodeTL *start = l.pHead;
	NodeTL *last = NULL;
	do {	
		NodeTL * mid = getMid(start, last);
		if (mid == NULL)
			return NULL;
		if (mid->tl.index == index)
			return mid;
		else if (mid->tl.index < index)
			start = mid->pNext;
		else
			last = mid;
	} while (last == NULL || last->pNext != start);
	return NULL; 
}

void xoaTempL(ListTL &l) {
	NodeTL *p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}