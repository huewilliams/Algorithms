#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ArrayStack[50];

int main() {
	int result = 0;
	int count = 0;
	scanf("%d", &count);
	while(count > 0) {
		scanf("%s", ArrayStack);
		count --;
		int i=0;
		for(i=0; i<strlen(ArrayStack); i++) {
			if(ArrayStack[i] == '(')
				result ++;
			else
				result --;
			if(result < 0) {
				break;
			}
		}
		if(result == 0)
			printf("YES\n");
		else
			printf("NO\n");
		result = 0;
	}
	
	return 0;
}
