#include <stdio.h>
#include <malloc.h> 

int main()
{
	int a[5]={1,2,3,4,5};
	int len;
	printf("����Ҫ������ڴ棺\n");
	scanf("%d",&len);
	//��̬�ڴ�������� 
	int * pa = (int *)malloc(sizeof(int) *len);
	*pa = 4;// == pa[0] = 4;
	pa[1] = 10;
	
	printf("%d\n%d",*pa,pa[1]);
	
	free(pa); 
	
	return 0;
 } 
 
// struct s *p = (struct *)malloc(sizeof(struct s) *p);
