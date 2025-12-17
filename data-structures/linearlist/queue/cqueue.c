//线性表-循环队列-顺序结构
//取模操作 每次移动队尾、队头指针都要通过取模运算
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;

typedef struct {
	Elemtype *data;
	int front;//当成数组下标
	int rear;//当成数组下标
}Queue;

//初始化-动态分配空间
Queue* initQueue1() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->data = (Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
	Q->front = 0;//队头指针
	Q->rear = 0;//队尾指针
	return Q;
}

//判断循环队列是否为空
int isEmpty1(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//循环队列-入队
int equeue1(Queue* Q, Elemtype e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) { //通过取模操作判断满队列
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;//取模
	return 1;
}

//循环队列-出队
Elemtype dequeue1(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	Elemtype e = Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;//取模
	return e;
}

int main() {
	Queue* Q = initQueue1();//Q是Queue结构体类型的指针
	equeue1(Q, 10);
	equeue1(Q, 20);
	equeue1(Q, 30);
	equeue1(Q, 40);
	equeue1(Q, 50);

	printf("%d\n", dequeue1(Q));
	printf("%d\n", dequeue1(Q));
	return 0;
}
