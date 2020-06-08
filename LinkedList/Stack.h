#pragma once
#ifndef STACK_H
#define STACK_H
void Start1();
typedef struct node_stack {
	char* data;
	struct node_stack* next;
}Node_stack;

typedef struct stack {
	Node_stack* top;
	Node_stack* tail;
}Stack;


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

#endif