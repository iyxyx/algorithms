//线性表-队列-顺序结构（先进先出）
#include <stdio.h>
#define MAXSIZE 100

typedef int Elemtype;

typedef struct {
	Elemtype data[MAXSIZE];
	int front;//当成数组下标
	int rear;//当成数组下标
}Queue;

//初始化
void initQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}

//判断队列是否为空
int isEmpty2(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}

//顺序队列-出队
Elemtype dequeue(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	Elemtype e = Q->data[Q->front];
	Q->front++;
	return e;
}

//顺序队列-入队
//若队头有剩余，往前移动
int queueFull(Queue* Q) {
	if (Q->front == 0) {
		printf("真的满了\n");
		return 0;
	}
	//队尾已经到头，但是队头前面有空余
	int step = Q->front; // step是队头前的空余长度
	for (int i = Q->front; i <= Q->rear;i++) {  //遍历当前列表元素
		Q->data[i - step] = Q->data[i]; //元素向前移动step位
	}
	Q->front = 0; //队头重置到数组开头
	Q->rear = Q->rear - step; //队尾同步前移step位 
	return 1;
}
int equeue(Queue* Q,Elemtype e) {
	if (Q->rear == MAXSIZE) {
		if (!queueFull(Q)) {
			return 0;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
	return 1;
}

//获取队头元素
int getqueueHead(Queue* Q, Elemtype* e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

int main() {
	Queue Q;
	initQueue(&Q);
	equeue(&Q, 10);
	equeue(&Q, 20);
	equeue(&Q, 30);

	printf("%d\n", dequeue(&Q));
	printf("%d\n", dequeue(&Q));

	Elemtype e;
	getqueueHead(&Q, &e);
	printf("%d\n", e);

	return 0;
}
