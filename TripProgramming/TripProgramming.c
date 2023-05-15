#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 300
#define INF 0x3f3f3f3f

int p[MAXSIZE];
int caminho[MAXSIZE];
int distancia[MAXSIZE];
int adjacente[MAXSIZE][MAXSIZE];

void reverso(int *, int );

int tamanho;

int dijkstra(int d, int size)
{

    memset(p, -1, sizeof(p));
    bool visitado[MAXSIZE] = { false };

    for (int i = 0; i <= size; ++i)
        distancia[i] = INF;

    p[d] = d;
    distancia[d] = 0;

    for (int i = 0; i <= size; ++i)
    {

        int v = -1;
        for (int j = 0; j <= size; ++j)
            if (!visitado[j] && (v == -1 || distancia[j] < distancia[v]))
                v = j;

        if (distancia[v] == INF)
            break;

        visitado[v] = true;
        for (int j = 0; j <= size; ++j)
            if (distancia[v] + adjacente[v][j] < distancia[j])
                distancia[j] = adjacente[v][j] + distancia[v], p[j] = v;

    }

    int u = 1;
    tamanho = 0;

    while (p[u] != u)
        caminho[tamanho++] = u, u = p[u];

    caminho[tamanho] = d;

    reverso(caminho, tamanho + 1);

    return distancia[1];

}

void reverso(int *v, int n)
{

    for (int i = 0, j = n - 1; i < j; ++i, --j)
    {

        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;

    }

}

int main(int argc, char **argv)
{

    int numCidades, numEstradas, cidadeA, cidadeB, tempoMedio, cidadeDestino;

    while (scanf("%d %d", &numCidades, &numEstradas), numCidades && numEstradas)
    {

        for (int i = 0; i <= numCidades; ++i)
            for (int j = 0; j <= numCidades; ++j)
                adjacente[i][j] = INF;

        for (int i = 0; i < numEstradas; ++i)
        {

            scanf("%d %d %d", &cidadeA, &cidadeB, &tempoMedio);
            adjacente[cidadeA][cidadeB] = adjacente[cidadeB][cidadeA] = tempoMedio;

        }

        scanf("%d", &cidadeDestino);
        int resposta = dijkstra(cidadeDestino, numCidades);

        if (resposta <= 120)
            printf("Will not be late. ");
        else
            printf("It will be %d minutes late. ", resposta - 120);

        printf("Travel time - %d - best way -", resposta);

        for (int i = 0; i <= tamanho; ++i)
            printf(" %d", caminho[i]);

        printf("\n");

    }
    return 0;

}
