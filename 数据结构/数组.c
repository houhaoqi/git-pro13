#include <stdio.h>

int main1()
{
	int a[5]={1,2,3,4,5};
	//a[3] = *(a+30 = *(3+a) = 3[a]; 
	
	printf("%d\n",3[a]); 
	return 0;
}
void showa(int * p,int len){
	p[len] = -1;
}
int main()
{
	int a[5]={1,2,3,4,5};
	int len = 4;
	showa(a,len);
	for(len=0;len<5;len++)
		printf("%d\n",a[len]);
	
	return 0;
}
