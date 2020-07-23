#include <stdio.h>

int main1()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int i,n = 9,t;
	
	for (i=0;i<n/2;i++){
		t = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1]=t;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	
	return 0;
 } 
 
 int main()
 {
 	int a[] = {1,2,3,4,5,6,7,8,9};
 	int b[9],i,n=9;
 	
 	for(i=0;i<n;i++)
 		b[i] = a[n-i-1];
 	for(i=0;i<n;i++)
 		a[i] = b[i];
 		
 	for (i=0;i<n;i++)
 		printf("%d ",a[i]);
 	
 	return 0;
 }
