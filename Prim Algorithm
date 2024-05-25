#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

typedef struct GraphType
{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int get_min_vertex(int n)
{
    int v, i;
    for (int i = 0; i < n; i++)
    {
        //printf("sel : %d\n", selected[i]);
        if (!selected[i])
        {
            v = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!selected[i] && (distance[i] < distance[v]))
        {
            v = i;
        }        
    }
    return v;
}//end of get_min_vertex

void prim(GraphType* g, int s)
{
    int i, u, v;

    for (u = 0; u < g->n; u++)
    {
        distance[u] = INF;
    }
    distance[s] = 0;
    for (i = 0; i < g->n; i++)
    {
        u = get_min_vertex(g->n);
        //printf("u == %d\n", u);
        selected[u] = TRUE;
        if(distance[u] == INF)  return;
        printf("%d번 : 정점 %d 추가\n", i+1, u);
        for (v = 0; v < g->n; v++)
            if(g->weight[u][v] != INF)
                if(!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];
    }
}//end of prim

int main(void)
{
    // GraphType g = {7,
    // {{ 0, 29, INF, INF, INF, 10, INF },
    // {29, 0, 16, INF, INF, INF, 15 },
    // {INF, 16, 0, 12, INF, INF, INF },
    // {INF, INF, 12, 0, 22, INF, 18 },
    // {INF, INF, INF, 22, 0, 27, 25 },
    // {10, INF, INF, INF, 27, 0, INF },
    // {INF, 15, INF, 18, 25, INF, 0}}
    // };

    // GraphType g = {5,
    // {{ 0, 1, 3, INF, INF},
    // {1, 0, 3, 6, INF},
    // {3, 3, 0, 4, 3},
    // {INF, 6, 4, 0, 5},
    // {INF, INF, 2, 5, 0}}
    // };

    //수업 시연 예제
    GraphType g = {6,
    {{ 0, 6, 3, INF, INF, INF},
    {6, 0, 2, 5, INF, INF},
    {3, 3, 0, 3, 4, INF},
    {INF, INF, 3, 0, 2, 3},
    {INF, INF, 4, 2, 0, 5},
    {INF, INF, INF, 3, 5, 0}}
    };
    prim(&g, 0);
    return 0;
}//end of main
