//线性表-栈-顺序结构（先进后出）
#include <stdio.h>
#define MAXSIZE 100

typedef int Elemtype;
//栈的结构体类型
typedef struct stack {
    Elemtype data[MAXSIZE];
	int top; // 把top当作下标
}Stack;
//栈的顺序结构-初始化
void initStack(Stack* s) {
	s->top = -1;
}

//判断栈是否为空
int isEmpty(Stack* s) {
	if (s->top == -1) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//进栈/压栈
int push(Stack* s, Elemtype e) {
	if (s->top>= MAXSIZE - 1) {
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈
int pop(Stack* s, Elemtype* e) {
	if (s->top == -1) {
		printf("空了\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(Stack* s,Elemtype* e) {
	if (s->top == -1) {
		printf("空了\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

int main() {
	Stack s;//定义一个栈，Stack栈的结构体类型
	initStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	Elemtype e;//用来存储出栈/取栈顶的结果
	pop(&s, &e);
	printf("%d\n", e);
	getTop(&s, &e);
	printf("%d\n", e);

	return 0;
}

//栈的顺序结构初始化-动态内存分配
/*#include <stdlib.h>//malloc函数
#define MAXSIZE 100
typedef int Elemtype;
typedef struct Stack {
	Elemtype* data;
	int top;
};
Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (Elemtype*)malloc(sizeof(Elemtype));
	s->top = -1;
	return s;
}*/
