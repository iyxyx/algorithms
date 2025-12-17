//线性表-双向链表(操作基本与单链表一致)
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
//定义双向链表
typedef struct node {
	Elemtype data;
	struct node* next, * prev;
}Node;

//初始化链表
Node* initList03() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//头插法
int insertHead03(Node* L, Elemtype e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	p->prev = L;
	if (L->next != NULL) {
		L->next->prev = p;
	}
	L->next = p;
	return 1;
}

//遍历
void listNode03(Node* L) {
	Node* p = L->next;
	while (p!= NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//尾插法
//获取尾节点
Node* get_tail03(Node* L) {
	Node* tail =L;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}
Node* insertTail03(Node* tail, Elemtype e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = tail;
	tail->next = p;
	p->next = NULL;
	return p;
}

//在指定位置插入
//获取指定位置的前驱节点
int insertList03(Node* L, int pos, Elemtype e) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->prev = p;
	q->next = p->next;
	p->next->prev = q;
	p->next = q;
	return 1;
}

//删除节点
//获取删除节点的前驱节点
int deleteNode03(Node* L,int pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	Node* q = p->next;
	p->next = q->next;
	q->next->prev = p;
	free(q);
	return 1;
}

//释放链表
void freeList03(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

int main() {
	Node* list = initList03();

	insertHead03(list, 10);
	insertHead03(list, 20);
	insertHead03(list, 30);
	listNode03(list);

	Node* tail = get_tail03(list);
	tail = insertTail03(tail, 40);
	tail = insertTail03(tail, 50);
	tail = insertTail03(tail, 60);
	listNode03(list);

	insertList03(list, 3, 15);
	listNode03(list);

	deleteNode03(list, 3);
	listNode03(list);
	return 0;
}
