#pragma once
#ifndef STACK_H
#define STACK_H

void Start1();
typedef struct node_stack {
	int data;
	struct node_stack* next;

}Node_stack;
typedef struct stack {
	Node_stack* top;
}Stack;

#endif