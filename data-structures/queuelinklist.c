//线性表-队列-链式结构
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
//链表节点类型结构体
typedef struct QueueNode {
	Elemtype data;//链表data域
	struct QueueNode* next;//链表next域
}QueueNode;
//声明两个节点类型指针分别指向队头和队尾
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}Queue;

//初始化(动态分配内存)
Queue* initQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//构造一个头节点
	node->data = 0;//头节点赋值为0
	node->next = NULL;
	//最开始队头和队尾指针都指向头节点，空
	q->front = node;
	q->rear = node;
	return q;
}

//判断链式队列是否为空
int isEmpty(Queue *q) {
	if (q->front == q->rear) {
		printf("空的\n");
		return 1;
	}
	printf("不为空\n");
	return 0;
}

//链式结构队列-入队
void eQueue(Queue* q, Elemtype e) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//创造一个新节点
	node->data = e;
	node->next = NULL;
	q->rear->next = node;//尾节点的next指向新节点
	q->rear = node;
}

//链式结构队列-出队
//依次将首节点释放
Elemtype deQueue(Queue* q) {
	QueueNode* node = q->front->next;//要删除节点
	Elemtype e = node->data;
	q->front->next = node->next;//front开始指向头节点
	if (q->rear == node) {
		q->rear = q->front;
	}
	free(node);
	return e;
}

//获取队头元素
Elemtype getQueue(Queue* q) {
	if (isEmpty02(q)) {
		return 0;
	}
	return q->front->next->data;//front开始指向头节点
}

int main() {
	Queue* q = initQueue();
	eQueue(q, 10);
	eQueue(q, 20);
	eQueue(q, 30);
	eQueue(q, 40);
	eQueue(q, 50);
	printf("%d\n", deQueue(q));
	printf("%d\n", deQueue(q));
	printf("%d\n", deQueue(q));
	printf("%d\n", deQueue(q));
	printf("%d\n", getQueue(q));
	return 0;
}
