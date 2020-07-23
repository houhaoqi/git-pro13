#include <stdio.h>

void han(int n,char A,char B,char C){
	if(1==n)
		printf("%d= %c -> %c\n",n,A,C);
	else {
		han(n-1,A,C,B);
		
		printf("%d= %c -> %c\n",n,A,C);
		
		han(n-1,B,A,C);
	} 
}

int main()
{
	int n;
	char A='a',B='b',C='c';
	
	printf("ººÅµËşÅÌ×Ó¸öÊı£º\n");
	scanf("%d",&n);
	han(n,'a','b','c');
	
	return 0;
 } 
