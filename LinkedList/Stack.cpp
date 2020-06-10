#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void InitStack(Stack* stack) {
	stack->top = NULL;
	stack->tail = NULL;
}

int IsEmpty(Stack* stack) {
	return stack->top == NULL;
}

void Push(Stack* stack, int data) {
	Node_stack* NewNode = (Node_stack*)malloc(sizeof(Node_stack));
	NewNode->data = data;
	NewNode->next = stack->top;
	stack->top = NewNode;
}

int Pop(Stack* stack) {
	int data;
	Node_stack* node;

	if (IsEmpty(stack)) {
		printf("stack memory error");
		exit(-1);
	}

	data = stack->top->data;
	node = stack->top;

	stack->top = stack->top->next;
	free(node);
	return data;
}

int Peek(Stack* stack) {
	if (IsEmpty(stack)) {
		printf("stack memory error");
		exit(-1);
	}
	return stack->top->data;
	
}

void Conversion(char exp[]) {
	Stack stack;
	int expLen = strlen(exp);
	char* ConvExp = (char*)malloc(expLen + 1);
	
	int i, index = 0;
	char tok, popOp;
}
void Start1() {

	Stack stack;
	InitStack(&stack);
	
}
