#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

int queue[MAXSIZE];
int size = 0, rear = 0, front = 0, i=0;

int push(int data) {
	size++;
	queue[rear%MAXSIZE] = data;
	rear++;
	return 0;
}
	
int pop() {
	if(isEmpty()) return -1;
	size--;
	int result = queue[(front%MAXSIZE)];
	front++;
	return result;
}
	
int isEmpty() {
	if(size == 0)
		return 1;
	else
		return 0;
}
	
int SIZE() {
	return size;
}

int main(int argc, char *argv[]) {
	int count = 0, num;
	char input[10];
	scanf("%d", &count);
	while(count) {
		count--;
		scanf("%s", input);
		if(!strcmp(input, "push")) {
			scanf(" %d", &num);
			push(num);
		} else if(!strcmp(input, "pop")) {
			printf("%d\n", pop());
		} else if(!strcmp(input, "size")) {
			printf("%d\n", SIZE());
		} else if(!strcmp(input, "empty")) {
			printf("%d\n", isEmpty());	
		} else if(!strcmp(input, "front")) {
			if(isEmpty()) 
				printf("-1\n");
			else
				printf("%d\n", queue[front]);
		} else if(!strcmp(input, "back")) {
			if(isEmpty()) 
				printf("-1\n");
			else
				printf("%d\n", queue[rear-1]);
		}
	}
	return 0;
}
