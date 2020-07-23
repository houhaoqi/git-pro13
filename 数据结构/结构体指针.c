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
 //这种方式消耗内存大 
 void g(struct student s){
 	printf("%d,%s,%d\n",s.id,s.name,s.age);
 }
 //指针可以提高效率节约空间 
 void g2(struct student * ps){
 	printf("%d,%s,%d\n",ps->id,ps->name,ps->age);
 }
