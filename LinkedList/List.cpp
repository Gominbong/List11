#include"List.h"
#include<stdio.h>
#include<stdlib.h>
Node* Head = (Node*)malloc(sizeof(Node));
Node* Tail = (Node*)malloc(sizeof(Node));
Node* Temp = NULL;
Node* Temp1 = NULL;
void Init() {
	Head->next = Tail;
	Tail->next = NULL;
	Tail->data = NULL;
}
void DelFirst() {
	if (Head->next != Tail) {
		Temp1 = Head->next;
		Head->next = Head->next->next;
		printf("%p\n", Temp1->next);
		printf("%p\n,", Temp1);
		free(Temp1);
		//printf("%p\n", Temp1->next);
		printf("%p\n,", Temp1);
		printf("\n\n맨앞삭제완료\n\n\n");
		system("pause");
	}
	else {
		system("cls");
		printf("\n\n");
		puts("삭제할거없음");
		printf("\n\n");
		system("pause");
	}

}
void DelLast() {
	if (Head->next != Tail) {

	}
	else {
		puts("삭제할거없음");
	}
}
void AddBetween() {
	int Number = 0;
	int index = 0;
	int i = 0;

	if (Head->next != Tail) {
		printf("숫자 입력 : ");
		scanf_s("%d", &Number);
		printf("삽입할 위치 : ");
		scanf_s("%d", &index);
	}
	else {
		printf("\n\n사이에추가할데이터없음\n \n");
		system("pause");
	}

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head;
		while (Temp->next != Tail) {
			if (index == i) {
				NewNode->next = Temp->next->next;
				Temp->next->next = NewNode;
			}
			Temp = Temp->next;
			i++;
		}
	}

}
void AddFirst() {
	int Number = 0;
	printf("숫자 입력 :  ");
	scanf_s("%d", &Number);

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head->next;
		Head->next = NewNode;
		NewNode->next = Temp;
	}
}
void AddLast() {
	int Number = 0;
	printf("숫자 입력 : ");
	scanf_s("%d", &Number);

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head;
		while (Temp->next != Tail) {
			Temp = Temp->next;
		}
		Temp->next = NewNode;
		NewNode->next = Tail;
	}
}
void Print() {
	if (Head->next == Tail) {
		printf("\n\n입력된 데이터 없음\n");
	}
	int index = 0;
	Temp = Head;
	while (Temp->next != Tail) {

		printf("%d번index:%d\t", index, Temp->next->data);
		Temp = Temp->next;
		index++;
		if (index % 7 == 0) printf("\n");
	}
}


void Start() {
	Init();
	int n;
	while (1) {
		system("cls");
		puts("리스트");
		puts("1. 추가 ");
		puts("2. 삭제");
		puts("3. 출력");
		puts("4. 종료 ");
		printf("번호 입력 : ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			system("cls");
			puts("1. 맨앞추가");
			puts("2. 사이에추가");
			puts("3. 맨뒤추가");
			puts("4. 종료");
			printf("번호입력 : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: AddFirst(); break;
			case 2: AddBetween(); break;
			case 3: AddLast(); break;
			case 4: exit(0);
			default: exit(0);
			}
			break;
		case 2:
			system("cls");
			puts("1. 맨앞삭제");
			puts("2. 맨뒤삭제");
			puts("3. 인덱스기준삭제");
			puts("4. 종료");
			printf("번호 입력 : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: DelFirst(); break;
			case 2:
			case 3:
			case 4: exit(0);
			default: exit(0);
			}

			break;
		case 3:
			system("cls");
			Print();
			printf("\n\n");
			system("pause");
			break;
		case 4:
			exit(0);
		case 5:
			printf("%p\n", Temp1->next);
			system("pause");
			break;
		default:
			exit(0);
		}
	}


}