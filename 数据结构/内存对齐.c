#include <stdio.h>

struct {
	int i;
	char b;
	char c;
}x1;

struct {
	char b;
	char c;
	int i;
	
}x2;

struct {
	char c;
	int i;
	char b;
	
}x3;

int main()
{
	printf("%d\n",sizeof(x1));
	printf("%d\n",sizeof(x2));
	printf("%d\n",sizeof(x3));
	
	return 0;
}

