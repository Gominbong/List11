#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
Node* Head = (Node*)malloc(sizeof(Node));
Node* Tail = (Node*)malloc(sizeof(Node));
Node* Temp = NULL;
Node* Temp1 = NULL;
int a = 50;
void InitList() {
	Head->next = Tail;
	Tail->next = NULL;
	Tail->data = NULL;
}

void DelBetween() {
	int index = 0;
	int i = 0;
	if (Head->next != Tail) {
		printf("삭제할 위치 : ");
		scanf_s("%d", &index);
		if (Head->next != Tail) {
			Temp = Head;
			while (Temp->next != Tail) { 
				if (Temp->next->next == Tail) {
					Temp1 = Temp->next;
					Temp->next = Tail;
					printf("\n\n%d번 인덱스 %d   삭제완료\n\n\n", index, Temp1->data);
					system("pause");
					free(Temp1);
					break;
				}
				if (i==index) {
					Temp1 = Temp->next;
					Temp->next = Temp->next->next;
					printf("\n\n%d번 인덱스 %d   삭제완료\n\n\n", index, Temp1->data);
					system("pause");
					free(Temp1);
					break;
				}
				i++;
				Temp = Temp->next;
			}
		}
		else {
			printf("\n\n사이에추가할데이터없음\n\n\n");
			system("pause"); return;
		}
	}
}

void DelFirst() {
	if (Head->next != Tail) {
		Temp1 = Head->next;
		Head->next = Head->next->next;
		free(Temp1);
		printf("\n\n맨앞삭제완료\n\n\n");
		system("pause"); 
	}
	else {
		puts("\n\n삭제할거없음\n\n\n");
		system("pause"); return;
	}

}
void DelLast() {
	
	if (Head->next != Tail) {
		Temp = Head;
		while (1) {
			if (Temp->next->next == Tail) {
				Temp1 = Temp->next;
				Temp->next = Tail;
				free(Temp1);
				puts("\n\n맨뒤삭제완료\n\n\n");
				system("pause");
				break;
			}
			else {
				Temp = Temp->next;
			}
		}
		
	}else {
		puts("\n\n삭제할거없음\n\n\n");
		system("pause"); return;
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
		printf("\n\n사이에추가할데이터없음\n\n\n");
		system("pause"); return;
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
		printf("\n\n%d 추가완료\n\n\n", Number);
		printf("\n\n%d 추가완료\n\n\n", Number);
		system("pause");
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
		
		printf("\n\n%d 추가완료\n\n\n", Number);
		system("pause");
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

		printf("\n\n%d 추가완료\n\n\n", Number);
		system("pause");
	}
}
void InsertSort(int size) {
	Node* cur = Head->next;
	Node* insert;
	int Swap;
	while(!cur->next==NULL){
		insert = Head->next;
		while (1) {

			if (insert== cur) {
				break;
			}

			if (insert->data > cur-> data) {
				Swap = insert->data;
				insert->data = cur->data;
				cur->data = Swap;
			}
			insert = insert->next;
		}
		cur = cur->next;
	
	}

	printf("\n\n");
	while (Temp->next!=Tail) {
		printf("%d\n", Temp->next->data);
		Temp = Temp->next;
	}

	system("pause");
	printf("\n");
}
void BubbleSort(int size) {
	int Swap;
	Node* jNode;
	int index = 0;
	printf("\n\n");

	for (int i = 0; i < size - 1; i++) {
		jNode = Head->next;
		for (int j = 0; j < size - (i + 1); j++) {
			if (jNode->data > jNode->next->data) {
				Swap = jNode->data;
				jNode->data = jNode->next->data;
				jNode->next->data = Swap;
			}
			jNode = jNode->next;
		}
	}
	Temp = Head;
	while (Temp->next != Tail) {
		printf("%d번index:%d\t", index, Temp->next->data);
		Temp = Temp->next;
		index++;
		if (index % 7 == 0) printf("\n");
	}
	system("pause");
	printf("\n");
}
void SelectSort(int size) {
	Node* KeyNode=Head->next;
	Node* NextNode;
	Node* MinNode;
	int Swap;
	int index = 0;
	printf("\n\n");
	
	for (int i = 0; i < size-1; i++) {
		NextNode = KeyNode->next;
		MinNode = KeyNode;
		for (int j = i + 1; j < size; j++) {
			if (MinNode->data > NextNode->data) {
				MinNode = NextNode;
			}
			NextNode = NextNode->next;
		}
		Swap = MinNode->data;
		MinNode->data = KeyNode->data;
		KeyNode->data = Swap;

		KeyNode = KeyNode->next;
	}

	Temp = Head;
	while (Temp->next != Tail) {
		printf("%d\n", Temp->next->data);
		Temp = Temp->next;
	}

	system("pause");
	printf("\n");
}
void Print() {
	if (Head->next == Tail) {
		printf("\n\n입력된 데이터 없음\n\n\n");
		
		system("pause"); return;
	}
	int size =sizeof(Node);
	size = size / size;
	int index = 0;
	Temp = Head;
	while (Temp->next != Tail) {
		size = size + 1;
		printf("%d번index:%d\t", index, Temp->next->data);
		Temp = Temp->next;
		index++;
		if (index % 7 == 0) printf("\n");
	}
	--size; 
	int n;
	printf("\n\n\n\n\n1. 뒤로가기 2. 선택 정렬 3. 삽입 정렬 4. 버블 정렬 5. 병합 정렬 6. 퀵 정렬 \n\n");
	scanf_s("%d", &n);
		switch (n) {
		case 1:  break;
		case 2: SelectSort(size); break;
		case 3: InsertSort(size);  break;
		case 4: BubbleSort(size); break;
		case 5: break;
		case 6: break;
		default: break;
		}
}
void Start() {
	InitList();
	int n;
	while (1) {
		system("cls");
		puts("리스트\n");
		puts("1. 추가 ");
		puts("2. 삭제");
		puts("3. 출력");
		puts("4. 종료 ");
		printf("\n\n번호 입력 : ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			while (1) {
				system("cls");
				puts("1. 맨앞추가");
				puts("2. 사이에추가");
				puts("3. 맨뒤추가");
				puts("4. 뒤로가기");
				puts("5. 종료");
				printf("\n\n번호입력 : ");
				scanf_s("%d", &n);
				switch (n) {
				case 1: AddFirst(); break;
				case 2: AddBetween(); break;
				case 3: AddLast(); break;
				case 4: break;
				case 5: exit(0);
				default: printf("\n1~5사이 입력.\n\n"); system("pause"); continue;
				}
				break;
			}
			break;
		case 2:
			while (1) {
				system("cls");
				puts("1. 맨앞삭제");
				puts("2. 맨뒤삭제");
				puts("3. 인덱스기준삭제");
				puts("4. 뒤로가기");
				puts("5. 종료");
				printf("번호 입력 : ");
				scanf_s("%d", &n);
				switch (n) {
				case 1: DelFirst(); break;
				case 2: DelLast(); break;
				case 3: DelBetween(); break;
				case 4: break;
				case 5: exit(0);
				default: printf("\n1~5사이 입력.\n\n"); system("pause"); continue;
				}
				break;
			}
			break;
		case 3:
			system("cls");
			Print();
			break;
		case 4: exit(0);
		default: printf("\n1~4사이 입력.\n\n"); system("pause"); continue;
		}
	}
}