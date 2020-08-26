#include "Temp.h"

void initTempList(tempList &l) {
	l.n = NULL;
}

void themTempList(tempList &l, int index, int MADG) {
	l.tl[l.n].index = index;
	l.tl[l.n].maDG = MADG;
	l.n++;
}

// ne su dung tim kiem tuyen tinh vi cai nao cung bigO(n)
TEMP *binarySearch(tempList l, int index)
{
	int last = l.n;
	int start = 0;
	TEMP*p;
	do
	{	//Find middle
		int mid = start + (last - start)/2 ;
		// if middle is empty
		if (mid == 0)
			return NULL;

		// if value is present at middle
		if (l.tl[mid].index == index) {
			p = &l.tl[mid];
			return p;
		}
			//return l.tl[mid];
		// if value is more than mid
		else if (l.tl[mid].index < index)
			start = mid + 1;
		// if value is less than mid
		else
			last = mid;
	} while (last == 0 || last == start);
	return NULL; // value not present;
}

void xoaTempList(tempList &l) {
	TEMP *p;
	while (l.n != 0)
	{
		p = &l.tl[l.n--];
		delete  p;
	}
}