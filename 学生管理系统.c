#include <stdio.h>
#include <stdlib.h>

struct student{
	int num;
	char name[20];
	int gread;
};
//���������޸ĳ�ѧ������ϵͳ 
struct Node{
	struct student data;
	struct Node * next;
}; 

//��������
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode ��ɽṹ�����
	//����ʹ��ǰҪ��ʼ��,����һ�㸳��NULL 
	//headNode->data = 1��
	headNode->next = NULL;
	
	return headNode; 
} 

//�����ڵ�
struct Node* createNode(struct student  data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
} 

//��ӡ����
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

//ͷ����������
void insertNodeHead(struct Node* headNode,struct student  data){
	struct Node* newNode = createNode(data);
	//������� 
	newNode->next = headNode->next;
	headNode->next = newNode;
	
} 

//ָ������λ��ɾ��
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
				//δ�ҵ������� 
				return;
			}
		}
		posNodeFront->next = posNode->next; //�ҵ��ˣ�ɾ�� 
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
		printf("������ѧ�ţ��������ɼ�\n");
	//	setbuf(stdin,NULL);
		scanf("%d%s%d",&info.num,info.name,&info.gread);
		insertNodeHead(list,info);
		printf("������y/n����");
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

