#include <stdio.h>
#include <stdlib.h>

struct student{
	int num;
	char name[20];
	int gread;
};
//利用链表修改成学生管理系统 
struct Node{
	struct student data;
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
struct Node* createNode(struct student  data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
} 

//打印链表
void printList(struct Node* headNode){
	struct Node* pMove;
	pMove = headNode->next;
	
	printf("num\tname\tgread\n");
	while(pMove){
		printf("%d\t%s\t%d\n",pMove->data.num,pMove->data.name,pMove->data.gread);
		pMove = pMove->next;
	}
	printf("\n");
} 

//头部插入链表
void insertNodeHead(struct Node* headNode,struct student  data){
	struct Node* newNode = createNode(data);
	//插入对象 
	newNode->next = headNode->next;
	headNode->next = newNode;
	
} 

//指定链表位置删除
void deleteNodeNum(struct Node* headNode,int num){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if(posNode == NULL)
		printf("it's NULL ,couldn't delete");
	else {
		while(posNode->data.num != num){
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
//	insertNodeHead(list,1);
//	insertNodeHead(list,2);
//	insertNodeHead(list,3);
//	insertNodeHead(list,4); 
//	printList(list);
//	deleteNodeNum(list,2);

	//------------------------
	struct student info;
	while(1){
		printf("请输入学号，姓名，成绩\n");
	//	setbuf(stdin,NULL);
		scanf("%d%s%d",&info.num,info.name,&info.gread);
		insertNodeHead(list,info);
		printf("继续（y/n）？");
	//	setbuf(stdin,NULL);
		int choice = 0; 
		scanf("%d",&choice);
		if(choice == 'N' || choice == 'n'){
			break;
		} 
		//	break;
	}
	printList(list);
	
	return 0;
}

