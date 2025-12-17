//二叉树-链式结构-递归遍历(压栈和出栈的过程)
#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;

typedef struct TreeNode {
	Elemtype data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;//BiTree类型相当于TreeNode类型的指针


//创造一颗树
char str[] = "ABDH#K###E##CFI###G#J##";//根据前序遍历造树
int idx = 0;
void createTree(BiTree* T) { //传入指针的指针，在函数内部修改外部的原指针变量
	Elemtype ch;
	ch = str[idx++];
	if (ch == '#') {
		*T = NULL;//*解引用指针，T是指针的指针，此时*T是指针
	}
	else {
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);//递归
		createTree(&(*T)->rchild);
	}
}

//二叉树的遍历-前序遍历
void preOrder(BiTree T) { // T是TreeNode类型的指针
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);// 打印输出
	preOrder(T->lchild);// 递归一直传入左孩子节点
	preOrder(T->rchild);//递归右子树
}

//中序遍历
void inOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	//从根节点开始先一直向左孩子移动直到空节点
	inOrder(T->lchild);// 递归左子树（一直压栈）
	printf("%c ", T->data);
	inOrder(T->rchild);//递归右子树
}

//后序遍历
void postOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	postOrder(T->lchild);// 递归左子树
	postOrder(T->rchild);//递归右子树
	printf("%c ", T->data);
}


int main() {
	BiTree T;
	createTree(&T);// 把指针T的地址传进去，可以直接修改外部原指针

	preOrder(T);
	printf("\n");

	inOrder(T);
	printf("\n");

	postOrder(T);
	printf("\n");
	return 0;
}
