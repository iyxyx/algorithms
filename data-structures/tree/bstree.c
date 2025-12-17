//二叉搜索树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉搜索树结点类型
typedef char ElementType;
typedef struct TreeNode {
    ElementType data;
    struct TreeNode* lchild;  // 左孩子
    struct TreeNode* rchild;  // 右孩子
} TreeNode;
typedef TreeNode* BiTree;  // BiTree为指向TreeNode的指针类型


// 二叉搜索树-创建（按前序序列，'#'表示空结点）
// 全局变量：前序序列字符串、当前遍历索引
char g_preStr[] = "FBD##E##H##";  // 满足左小右大
int g_idx = 0;

// 创建二叉搜索树（递归）
void createBST(BiTree* T) { //T指针的指针
    ElementType ch = g_preStr[g_idx++];
    if (ch == '#') {  // 空结点
        *T = NULL;
        return;
    }
    // 分配结点空间
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    // 递归创建左、右子树
    createBST(&((*T)->lchild));
    createBST(&((*T)->rchild));
}


// 二叉搜索树-查找（左子树的所有键值小于根节点，右子树的所有键值大于根节点）
// 1. 递归查找
BiTree findRecursive(BiTree BST, ElementType X) {
    if (!BST) {  // 判断树是否为空，树空，查找失败
        return NULL;
    }
    if (X > BST->data) {
        return findRecursive(BST->rchild, X);  // 右子树查找
    }
    else if (X < BST->data) {
        return findRecursive(BST->lchild, X);  // 左子树查找
    }
    else {  // 找到目标结点
        return BST;
    }
}

// 2. 迭代查找（效率更高）
BiTree findIterative(BiTree BST, ElementType X) {
    while (BST) {
        if (X > BST->data) {
            BST = BST->rchild;  // 右移
        }
        else if (X < BST->data) {
            BST = BST->lchild;  // 左移
        }
        else {
            break;  // 找到，跳出循环
        }
    }
    return BST;  // 找到返回结点，否则返回NULL
}


// 二叉搜索树-查找最值
// 查找最小值（最左结点）
BiTree findMin(BiTree BST) {
    if (BST) {
        while (BST->lchild) {  // 一直向左走
            BST = BST->lchild;
        }
    }
    return BST;
}

// 查找最大值（最右结点）
BiTree findMax(BiTree BST) {
    if (BST) {
        while (BST->rchild) {  // 一直向右走
            BST = BST->rchild;
        }
    }
    return BST;
}


// 二叉搜索树-插入
// 递归插入
BiTree insertBST(BiTree BST, ElementType X) {
    if (!BST) {  // 树空，创建新结点作为根
        BST = (BiTree)malloc(sizeof(TreeNode));
        BST->data = X;
        BST->lchild = BST->rchild = NULL;
    }
    else {
        if (X < BST->data) {
            BST->lchild = insertBST(BST->lchild, X);  // 插入左子树
        }
        else if (X > BST->data) {
            BST->rchild = insertBST(BST->rchild, X);  // 插入右子树
        }
    }
    return BST;
}


// 二叉搜索树-删除
// 递归删除（分3种情况：无孩子、1个孩子、2个孩子）
typedef BiTree Position;
BiTree deleteBST(BiTree BST, ElementType X) {
    Position Tmp;
    if (!BST) {  // 树空
        printf("要删除的元素未找到\n");
    }
    else {
        if (X < BST->data) {
            BST->lchild = deleteBST(BST->lchild, X);  // 左子树删除
        }
        else if (X > BST->data) {
            BST->rchild = deleteBST(BST->rchild, X);  // 右子树删除
        }
        else {  // 找到要删除的结点
            // 情况1：有左右两个孩子
            if (BST->lchild && BST->rchild) {
                Tmp = findMin(BST->rchild);  // 找右子树的最小值结点
                BST->data = Tmp->data;       // 替换当前结点值
                BST->rchild = deleteBST(BST->rchild, BST->data);  // 删除右子树的最小值结点
            }
            else {  // 情况2：有1个孩子或无孩子
                Tmp = BST;
                if (!BST->lchild) {  // 只有右孩子或无孩子
                    BST = BST->rchild;
                }
                else {  // 只有左孩子
                    BST = BST->lchild;
                }
                free(Tmp);  // 释放原结点空间
            }
        }
    }
    return BST;
}


// 二叉搜索树-遍历
// 前序遍历（根-左-右）
void preOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

// 中序遍历（左-根-右）
void inOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}

// 后序遍历（左-右-根）
void postOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ", T->data);
}


int main() {
    BiTree BST = NULL;

    // 1. 创建二叉搜索树（按前序序列）
    createBST(&BST);
    printf("创建后的二叉搜索树（前序遍历）：");
    preOrder(BST);
    printf("\n");

    // 2. 查找测试
    ElementType findVal = 'E';
    BiTree findRes = findIterative(BST, findVal);
    if (findRes) {
        printf("查找元素 '%c'：成功（结点值：%c）\n", findVal, findRes->data);
    }
    else {
        printf("查找元素 '%c'：失败\n", findVal);
    }

    // 3. 插入测试
    ElementType insertVal = 'K';
    BST = insertBST(BST, insertVal);
    printf("插入元素 '%c' 后（中序遍历）：", insertVal);
    inOrder(BST);
    printf("\n");

    // 4. 删除测试
    ElementType deleteVal = 'C';
    BST = deleteBST(BST, deleteVal);
    printf("删除元素 '%c' 后（中序遍历）：", deleteVal);
    inOrder(BST);
    printf("\n");

    // 5. 遍历测试
    printf("\n前序遍历：");
    preOrder(BST);
    printf("\n中序遍历：");
    inOrder(BST);
    printf("\n后序遍历：");
    postOrder(BST);
    printf("\n");

    return 0;
}
