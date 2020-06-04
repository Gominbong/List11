#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>
void InitStack(Stack* stack) {
	stack->top = NULL;
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


void Start1() {
	Stack stack;
	
	InitStack(&stack);

	while (1) {
		puts("1. 스택추가 ");
		puts("2. 스택 ");
		puts("3. 스택출력 ");
		puts("4. 종료 : ");
	}

	Push(&stack,1); 
	Push(&stack,2);
	Push(&stack,3);

	while (!IsEmpty(&stack)) {
		printf("asdasd%d", Pop(&stack));
	}
}
