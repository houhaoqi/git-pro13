#include <stdio.h>
#include <string.h>

struct student{
	int id;
	char name[200];
	int age;
};

int main()
{
	struct student s = {
		10001,
		"haoqi",
		19
	};
	strcpy(s.name,"dapeng");
	printf("%d,%s,%d\n",s.id,s.name,s.age);
	
	//һ��ʹ��һ��һ�ַ�ʽ
	 
	struct student * pst;
	pst = &s;
	pst->id = 99;
	printf("%d,%s,%d\n",s.id,s.name,s.age);
	 
	
	return 0;
}
