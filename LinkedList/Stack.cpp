#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void InitStack(Stack* stack) {
	stack->top = NULL;
}

int IsEmpty(Stack* stack) {
	if (stack->top == NULL)
		return true;
	else
		return false; 
}

void Push(Stack* stack, float data) {
	Node_stack* NewNode = (Node_stack*)malloc(sizeof(Node_stack));
	NewNode->data = data;
	NewNode->next = stack->top;
	stack->top = NewNode;
}

float Pop(Stack* stack) {
	float data;
	Node_stack* node;

	if (IsEmpty(stack)) {
		printf("stack memory erro1r");
		exit(-1);
	}
	data = stack->top->data;
	node = stack->top;

	stack->top= stack->top->next;
	free(node);
	return data;
}

int Peek(Stack* stack) {
	if (IsEmpty(stack)) {
		printf("stack memory error");
		exit(-1);
	}
	if (stack->top->data == '(') {
		return 0;
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
	else{
		return 0;
	}
}

void PostfixConversion(char exp[]) {
	Stack stack;
	int ExpLen = strlen(exp)+1;
	int count=0;
	for (int i = 0; i <ExpLen; i++) {
		if (exp[i]=='+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i]=='(' || exp[i] ==')' ) {
			count += 2;
		}
	}
	ExpLen = ExpLen + count;
	char* ConvExp = (char*)malloc(ExpLen);
	int index = 0;
	char comparison, popOp;
	int flag = 1;
	memset(ConvExp, 0, sizeof(char ) * ExpLen);
	InitStack(&stack);
	for (int i = 0; i < ExpLen - count; i++) {
		comparison = exp[i];
		if (isdigit(comparison)) {   //저장된값이 숫자면 T
			ConvExp[index++] = comparison;
		}
		else{
		     if ( comparison== '(' ) {
				ConvExp[index++] = ' ';
				Push(&stack, comparison);
             }		
			switch (comparison) {
			case ')':
				if (stack.top->data = ')') {
					ConvExp[index++] = '*';
					Pop(&stack);
					flag = 0;
					break;
				}

				while (flag) {
					popOp = Pop(&stack);
					
					if (popOp == '(') {
						ConvExp[index++] = ' ';
						break;
					}
					
					ConvExp[index++] = ' ';
					ConvExp[index++] = popOp;
				} break;
			
			case '+':
			case '-':
			case '*':
			case '/':
				while (!IsEmpty(&stack) && WhoPriority(Peek(&stack), comparison) >= 0) {
					ConvExp[index++] = ' ';
					ConvExp[index++] = Pop(&stack);
				}
				ConvExp[index++] = ' ';
				Push(&stack, comparison);
				break;
			}
		}
	}
	while (!IsEmpty(&stack)) {
		ConvExp[index++] = Pop(&stack);
	}
	strcpy(exp, ConvExp);
	printf("%d", strlen(exp));
	free(ConvExp);
}

float Calculate(char exp[]) {
	Stack stack;
	int ExpLen = strlen(exp);
	char comparison;
	float op1=0, op2=0;
	InitStack(&stack);
	char b[100];
	int k = 0;
	int num = 0;
	
	for (int i = 0; i<ExpLen; i++) {
		comparison = exp[i];
		if (isdigit(comparison)) {
			b[k++] = exp[i];
			if (exp[i + 1] == ' ') {
				Push(&stack, atof(b));
				memset(b, 0, 100);
				k = 0;
				i++;
			}
			else if ( !isdigit(exp[i + 1]) ) {
				Push(&stack, atof(b));
					memset(b, 0, 100);
					k = 0;
			}
		}
		else if (exp[i]==' ') {
			Push(&stack, atof(b));
			memset(b, 0, 100);
			k = 0;
		}
    	else{
			
			op2 = Pop(&stack);
			op1 = Pop(&stack);

			switch (comparison) {
			case '+':
				Push(&stack, op1 + op2); while(exp[i+1] == ' ') { i++; } break;
			case '-':
				Push(&stack, op1 - op2); while (exp[i + 1] == ' ') { i++; } break;
			case '*':
				Push(&stack, op1 * op2); while (exp[i + 1] == ' ') { i++; } break;
			case '/': 
				Push(&stack, op1 / op2); while (exp[i + 1] == ' ') { i++; } break;
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
		printf("후위식 계산 : %f \n\n\n", Calculate(str));
	}
}
