#pragma once
#ifndef TREE_H
#define TREE_H
void Start2();
typedef struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
} BTnode;
typedef void (*fpShowData)(int);

#endif