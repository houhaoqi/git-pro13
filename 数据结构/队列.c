#include <stdio.h>
#include <stdlib.h>

#define len 10	//���ö��д�С 
				//��0����len-1��ֵ 

typedef struct Queue{
	int *pBase; //���� 
	int front; //��ͷָ�� 
	int rear; //��βָ�� 
}Queue;

void init(Queue *pq); 			//��ʼ������ 
int input(Queue *pq,int val);	//��� 
void treverse(Queue *pq);	 	//��������
int out(Queue *pq,int *pval); 	//����

int main()
{
	int i; 
	Queue q; 			//����������q 
	
	init(&q); 			//��ʼ������ 
	
	for(i=0;i<len;i++)
		input(&q,i); 	//��� 
	
	treverse(&q); 		//��������

	if(out(&q,&i)==0) 	//���� 
		printf("out queue ok the facot is %d\n",i);
	else 
		printf("out error !\n");
	treverse(&q); 		//��������
	
	
	return 0;
 } 

void init(Queue *pq){ 	//��ʼ������ 
	//Ϊ���������ڴ� 
	pq->pBase = (int *)malloc(sizeof(int)*len); 
	pq->front = 0; 		//��ͷβ��ָ��ָ��ͬһ���ط� 
	pq->rear = 0; 
}

int input(Queue *pq,int val){			//��� 
	if((pq->rear+1)%len==pq->front)
										//�ж��Ƿ����� 
		return 1;						//�������˷���1
	else{								//����û��������Ӳ���		
		pq->pBase[pq->rear] = val; 		//����ֵ 
		pq->rear = (pq->rear+1)%len; 	//βָ��ָ����һ�� 
		return 0;
	}
}

void treverse(Queue *pq){ 				//��������
	int point = pq->front;
	while(point != pq->rear){
		printf(" %d -> ",pq->pBase[point]);
		point = (point+1)%len;
	} 
	printf("\n");
	return ;
}

int out(Queue *pq,int *pval){ 			//����
 	if(pq->front == pq->rear) 			//����ǰ�ж��Ƿ�Ϊ��
	 	return 1; 						//Ϊ�շ���1�� 
	else {
		*pval = pq->pBase[pq->front];	 //��ͷָ��ָ��ֵ��pval 
		pq->front = (pq->front+1)%len;	//ָ����һ��Ԫ�� 
		return 0;
	} 
}

