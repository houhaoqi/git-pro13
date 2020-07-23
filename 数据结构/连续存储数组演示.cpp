#include <stdio.h>
#include <stdlib.h>

struct Arr{
	int * pbase;
	int len;
	int cnt;
};

void init_arr();
//bool append_arr();
//bool insert_arr();
//bool delete_arr();
//int get();
//bool is_empty();
bool is_full();
void sort_arr();
void show_arr();
void inversion_arr();

int main()
{
	struct Arr *arr;
	init_arr(&arr,10);
	printf("%d\n",arr.len); 
	show_arr(&arr);
	
	return 0;
}

void init_arr(struct Arr *arr,int length){
	arr->pbase = (int *)malloc(sizeof(int)*length);
	if(NULL == arr->pbase){
		printf("malloc error .exit\n");
		exit(-1);
	} else {
		//arr->len = length;
		//arr->cnt = 0;
	}
	return ;
}
void show_arr(struct Arr *arr){
	if(NULL == arr->pbase){
		printf("malloc error .exit\n");
		exit(-1);
	} else {
		printf("cnt=%d\tlen=%d\tpbase=%d",arr->cnt,arr->len,arr->pbase);
	}
}
