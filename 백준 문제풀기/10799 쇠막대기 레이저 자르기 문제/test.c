#include <stdio.h>
#include <string.h>
int main() {	
	int pipe = 0;
	char str[100000];
	char prev, c;
	scanf("%s", str);
	int i, result=0;
	for(i=0; i<strlen(str); i++) 
	{
		c = str[i];
		if(c == '(') {
			pipe++;
		}
		else {
			pipe--;
			if(prev == '(')
				result += (pipe);	
			else 
				result ++;
		}
		prev = c;
	}
	printf("%d",result);
}
