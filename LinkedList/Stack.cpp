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
	case '*':return 5;
	case '/': return 5;
	case '+':return 3;
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
		if (exp[i]=='+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			count += 2;
		}
	}
	ExpLen = ExpLen + count;
	char* ConvExp = (char*)malloc(ExpLen);
	int index = 0;
	char comparison, popOp;

	memset(ConvExp, 0, sizeof(char ) * ExpLen);
	InitStack(&stack);
	for (int i = 0; i < ExpLen-count; i++) {
		comparison = exp[i];
		if (isdigit(comparison)) {   //저장된값이 숫자면 T
			ConvExp[index++] = comparison;
		}
		else {
			//ConvExp[index++] = ' ';
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
				while (!IsEmpty(&stack) && WhoPriority(Peek(&stack), comparison) > 0) {
					ConvExp[index++] = Pop(&stack);
				}
				
				Push(&stack, comparison);
			
				break;
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

	printf("%d", ExpLen);
	char comparison, op1, op2;

	InitStack(&stack);
	char temp[10];
	char* temp1;
	char a[10];
	char b[100];
	int j = 0;
	int num = 0;
	for (int i = 0; i < ExpLen; i++) {
		//숫자 아스키인지 판단
		
		if (exp[i]==' ') {
			//공백이면.
			//저장한 값들을 가지고 값을 만들어서 atoi로 정수값으로 만듬.
			num = atoi(b);
			//b배열 초기화.
			j = 0;
		}
		else if (exp[i] >= '0' || exp[i] <= '9')
		{
			b[j] = exp[i];
			j++;
			continue;
		}
		else {
			comparison = exp[i];
		}
		//comparison = exp[i];
		
		//if (isdigit(comparison)) {
//			a[i] = comparison;
		//if ( isdigit(num))
		if ( num>=0 )
		{		

			//Push(&stack, comparison - '0');
			Push(&stack, num);
			num = -1;
		}
		else {
			op2 = Pop(&stack);
			op1 = Pop(&stack);

			switch (comparison) {
			case '+':
				printf("asdasd");
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
