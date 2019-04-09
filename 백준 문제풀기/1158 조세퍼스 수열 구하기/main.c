#include <stdio.h>
#define MAXSIZE 5000

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
	int N, K, count=0, i;
	scanf("%d %d",&N,&K);
	for(i=1; i<=N; i++) {
		push(i);
	}
	printf("<");
	while(N > count) {
		for(i=0; i<K-1; i++) {
			push(pop());			
		}
		if(count == N-1)
			printf("%d", pop());
		else
			printf("%d, ", pop());
		count++;
	}
	printf(">");
		
	return 0;
}
