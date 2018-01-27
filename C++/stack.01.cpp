#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERLOW -2
#define ok 1
#define error -1

typedef struct sqstack {
	int *base;
	int *top;
	int max;
} sqstack;


void Initstack(sqstack &s) {
	s.base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));

	if(!s.base) exit(OVERLOW);
	s.top = s.base;
	s.max = STACKINCREMENT;
}
int stackempty(sqstack &s) {
	if(s.base == s.top) return 1;
	return 0;
}
int push(sqstack &s,int e) {
	if(s.top-s.base >= s.max) {
		//ջ����׷�Ӵ洢�ռ�
		s.base = (int *)realloc(s.base,(s.max + STACKINCREMENT)*sizeof(int));
		if(!s.base) exit(OVERLOW);//�洢����ʧ��
		s.top = s.base + s.max;
		s.max += STACKINCREMENT;
	}
	*s.top++ = e;
	return ok;
}
int pop(sqstack & s,int *e) {
//��ջ���գ�ɾ��s��ջ��Ԫ�أ���e������ֵ��������ok�����򷹺�error
	if(s.top == s.base) return error;
	*e = *--s.top;
	return ok;
}
void convert(sqstack s) {
//�������������һ���Ǹ�ʮ������������ӡ�����ֵ�Ķ�������
	Initstack(s);
	int n,e;
	printf("������һ���Ǹ�ʮ��������\n");
	scanf("%d",&n);
	while(n) {
		push(s,n%2);
		n=n/2;//Ч�ʸ���.n=n>>1
	}
	while(!stackempty(s)) {
		pop(s,&e);
		printf("%d",e);
	}
	printf("\n");
}

int main() {
	sqstack* s;

	s = (sqstack*) malloc(sizeof(sqstack));

	convert(*s);

	free(s);

	return 0;
}
