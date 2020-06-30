#include<stdio.h>
#include"Heap.h"
int DataPriorityComp(char ch1, char ch2);

void HeapInit(heap* ph, PriorityComp pc) {
	ph->numberofdata = 0;
	ph->comp = pc;
}

int HeapIsEmpty(heap* ph) {
	if (ph->numberofdata == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int GetParentindex(int index) {
	return index / 2;
}

int GetLeftChildindex(int index) {
	return index * 2;
}

int GetRightChildindex(int index) {
	return GetLeftChildindex(index) + 1;
}

int GetHighPriorityindex(heap* ph, int index) {
	if (GetLeftChildindex(index) > ph->numberofdata) {
		return 0;
	}
	else if (GetLeftChildindex(index) == ph->numberofdata) {
		return GetLeftChildindex(index);
	}
	else {
		if (ph->comp(ph->heapArr[GetLeftChildindex(index)], 
			ph->heapArr[GetRightChildindex(index)]) < 0) {
			return GetRightChildindex(index);
		}
		else {
			return GetLeftChildindex(index);
		}
	}
}

void Heapinsert(heap* ph, char data) {
	int index = ph->numberofdata + 1;

	while (index != 1) {
		if (ph->comp(data, ph->heapArr[GetParentindex(index)]) > 0) {
			ph->heapArr[index] = ph->heapArr[GetParentindex(index)];
			index = GetParentindex(index);
		}
		else {
			break;
		}
	}
	ph->heapArr[index] = data;
	ph->numberofdata += 1;

}

char HeapDelete(heap* ph) {
	char ResultData = ph->heapArr[1];
	char LastElem = ph->heapArr[ph->numberofdata];
	int Parentindex = 1;
	int Childindex;

	while (Childindex = GetHighPriorityindex(ph, Parentindex)) {
		if (ph->comp(LastElem, ph->heapArr[Childindex]) >= 0) {
			break;
		}
		ph->heapArr[Parentindex] = ph->heapArr[Childindex];
		Parentindex = Childindex;
	}
	ph->heapArr[Parentindex] = LastElem;
	ph->numberofdata -= 1;
	return ResultData;
}

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;
}

void Start3() {
	heap heap;
	HeapInit(&heap,DataPriorityComp);

	Heapinsert(&heap, 'A');
	Heapinsert(&heap, 'B');
	Heapinsert(&heap, 'C');
	Heapinsert(&heap, 'A');
	Heapinsert(&heap, 'B');
	Heapinsert(&heap, 'C');


	while (!HeapIsEmpty(&heap)) {
		printf("입력데이터 : %c \n", HeapDelete(&heap) );
	}
}