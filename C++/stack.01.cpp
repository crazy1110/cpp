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
		//栈满，追加存储空间
		s.base = (int *)realloc(s.base,(s.max + STACKINCREMENT)*sizeof(int));
		if(!s.base) exit(OVERLOW);//存储分配失败
		s.top = s.base + s.max;
		s.max += STACKINCREMENT;
	}
	*s.top++ = e;
	return ok;
}
int pop(sqstack & s,int *e) {
//若栈不空，删除s的栈顶元素，用e返回其值，并返回ok，否则饭后error
	if(s.top == s.base) return error;
	*e = *--s.top;
	return ok;
}
void convert(sqstack s) {
//对于输入的任意一个非负十进制整数，打印输出等值的二进制数
	Initstack(s);
	int n,e;
	printf("请输入一个非负十进制整数\n");
	scanf("%d",&n);
	while(n) {
		push(s,n%2);
		n=n/2;//效率更高.n=n>>1
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
