//线性表-栈的链式结构
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct stack {
	Elemtype data;
	struct stack *next;
}Stack;
//初始化
Stack* initStack1() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}
//判断是否为空
int isEmpty1(Stack* s) {
	if (s->next == NULL) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//压栈
void push1(Stack* s, Elemtype e) {
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
int pop1(Stack* s, Elemtype *e) {
	if (s->next == NULL) {
		printf("空了\n");
		return 0;
	}
	Stack* q = s->next;
	*e = q->data;
	s->next = q->next;
	free(q);
	return 1;
}
//获取栈顶元素
int getTop1(Stack* s, Elemtype* e) {
	if (s->next==NULL) {
		printf("空了\n");
		return 0;
	}
	*e = s->next->data;
	return 1;
}

int main() {
	Stack* s = initStack1();
	push1(s, 10);
	push1(s, 20);
	push1(s, 30);

	Elemtype e;
	pop1(s, &e);
	printf("%d\n", e);
	pop1(s, &e);
	printf("%d\n", e);

	getTop1(s, &e);
	printf("%d\n", e);
	return 0;
}
