#include <stdio.h>
#include <stdlib.h>

#define len 10	//设置队列大小 
				//从0放入len-1个值 

typedef struct Queue{
	int *pBase; //数组 
	int front; //对头指针 
	int rear; //队尾指针 
}Queue;

void init(Queue *pq); 			//初始化队列 
int input(Queue *pq,int val);	//入队 
void treverse(Queue *pq);	 	//遍历队列
int out(Queue *pq,int *pval); 	//出队

int main()
{
	int i; 
	Queue q; 			//创建队名：q 
	
	init(&q); 			//初始化队列 
	
	for(i=0;i<len;i++)
		input(&q,i); 	//入队 
	
	treverse(&q); 		//遍历队列

	if(out(&q,&i)==0) 	//出队 
		printf("out queue ok the facot is %d\n",i);
	else 
		printf("out error !\n");
	treverse(&q); 		//遍历队列
	
	
	return 0;
 } 

void init(Queue *pq){ 	//初始化队列 
	//为队列申请内存 
	pq->pBase = (int *)malloc(sizeof(int)*len); 
	pq->front = 0; 		//队头尾部指针指向同一个地方 
	pq->rear = 0; 
}

int input(Queue *pq,int val){			//入队 
	if((pq->rear+1)%len==pq->front)
										//判断是否满了 
		return 1;						//队列满了返回1
	else{								//队列没有满，入队操作		
		pq->pBase[pq->rear] = val; 		//放入值 
		pq->rear = (pq->rear+1)%len; 	//尾指针指向下一个 
		return 0;
	}
}

void treverse(Queue *pq){ 				//遍历队列
	int point = pq->front;
	while(point != pq->rear){
		printf(" %d -> ",pq->pBase[point]);
		point = (point+1)%len;
	} 
	printf("\n");
	return ;
}

int out(Queue *pq,int *pval){ 			//出队
 	if(pq->front == pq->rear) 			//出对前判断是否为空
	 	return 1; 						//为空返回1； 
	else {
		*pval = pq->pBase[pq->front];	 //吧头指针指向值给pval 
		pq->front = (pq->front+1)%len;	//指向下一个元素 
		return 0;
	} 
}

