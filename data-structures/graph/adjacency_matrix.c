// 图-邻接矩阵
#include <stdio.h>

// 最大顶点数
#define MAX_VERTICES 100

// 邻接矩阵结构体
typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_num; // 实际顶点数
} AdjMatrixGraph;

// 初始化图
void initGraph(AdjMatrixGraph *graph, int vertex_num) {
    graph->vertex_num = vertex_num;
    // 初始化矩阵为0（无边）
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

// 添加边（无向图，有向图则只赋值matrix[v1][v2]）
void addEdge(AdjMatrixGraph *graph, int v1, int v2, int weight) {
    if (v1 >= 0 && v1 < graph->vertex_num && v2 >= 0 && v2 < graph->vertex_num) {
        graph->matrix[v1][v2] = weight;
        graph->matrix[v2][v1] = weight;
    }
}

// 打印邻接矩阵
void printMatrix(AdjMatrixGraph *graph) {
    printf("邻接矩阵：\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        for (int j = 0; j < graph->vertex_num; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// 测试
int main() {
    AdjMatrixGraph graph;
    // 初始化5个顶点的图
    initGraph(&graph, 5);
    // 添加边（权重默认为1）
    addEdge(&graph, 0, 1, 1);
    addEdge(&graph, 0, 2, 1);
    addEdge(&graph, 1, 3, 1);
    addEdge(&graph, 2, 4, 1);
    // 打印矩阵
    printMatrix(&graph);
    return 0;
}
