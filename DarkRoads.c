#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	unsigned u, v, w;

} vertice;

#define true 1
#define false 0
#define MAXSIZE 200100

vertice grafo[MAXSIZE];
int p[MAXSIZE];

int parent(int i)
{

	if (i == p[i])
		return i;

	return parent(p[i]);

}

int kruskal(int c)
{

	int i, v, u;
	unsigned resposta;

	for (i = 0, resposta = 0; i < c; ++i)
	{

		v = parent(grafo[i].v);
		u = parent(grafo[i].u);

		if (u != v)
			p[v] = p[u], resposta += grafo[i].w;

	}

	return resposta;

}

int compara(vertice *a, vertice *b)
{

	return a->w - b->w;

}

int main(int argc, char **argv)
{

	int e, v;

	while (scanf("%d %d", &e, &v), e && v)
	{

		int i;
		unsigned total = 0;
		for (i = 0; i < v; ++i)
			scanf("%d %d %d", &grafo[i].v, &grafo[i].u, &grafo[i].w), total += grafo[i].w;

		qsort(grafo, v, sizeof(vertice), compara);

		for (i = 1; i <= e; ++i)
			p[i] = i;

		printf("%u\n", total - kruskal(v));

		memset(grafo, 0, sizeof(grafo));
		memset(p, 0, sizeof(p));

	}

	return 0;

}
