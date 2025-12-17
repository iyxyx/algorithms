#ifndef SEQLIST-H//防止头文件重复包含
#define SEQLIST-H

#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
//顺序表的定义
typedef struct {
    ElemType data[MAXSIZE];//存放顺序表元素的数组
    int length;//顺序表当前长度
} SeqList;

//函数声明
void initList(SeqList* L);
int appendElem(SeqList* L, ElemType e);
void listElem(SeqList* L);
int insertElem(SeqList* L, int pos, ElemType e);
int deleteElem(SeqList* L, int pos, ElemType* e);
int findElem(SeqList* L, ElemType e);

#endif

