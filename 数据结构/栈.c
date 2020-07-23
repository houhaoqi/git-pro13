#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * pNext;
}Node,*pNode;

typedef struct Stack{
	pNode pTop;
	pNode pBottom;
}Stack,*pStack;

void init(pStack ps); //��ʼ�� 
void push(pStack ps,int val); //ѹջ 
void traverse(pStack ps);//����Ԫ�� 
void clear(pStack ps);//���ջ 


int main()
{
	Stack s;
	int val;
	
	init(&s); //������ջ 
	
	//ѹջ 
	for(val=0; val<10; val++)
		push(&s,val);

	if(pop(&s,&val))
		printf("��ջ�ɹ�����ջԪ��Ϊ��%d\n",val);
	else
		printf("��ջʧ��\n");
	
//	clear(&s);	 //���ջ 
	traverse(&s); //������� 
			
	
	return 0;
}

void init(pStack ps){
	ps->pTop = (pNode)malloc(sizeof(Node));
	if(NULL ==ps->pTop){
		printf("malloc error!");
		exit(-1);
	} else{
		ps->pBottom = ps->pTop;
	}	
}

void push(pStack ps,int val){
	pNode pnew = (pNode)malloc(sizeof(Node)); //����ռ� 
	pnew->data = val; //�������� 
	pnew->pNext = ps->pTop;//ָ��ջ�� 
	ps->pTop = pnew; // ջ����ָ���½ڵ� 
	
	return ;
}

void traverse(pStack ps){ //������ʱָ�� 
	pNode p = ps->pTop;
	while(p != ps->pBottom){
		printf("p->=%d\n",p->data);
		p = p->pNext;
	}
	
	return ;
}

int emty(pStack ps){ //�ж�ջ���Ƿ�Ϊ�� 
	if(ps->pTop ==ps->pBottom)
		return 1;
	else 
		return 0;
} 

// ��psָ���ջһ�Σ����ѳ�ջԪ�ط���pVal�У�
//��ջ�ɹ�����pVal����ʧ�ܷ��ؿ� 
int pop(pStack ps,int* pVal){
	if(emty(ps)==1){
		return 0;
	} else{
		pNode r = ps->pTop;
		*pVal = r->data;
		ps->pTop = r->pNext;
		free(r);
		r = NULL;
		return 1;
	}
}

void clear(pStack ps){
	if(emty(ps))
		return;
	else {
		pNode p = ps->pTop;
		ps->pTop = NULL;
		while(ps->pTop != ps->pBottom) {
			ps->pTop = p->pNext;
			free(p);
			p = ps->pTop;
		}
		/* 
		pNode p = ps->pTop;
		pNode q = NULL;
		while(p != ps->pBottom){
			q = p->pNext;
			free(p);
			p = q;
		}
		ps->pTop = ps->pBottom;
		*/ 
	}
}
