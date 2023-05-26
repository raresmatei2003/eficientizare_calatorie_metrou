#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graf {
	int n;
	int **mat;
} graf;

void map_init(graf *harta, int nr);

void get_file_path(char *linie, char *file_path);

FILE *open_file(char *linie);

int caut_cod(char **cod, int nr_st, char nume_st[30]);

void get_codes(char *linie, char ***cod, int *nr_st);

void get_adj_mat(char *linie, char **cod, int nr_st, graf harta);

void citire(graf *harta, char ***cod, int *nr_st);

void dijkstra(graf v, int start, int end, int *traseu, char **cod);