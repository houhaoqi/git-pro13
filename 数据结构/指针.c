#include <stdio.h>


 
 int main(void)
 {
 	int i = 0;
 	swao(&i);
 	printf("i=%d",i);
 	
 	return 0;
 }
 void swao(int * p){
 	*p = 100;
 }
