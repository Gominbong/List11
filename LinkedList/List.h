#pragma once
#ifndef LIST_H
#define LIST_H
void Start();
typedef struct node {
	int data;
	struct node* next;

}Node;
typedef struct Stack {
	Node* top;
}stack;

#endif