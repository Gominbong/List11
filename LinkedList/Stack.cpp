#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
		printf("stack memory erro1r");
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
int GetPriority(char op) {
	switch (op) {
	case '*':
	case '/': return 5;
	case '+':
	case '-': return 3;
	case '(': return 1;
		
	}
	return -1;
}
int WhoPriority(char op1, char op2) {
	int op1_Priority = GetPriority(op1);
	int op2_Priority = GetPriority(op2);

	if (op1_Priority > op2_Priority) {
		return 1;
	}
	else if (op1_Priority < op2_Priority) {
		return -1;
	}
	else {
		return 0;
	}
}
void Conversion(char exp[]) {
	Stack stack;
	int ExpLen = strlen(exp)+1;
	char* ConvExp = (char*)malloc(ExpLen);
	
	int index = 0;
	char tok, popOp;

	memset(ConvExp, 0, sizeof(char ) * ExpLen);
	InitStack(&stack);

	for (int i = 0; i < ExpLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {   //저장된값이 숫자면 T
			ConvExp[index++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				Push(&stack, tok); break;
			case ')':
				while (1) {
					popOp = Pop(&stack);
					if (popOp == '(') {
						break;
					}
					ConvExp[index++] = popOp;
				} break;

			case '+':
			case '-':
			case '*':
			case '/':
				while (!IsEmpty(&stack) && WhoPriority(Peek(&stack), tok) >= 0) {
					ConvExp[index++] = Pop(&stack);
				}
				Push(&stack, tok); break;
				

			}
		}
	}
	while (!IsEmpty(&stack)) {
		ConvExp[index++] = Pop(&stack);
	}
	strcpy(exp, ConvExp);
	free(ConvExp);
	
}
void Start1() {

	char exp1[] = "6+7*3";
	char exp2[] = "6+7*2";
	char exp3[] = "(1+2)*3";
	
	Conversion(exp1);
	Conversion(exp2);
	Conversion(exp3);

	printf("%s\n", exp1);
	printf("%s\n", exp2);
	printf("%s\n", exp3);

}
