#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
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
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
} 

//��ӡ����
void printList(struct Node* headNode){
	struct Node* pMove;
	pMove = headNode->next;
	while(pMove){
		printf("%d\n",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
} 

//ͷ����������
void insertNodeHead(struct Node* headNode,int data){
	struct Node* newNode = createNode(data);
	//������� 
	newNode->next = headNode->next;
	headNode->next = newNode;
	
} 

//ָ������λ��ɾ��
void deleteNode(struct Node* headNode,int posData){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode; //������ʱ�ڵ� 
	if(posNode == NULL)
		printf("it's NULL ,couldn't delete");
	else {
		while(posNode->data != posData){
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
	insertNodeHead(list,1);
	insertNodeHead(list,2);
	insertNodeHead(list,3);
	insertNodeHead(list,4); 
	printList(list);
	
	deleteNode(list,2);
	printList(list);
	
	return 0;
}

