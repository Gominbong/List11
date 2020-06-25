#pragma once
#ifndef HEAP_H
#define HEAP_H
#define TRUE 1
#define FALSE 0
void Start3();
typedef struct HeapElem {
	int Priority;
	char data;
} heapElem;

typedef struct Heap {
	int numberofdata;
	heapElem heapArr[100];
}heap;

#endif

