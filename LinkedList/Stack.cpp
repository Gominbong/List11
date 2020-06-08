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

void Push(Stack* stack, Node_stack* NewNode) {
	if (stack->top == NULL) {
		stack->top = NewNode;
	}
	else {
		stack->tail->next = NewNode;
	}
	stack->tail = NewNode;
	
}
Node_stack* Pop(Stack* stack) {
	Node_stack* PopNode = stack->tail;

	if (stack->top == stack->tail) {
		stack->top = NULL;
		stack->tail = NULL;
	}
	else {
		Node_stack* current = stack->top;
		while (current->next != PopNode) {
			current = current->next;
		}
		stack->tail = current;
		stack->tail->next = NULL;
	}
	return PopNode;
}
void FreeStack(Stack* stack ) {
	while (!IsEmpty(stack)) {
		Node_stack* PopNode = Pop(stack);
		free(PopNode->data);
		free(PopNode);
	}
}
Node_stack* GetTop(Stack* stack) {
	return stack->tail;
}
bool isEmpty(Stack* stack) {
	return (stack->top == NULL && stack->tail == NULL);
}

Node_stack* CreateNode(char* NewData) {
	Node_stack* NewNode = (Node_stack*)malloc(sizeof(Node_stack));

	NewNode->data = (char*)malloc(sizeof(strlen(NewData) + 1));
	strcpy_s(NewNode->data,8, NewData);
	NewNode->next = NULL;

	return NewNode;
}

unsigned int GetPriority(char op, int inStack) {
	unsigned int priority = -1;
	switch (op) {
	case LEFT_PARENTHESES:
		if (inStack) {
			priority = 3;
		}
		else {
			priority = 0;
		} break;
	case MULTIPLY:
	case DIVIDE:
		priority = 1; break;
	case PLUS:
	case MINUS:
		priority = 2; break;
	}
	return priority;
}

bool IsPrior(char op1, char op2) {
	return (GetPriority(op1, 1) < GetPriority(op2, 0));
}

bool IsNum(char c) {
	for (int i = 0; i < 11; i++) {
		if (num[i] == c) {
			return true;
		}
	}
	return false;
}
void Start1() {
	Stack stack;
	
	InitStack(&stack);

}
