//顺序表-单链表
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct node {
	Elemtype data;
	struct node* next;
}Node;


//初始化链表2
//Node*：让初始化链表函数返回头节点地址
Node* initNode() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;//Node*的返回类型
}


//单链表-头插法
int insertHead(Node* L, Elemtype e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;//先将新节点的下一个指向头节点的下一个
	L->next = p;
	return 1;//int类型有返回值
}


//单链表-遍历
void listNode(Node* L) {
	Node* p = L->next;
	while (p!= NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");//void类型无返回值
}


//单链表-尾插法
//先获取尾节点并返回
Node* get_tail(Node* L) {
	Node* tail = L;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}
Node* insertTail(Node* tail, Elemtype e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next=p;
	p->next=NULL;
	return p;//返回新的尾节点，便于后续重复使用尾插法
}


//单链表-在指定位置插入数据
// 先要遍历到指定位置的前一个节点
int insertNode(Node* L, int pos, Elemtype e) {
	Node* p = L;//用来保存插入节点的前驱节点
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
	}

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}


//单链表-删除节点
// 先找到删除节点的前驱节点p，q记录，通过改变p的后继节点实现删除q，最后释放空间
int deleteNode(Node* L, int pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
	}
	Node* q=p->next;//q指向要删除节点
	p->next = q->next;//让要删除节点的前驱指向要删除节点的后继
	free(q);//释放要删除节点的内存空间
	return 1;
}


//单链表-获取链表长度
int listlength(Node* L) {
	Node* p = L;
	int len = 0;
	while (p!= NULL) {
		p=p->next;
		len++;
	}
	return len;
}


//单链表-释放链表
//指针p指向头节点后的第一个节点，判断p，不为空用指针q记录p的后继节点，释放p，p与q指向同一个节点，循环操作
void freeList(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//让头节点指向空
}


int main() {
	Node* list = initNode();
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	listNode(list);//30 20 10 头插法插入顺序与排列顺序是相反的

	Node* tail = get_tail(list);
	tail=insertTail(tail, 40);
	tail=insertTail(tail, 50);
	tail=insertTail(tail, 60);
	listNode(list);

	insertNode(list, 3, 15);
	listNode(list);

	deleteNode(list, 3);
	listNode(list);

	printf("%d\n",listlength(list));

	freeList(list);
	printf("%d\n", listlength(list));
	return 0;
}
