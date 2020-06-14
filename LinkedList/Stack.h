#pragma once
#ifndef STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS



void Start1();
typedef struct node_stack {
	float data;
	struct node_stack* next;
}Node_stack;

typedef struct stack {
	Node_stack* top;
}Stack;
#endif