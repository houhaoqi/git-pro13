#include <stdio.h>
#define len 10
long f(long n){
	if(1==n)
		return 1;
	else
		return n+f(n-1); 
}
void g(){//��ӵݹ���� 
	
	printf("%d\n",f(len));
}
int main()
{
	g();
	
	return 0;
}
 
