#include <stdio.h>
#include <string.h>

struct student{
	int id;
	char name[100];
	int age;
};

void f(struct student *ps);
void g(struct student s);
void g2(struct student * s);

int main()
{
	struct student s;
	f(&s);
	g(s);
	g2(&s);
	
	return 0;
 } 
 
 void f(struct student *ps){
 	
 	(*ps).id = 1;
 	strcpy(ps->name,"haoqi");
 	ps->age = 19;
 }
 //���ַ�ʽ�����ڴ�� 
 void g(struct student s){
 	printf("%d,%s,%d\n",s.id,s.name,s.age);
 }
 //ָ��������Ч�ʽ�Լ�ռ� 
 void g2(struct student * ps){
 	printf("%d,%s,%d\n",ps->id,ps->name,ps->age);
 }
