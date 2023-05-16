#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1100

typedef struct _g {
    int u, v;
    double w;
} GraphEdge;

int parent[MAXSIZE];
GraphEdge graph[MAXSIZE];

int findParent(int);
double kruskal(int, int);

int compareEdges(const void *, const void *);

int x;
double t;

int main(int argc, char **argv)
{
    int q, c, i;

    while (scanf("%d %d %lf", &q, &c, &t), q && c && t)
    {
        for (i = 0; i < c; ++i)
            scanf("%d %d %lf", &graph[i].u, &graph[i].v, &graph[i].w);

        qsort(graph, c, sizeof(GraphEdge), compareEdges);
        printf("%.2lf ", kruskal(c, q));
        printf("%d\n", x);
    }

    return 0;
}

int compareEdges(const void *a, const void *b)
{
    GraphEdge *edgeA = (GraphEdge *)a;
    GraphEdge *edgeB = (GraphEdge *)b;

    double tmp = edgeA->w - edgeB->w;

    if (tmp == 0.0)
        return 0;
    else if (tmp > 0.0)
        return 1;
    else
        return -1;
}

int findParent(int node)
{
    if (parent[node] == node)
        return node;

    return findParent(parent[node]);
}

double kruskal(int numEdges, int q)
{
    int i;
    double ans = 0;

    for (i = 0; i <= q; ++i)
        parent[i] = i;

    x = 0;
    for (i = 0; i < numEdges; ++i)
    {
        int u = findParent(graph[i].u);
        int v = findParent(graph[i].v);

        if (u != v)
        {
            parent[u] = parent[v];

            if (graph[i].w > t)
                ans += graph[i].w + 2, ++x;
            else
                ans += graph[i].w;
        }
    }

    return ans;
}
