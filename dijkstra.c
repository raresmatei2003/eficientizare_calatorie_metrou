#include "header.h"

void dijkstra(graf v, int start, int end, int *traseu, char **cod)
{
    int dist[100], vizitat[100], i, j, next, distmin, p;
    for (i = 0; i < v.n; i++)
        for (j = 0; j < v.n; j++)
            if (v.mat[i][j] == 0 && i != j)
                v.mat[i][j] = 300;
    for (i = 0; i < v.n; i++)
    {
        dist[i] = v.mat[start][i];
        vizitat[i] = 0;
    }
    dist[start] = 0;
    vizitat[start] = 1;
    traseu[start] = -1;
    p = start;
    while (p != end)
    {
        distmin = 300;
        for (i = 0; i < v.n; i++)
            if (dist[i] < distmin && vizitat[i] == 0)
            {
                distmin = dist[i];
                next = i;
            }
        if (p == start)
            traseu[next] = p;
        vizitat[next] = 1;
        p = next;
        for (i = 0; i < v.n; i++)
            if (distmin + v.mat[next][i] < dist[i])
            {
                traseu[i] = next;
                dist[i] = distmin + v.mat[next][i];
            }
    }
    printf("\nDistanta de la %s la %s: %d", cod[start], cod[end], dist[end]);
    printf("\n");
}