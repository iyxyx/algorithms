// 图-邻接表
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 边节点结构体
typedef struct EdgeNode {
    int adj_vex; // 邻接点的索引
    int weight;  // 边的权重
    struct EdgeNode* next; // 指向下一个边节点
} EdgeNode;

// 顶点结构体
typedef struct VertexNode {
    int data; // 顶点数据（可根据需求修改为char等）
    EdgeNode* first_edge; // 指向第一个边节点
} VertexNode;

// 邻接表结构体
typedef struct {
    VertexNode adj_list[MAX_VERTICES];
    int vertex_num; // 顶点数
    int edge_num;   // 边数
} AdjListGraph;

// 初始化图
void initGraph(AdjListGraph* graph, int vertex_num) {
    graph->vertex_num = vertex_num;
    graph->edge_num = 0;
    for (int i = 0; i < vertex_num; i++) {
        graph->adj_list[i].data = i; // 顶点数据暂设为索引
        graph->adj_list[i].first_edge = NULL;
    }
}

// 添加边（无向图，有向图则只添加单方向）
void addEdge(AdjListGraph* graph, int v1, int v2, int weight) {
    if (v1 < 0 || v1 >= graph->vertex_num || v2 < 0 || v2 >= graph->vertex_num) {
        return;
    }

    // 创建边节点
    EdgeNode* new_node = (EdgeNode*)malloc(sizeof(EdgeNode));
    new_node->adj_vex = v2;
    new_node->weight = weight;
    new_node->next = graph->adj_list[v1].first_edge;
    graph->adj_list[v1].first_edge = new_node;

    // 无向图需反向添加边
    new_node = (EdgeNode*)malloc(sizeof(EdgeNode));
    new_node->adj_vex = v1;
    new_node->weight = weight;
    new_node->next = graph->adj_list[v2].first_edge;
    graph->adj_list[v2].first_edge = new_node;

    graph->edge_num++;
}

// 打印邻接表
void printList(AdjListGraph* graph) {
    printf("邻接表：\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        printf("顶点%d: ", graph->adj_list[i].data);
        EdgeNode* p = graph->adj_list[i].first_edge;
        while (p != NULL) {
            printf("-> (%d, %d) ", p->adj_vex, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

// 释放邻接表内存
void freeGraph(AdjListGraph* graph) {
    for (int i = 0; i < graph->vertex_num; i++) {
        EdgeNode* p = graph->adj_list[i].first_edge;
        while (p != NULL) {
            EdgeNode* temp = p;
            p = p->next;
            free(temp);
        }
    }
}

// 测试
int main() {
    AdjListGraph graph;
    // 初始化5个顶点的图
    initGraph(&graph, 5);
    // 添加边
    addEdge(&graph, 0, 1, 1);
    addEdge(&graph, 0, 2, 1);
    addEdge(&graph, 1, 3, 1);
    addEdge(&graph, 2, 4, 1);
    // 打印邻接表
    printList(&graph);
    // 释放内存
    freeGraph(&graph);
    return 0;
}