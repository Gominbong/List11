#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
BTnode* CreateBTNode() {
	BTnode* Node = (BTnode*)malloc(sizeof(BTnode));
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

int GetData(BTnode* bt) {
	return bt->data;
}

void SetData(BTnode* bt, int data) {
	bt->data = data;

}
BTnode* GetLeftSubTree(BTnode* bt) {
	return bt->left;
}

BTnode* GetRightSubTree(BTnode* bt) {
	return bt->right;
}

void CreateLeftSubTree(BTnode* maintree, BTnode* subtree) {
	if (maintree->left != NULL) {
		free(maintree->left);
	}
	maintree->left = subtree;
}

void CreateRightSubTree(BTnode* maintree, BTnode* subtree) {
	if (maintree->right != NULL) {
		free(maintree->right);
	}
	maintree->right = subtree;
}

void InorderTraverse(BTnode* bt, void(*visit)(int)) {
	if (bt == NULL) {
		return;
	}
	
	InorderTraverse(bt->left , visit);
	visit(bt->data);
	InorderTraverse(bt->right, visit);
}

void PreorderTraverse(BTnode* bt, fpShowData visit) {
	if (bt == NULL) {
		return;
	}
	visit(bt->data);
	PreorderTraverse(bt->left, visit);
	PreorderTraverse(bt->right, visit);
}

void PostorderTraverse(BTnode* bt, fpShowData visit) {
	if (bt == NULL) {
		return;
	}
	PostorderTraverse(bt->left, visit);
	PostorderTraverse(bt->right, visit);
	visit(bt->data);
}

void ShowData(int data) {
	printf("%d ", data);
}

void Start2() {
	BTnode* bt1 = CreateBTNode();
	BTnode* bt2 = CreateBTNode();
	BTnode* bt3 = CreateBTNode();
	BTnode* bt4 = CreateBTNode();
	BTnode* bt5 = CreateBTNode();
	BTnode* bt6 = CreateBTNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	CreateLeftSubTree(bt1, bt2);
	CreateRightSubTree(bt1, bt3);
	CreateLeftSubTree(bt2, bt4);
	CreateRightSubTree(bt2, bt5);
	CreateRightSubTree(bt3, bt6);

	PreorderTraverse(bt1,ShowData);
	printf("\n");
	InorderTraverse(bt1, ShowData);
	printf("\n");
	PostorderTraverse(bt1, ShowData);
}