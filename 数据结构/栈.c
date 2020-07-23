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

void init(pStack ps); //初始化 
void push(pStack ps,int val); //压栈 
void traverse(pStack ps);//遍历元素 
void clear(pStack ps);//清空栈 


int main()
{
	Stack s;
	int val;
	
	init(&s); //创建空栈 
	
	//压栈 
	for(val=0; val<10; val++)
		push(&s,val);

	if(pop(&s,&val))
		printf("出栈成功，出栈元素为：%d\n",val);
	else
		printf("出栈失败\n");
	
//	clear(&s);	 //清空栈 
	traverse(&s); //遍历输出 
			
	
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
	pNode pnew = (pNode)malloc(sizeof(Node)); //分配空间 
	pnew->data = val; //放入数据 
	pnew->pNext = ps->pTop;//指向栈底 
	ps->pTop = pnew; // 栈顶新指向新节点 
	
	return ;
}

void traverse(pStack ps){ //创建临时指针 
	pNode p = ps->pTop;
	while(p != ps->pBottom){
		printf("p->=%d\n",p->data);
		p = p->pNext;
	}
	
	return ;
}

int emty(pStack ps){ //判断栈顶是否为空 
	if(ps->pTop ==ps->pBottom)
		return 1;
	else 
		return 0;
} 

// 吧ps指向出栈一次，并把出栈元素放入pVal中，
//出栈成功返回pVal，若失败返回空 
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
