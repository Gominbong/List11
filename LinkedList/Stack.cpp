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
}
int FreeStack(Stack* stack) {
	char data;
	Node_stack* Temp;
	if (IsEmpty(stack)) {
		printf("Asd");
		return 0;
	}
	Temp = stack->top;
	data = Temp->data;
	
	stack->top = Temp->next;
	free(Temp);
	return data;

}

Node_stack* CreateNode(char* NewData) {
	Node_stack* NewNode = (Node_stack*)malloc(sizeof(Node_stack));

	NewNode->data = (char*)malloc(sizeof(strlen(NewData) + 1));
	strcpy(NewNode->data, NewData);
	NewNode->next = NULL;

	return NewNode;
}

void Start1() {
	Stack stack;
	
	InitStack(&stack);

	char num[11] = { '0','1','2','3','4','5','6','7','8','9','.', };
	enum symbol {
		LEFT_PARENTHESES = '(',
		RIGHT_PARENTHESES = ')',
		MULTIPLY = '*',
		DIVIDE = '/',
		PLUS = '+',
		MINUS = '-',
		SPACE = ' ',
		OPERAND
	};
	while (1) {
		printf("계산할 값 입력");
		
	}

	Push(&stack,'1'); 
	Push(&stack,'2');
	Push(&stack,'3');

	while (!IsEmpty(&stack)) {
		printf("asdasd%d", Pop(&stack));
	}
}
