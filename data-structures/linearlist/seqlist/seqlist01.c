#include "seqlist.h"
//顺序表-初始化
void initList(SeqList* L) {//initList要求传一个SeqList类型的指针
    L->length = 0;
}


//顺序表-在尾部添加元素
int appendElem(SeqList* L, ElemType e) {
    if (L->length == MAXSIZE) {
        printf("顺序表已满\n");
        return 0;
   }
    L->data[L->length] = e;//把length当作数组下标，开始时length=0
    L->length++;
    return 1;
 }

//顺序表-遍历
void listElem(SeqList* L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

//顺序表-插入元素（最好时间复杂度为O（1），最坏为O（N））
int insertElem(SeqList* L, int pos,ElemType e) {
    if (L->length >= MAXSIZE) {
        printf("顺序表已经满了\n");
        return 0;
    }
    if (pos > L->length || pos < 1) {
        printf("插入位置错误\n");
        return 0;
    }
    if (pos <= L->length) {
        for (int i = L->length-1; i >= pos - 1; i--) {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

//顺序表-删除元素
int deleteElem(SeqList* L, int pos, ElemType* e) {
    *e = L->data[pos - 1];
    if (L->length < 1) {
        printf("顺序表已经空了\n");
        return 0;
    }
    if (pos > L->length) {
        printf("删除位置错误\n");
        return 0;
    }
    if (pos <= L->length) {
        for (int i = pos; i < L->length; i++) {
            L->data[i - 1] = L->data[i];
        }
        L->length--;
        return 1;
    }
}

//顺序表-查找(给一个参数e，查找e第一次出现的位置)
int findELem(SeqList* L, ElemType e) {
    if (L->length < 1) {
        printf("顺序表为空\n");
        return 0;
    }
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

int main01() {
    //声明一个顺序表并初始化
    SeqList list;
    initList(&list);//函数默认传递是值传递，即不改变原始变量；用&list可直接修改变量地址
    printf("初始化成功，目前长度占用%d\n", list.length);
    printf("目前占用内存%zu字节\n", sizeof(list.data));

    appendElem(&list, 18);
    appendElem(&list, 30);
    appendElem(&list, 54);
    appendElem(&list, 62);
    appendElem(&list, 86);
    listElem(&list);

    insertElem(&list, 2, 20);
    listElem(&list);

    ElemType delData;
    deleteElem(&list, 3, &delData);
    printf("被删除的元素为：%d\n", delData);
    listElem(&list);

    printf("%d\n",findELem(&list, 86));

    return 0;
}