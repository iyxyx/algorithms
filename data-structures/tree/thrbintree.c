//线索二叉树(加上前驱和后继)
//遍历-像遍历双向链表一样去遍历二叉树
//1.头节点(自己创建)的lchild指向二叉树的根；2.头节点的rchild指向遍历的最后一个节点
//3.第一个节点（叶子节点）的lchild指向头节点；4.最后一个节点的rchild指向头节点
#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
//线索二叉树结构体
typedef struct ThreadNode {
	Elemtype data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	//ltag为0时，指向该节点的左孩子，为1时，指向该节点的前驱
	//rtag为0时，指向该节点的右孩子，为1时，指向该节点的后继
	int ltag;
	int rtag;
}ThreadNode;

typedef ThreadNode* ThreadTree;
//中序遍历
//按前序方式造树
char s[] = "ABDH##I##EJ###CF##G##";
int i = 0;
ThreadTree prev;//全局变量，记录每一次线索化过程中，上一次访问的节点
//创建树
void createTree1(ThreadTree *T) { // 如果不加*，就是传入T这个指针变量；*T传入指针T的地址
	Elemtype ch;
	ch = s[i++];
	if (ch == '#') {
		*T = NULL;//*T就是指向一个ThreadNode类型节点的指针
	}
	else {
		//ThreadTree相当于ThreadNode*
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		createTree1(&(*T)->lchild);//传地址&
		if ((*T)->lchild != NULL) {
			(*T)->ltag = 0;
		}
		createTree1(&(*T)->rchild);
		if ((*T)->rchild != NULL) {
			(*T)->rtag = 0;
		}
	}
}

//具体线索化（加前驱，加后继）
void threading(ThreadTree T) {
	if (T != NULL) {
		//中序遍历，先递归找左孩子
		threading(T->lchild);
		if (T->lchild == NULL) { //左孩子到了叶子节点
			T->ltag = 1;
			T->lchild = prev;
		}
		if (prev->rchild == NULL) {
			prev->rtag = 1;
			prev->rchild = T;
		}
		prev = T;
		threading(T->rchild);
	}
}

//开始线索化（四个步骤）
void inOrderThreading(ThreadTree *head,ThreadTree T) { //传入指针T即可
	//创造头节点 
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = (*head); //还未遍历，先指向头节点本身

	if (T == NULL) {
		(*head)->lchild = *head;
	}
	else {
		(*head)->lchild = T; //1.二叉树的根赋值给头节点的lchild
		prev = (*head);//线索化的上一个节点prev

		threading(T);

		//最后一个节点线索化
		prev->rchild = *head;//4
		prev->rtag = 1;
		//2.头节点右孩子指向最后一个节点
		(*head)->rchild = prev;
	}
}

//使用线索进行中序遍历
void inOrder1(ThreadTree T) {
	ThreadTree curr;
	curr = T->lchild;//curr此时是头节点T的左孩子即根节点
	while (curr != T) { //循环条件是curr不等于头节点，循环到最后一个节点时会回到头节点
		while (curr->ltag == 0) {
			curr = curr->lchild;//左子树一直循环到叶子节点
		}
		printf("%c", curr->data);
		while (curr->rtag == 1 && curr->rchild != T) {
			curr = curr->rchild;//根据线索直接跳到后继节点
			printf("%c", curr->data);//输出后继节点
		}
		curr = curr->rchild;//右子树一直循环到叶子节点
	}
	printf("\n");
}

int main() {
	ThreadTree head;
	ThreadTree T;
	//创建
	createTree1(&T);
	//线索化
	inOrderThreading(&head, T);
	//基于线索遍历
	inOrder1(head);//传入头节点
	return 0;
}
