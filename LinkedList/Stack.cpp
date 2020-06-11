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
void PostfixConversion(char exp[]) {
	Stack stack;
	int ExpLen = strlen(exp)+1;
	char* ConvExp = (char*)malloc(ExpLen);
	
	int index = 0;
	char comparison, popOp;

	memset(ConvExp, 0, sizeof(char ) * ExpLen);
	InitStack(&stack);

	for (int i = 0; i < ExpLen; i++) {
		comparison = exp[i];
		if (isdigit(comparison)) {   //저장된값이 숫자면 T
			ConvExp[index++] = comparison;
		}
		else {
			switch (comparison) {
			case '(':
				Push(&stack, comparison); break;
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
				while (!IsEmpty(&stack) && WhoPriority(Peek(&stack), comparison) >= 0) {
					ConvExp[index++] = Pop(&stack);
				}
				Push(&stack, comparison); break;
			}
		}
	}
	while (!IsEmpty(&stack)) {
		ConvExp[index++] = Pop(&stack);
	}
	strcpy(exp, ConvExp);
	free(ConvExp);
}

int Calculate(char exp[]){
	Stack stack;
	int ExpLen = strlen(exp);
	char comparison, op1, op2;

	InitStack(&stack);

	for (int i = 0; i < ExpLen; i++) {
		comparison = exp[i];
		if (isdigit(comparison)) {
			Push(&stack, comparison - '0');
		}
		else {
			op2 = Pop(&stack);
			op1 = Pop(&stack);

			switch (comparison) {
			case '+':
				Push(&stack, op1 + op2); break;
			case '-':
				Push(&stack, op1 - op2); break;
			case '*':
				Push(&stack, op1 * op2); break;
			case '/':
				Push(&stack, op1 / op2); break;
			}
		}
	}
	return Pop(&stack);
}

void Start1() {

	char str[100];
	while (1) {
		printf("후위식 바꿀식 : ");
		fgets(str, sizeof(str), stdin);
		PostfixConversion(str);
		printf("후위식 : %s  \n", str);
		printf("후위식 계산 : %d \n\n\n", Calculate(str));
	}
	
}
