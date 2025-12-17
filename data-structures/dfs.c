//图-深度优先搜索（DFS）
#include <stdio.h>
#include <stdbool.h>

// 基础配置
#define MAX_VERTICES 100  // 最大顶点数
#define INF 999999        // 无边标识

// 邻接矩阵存储图（DFS依赖的图结构）
typedef struct {
    char vertex[MAX_VERTICES];   // 顶点（0,1,2...）
    int matrix[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵
    int vertex_num; // 实际顶点数
} Graph;

// 图初始化（为DFS准备数据）
void initGraph(Graph* g, int n) {
    g->vertex_num = n;
    // 初始化顶点
    for (int i = 0; i < n; i++) g->vertex[i] = '0' + i;
    // 初始化无边
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->matrix[i][j] = INF;
}

// 添加无向边（为DFS准备测试数据）
void addEdge(Graph* g, int v1, int v2) {
    if (v1 >= 0 && v1 < g->vertex_num && v2 >= 0 && v2 < g->vertex_num) {
        g->matrix[v1][v2] = 1; // 简化：边权固定为1
        g->matrix[v2][v1] = 1;
    }
}

// 单独的深度优先遍历（DFS）核心函数
void DFS(Graph* g, int start, bool visited[]) {
    // 1. 访问当前顶点，标记为已访问
    printf("%c ", g->vertex[start]);
    visited[start] = true;

    // 2. 遍历所有邻接点，递归访问未访问的顶点
    for (int i = 0; i < g->vertex_num; i++) {
        if (g->matrix[start][i] != INF && !visited[i]) {
            DFS(g, i, visited); // 递归深入
        }
    }
}

// 主函数（仅测试DFS）
int main() {
    Graph g;
    initGraph(&g, 5); // 5个顶点的图

    // 添加测试边（构建图结构）
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);

    // 初始化访问标记（默认未访问）
    bool visited[MAX_VERTICES] = { false };

    // 执行DFS（从顶点0开始）
    printf("深度优先遍历结果：");
    DFS(&g, 0, visited);

    printf("\n");
    return 0;
}
