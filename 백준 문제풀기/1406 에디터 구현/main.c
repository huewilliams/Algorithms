#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 이중연결리스트로 구현함 

typedef struct node {
	struct node * next;
	struct node * prev;
	char c; // 문자 데이터 
}Node;

Node *newNode(char input)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->c = input;
	newNode->prev = newNode->next = NULL;
	return newNode;	
}

typedef struct list { //연결리스트 정의 
	Node * head;
	Node * tail;
	Node * cur;	
}List;

void ListInit(List * list);
void LPush(List * list, char input);
void LPop(List * list);
void Lleft(List * list);
void LRight(List * list);
void LPrint(List * list);

int main(int argc, char *argv[]) {
	char str[500000]; // 텍스트  
	char command[100000]; // 명령어 
	
	int count = 0, i, j = -1;
	char temp, word;
	
	List list;
	ListInit(&list);
	scanf("%s", str);  
	for(i = 0; i < strlen(str); i++)
	{
		LPush(&list, str[i]);
	}
	scanf("%d", &count); // 명령어 수
	for(i = 0; i < count; i++)
	{
		scanf(" %c", &temp);
		command[++j] = temp;
		if(temp == 'P')
		{
			scanf(" %c", &word);
			command[++j] = word;
		}
	}
	count = ++j;
	for(i = 0; i < count; i ++) {
		if(command[i] == 'P') {
			LPush(&list, command[++i]);
		} else if(command[i] == 'L') {
			Lleft(&list);			
		} else if(command[i] == 'D') {
			LRight(&list);
		} else if(command[i] == 'B'){
			LPop(&list);
		}
	}
	LPrint(&list);
}

void ListInit(List * list) {
	list->head = newNode('0');
	list->tail = newNode('0');
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->cur = list->tail;
}

void LPush(List * list, char input) {
	Node * NewNode = newNode(input);
	NewNode->prev = list->cur->prev;
	NewNode->next = list->cur;
	list->cur->prev->next = NewNode;
	list->cur->prev = NewNode;
}

void LPop(List * list) {
	if(list->cur->prev != list->head) {
		Node * now = list->cur->prev;
		now->prev->next = now->next;
		now->next->prev = now->prev;
		free(now);
	}
}

void Lleft(List * list) {
	Node * now = list->cur;
	if(now->prev != list->head)
		list->cur = now->prev;	
}

void LRight(List * list) {
	Node * now = list->cur;
	if(now != list->tail)
		list->cur = now->next;
}

void LPrint(List * list) {
	Node * now = list->head->next;
	while(1) {
		if(now == list->tail)
			break;
		printf("%c", now->c);
		now = now->next;
	}
	printf("\n");
}
