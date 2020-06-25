#include<stdio.h>
#include"Heap.h"
void HeapInit(heap* ph) {
	ph->numberofdata = 0;
}

int HeapIsEmpty(heap* ph) {
	if (ph->numberofdata == 0) {
		return true;
	}
	else {
		return false;
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
		if (ph->heapArr[GetLeftChildindex(index)].Priority >
			ph->heapArr[GetRightChildindex(index)].Priority) {
			return GetRightChildindex(index);
		}
		else {
			return GetLeftChildindex(index);
		}
	}
}

void Heapinsert(heap* ph, char data, int priority) {
	int index = ph->numberofdata + 1;
	heapElem NewHeapElem = { priority,data };
	while (index != 1) {
		if (priority < (ph->heapArr[GetParentindex(index)].Priority)) {
			ph->heapArr[index] = ph->heapArr[GetParentindex(index)];
			index = GetParentindex(index);
		}
		else {
			break;
		}
	}
	ph->heapArr[index] = NewHeapElem;
	ph->numberofdata += 1;
}

char HeapDelete(heap* ph) {
	char ResultData = (ph->heapArr[1]).data;
	heapElem lastElem = ph->heapArr[ph->numberofdata];
	int ParentIndex = 1;
	int ChildIndex;

	while (ChildIndex = GetHighPriorityindex(ph,ParentIndex)) {
		if (lastElem.Priority <= ph->heapArr[ChildIndex].Priority) {
			break;
		}
		ph->heapArr[ParentIndex] = ph->heapArr[ChildIndex];
		ParentIndex = ChildIndex;
	}
	ph->heapArr[ParentIndex] = lastElem;
	ph->numberofdata -= 1;
	return ResultData;
}

void Start3() {
	heap heap;
	HeapInit(&heap);

	Heapinsert(&heap, 'A', 9);
	Heapinsert(&heap, 'B', 8);
	Heapinsert(&heap, 'C', 7);
	Heapinsert(&heap, 'D', 6);
	Heapinsert(&heap, 'E', 5);
	while (!HeapIsEmpty(&heap)) {
		printf("입력데이터 : %c \n", HeapDelete(&heap) );
	}
}