#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
}; 

//创建链表
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode 变成结构体变量
	//变量使用前要初始化,链表一般赋予NULL 
	//headNode->data = 1；
	headNode->next = NULL;
	
	return headNode; 
} 

//创建节点
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
} 

//打印链表
void printList(struct Node* headNode){
	struct Node* pMove;
	pMove = headNode->next;
	while(pMove){
		printf("%d\n",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
} 

//头部插入链表
void insertNodeHead(struct Node* headNode,int data){
	struct Node* newNode = createNode(data);
	//插入对象 
	newNode->next = headNode->next;
	headNode->next = newNode;
	
} 

//指定链表位置删除
void deleteNode(struct Node* headNode,int posData){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode; //创建临时节点 
	if(posNode == NULL)
		printf("it's NULL ,couldn't delete");
	else {
		while(posNode->data != posData){
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if(posNode == NULL){
				printf("it's NULL ,couldn't delete");
				//未找到，返回 
				return;
			}
		}
		posNodeFront->next = posNode->next; //找到了，删除 
		free(posNode);
	}

} 



int main()
{
	struct Node* list = createList();
	insertNodeHead(list,1);
	insertNodeHead(list,2);
	insertNodeHead(list,3);
	insertNodeHead(list,4); 
	printList(list);
	
	deleteNode(list,2);
	printList(list);
	
	return 0;
}

