#pragma once
#ifndef HEAP_H
#define HEAP_H
#define TRUE 1
#define FALSE 0
void Start3();

typedef int PriorityComp(char d1, char d2);

typedef struct Heap {
	PriorityComp* comp;
	int numberofdata;
	char heapArr[100];
}heap;

#endif

