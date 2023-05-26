#include "header.h"

void map_init(graf *harta, int nr)
{
	int i;
	(*harta).n = nr;
	(*harta).mat = calloc((*harta).n, sizeof(int *));
	for (i = 0; i < (*harta).n; i++)
		*((*harta).mat + i) = calloc((*harta).n, sizeof(int));
}

void get_file_path(char *linie, char *file_path)
{
	strcpy(file_path, "input/M");
	strcat(file_path, linie);
	strcat(file_path, ".txt");
}

FILE *open_file(char *linie)
{
	char *file_path = malloc(15 * sizeof(char));
	get_file_path(linie, file_path);
	FILE *in = fopen(file_path, "r");

	free(file_path);
	return in;
}

int caut_cod(char **cod, int nr_st, char nume_st[30])
{
	int i;

	for (i = 0; i < nr_st; i++)
		if (!strcmp(*(cod + i), nume_st))
			return i;
	return -1;
}

void get_codes(char *linie, char ***cod, int *nr_st)
{
	FILE *in = open_file(linie);

	int n, i;
	fscanf(in, "%d", &n);

	char nume_st[MAX_CHAR_NR];
	int buffer;

	for (i = 0; i < n; i++) {
		fscanf(in, "%s%d", nume_st, &buffer);

		int poz = caut_cod(*cod, *nr_st, nume_st);

		if (poz == -1) {
			(*nr_st)++;
			*cod = (char **)realloc(*cod, (*nr_st) * sizeof(char *));
			*((*cod) + *nr_st - 1)
				= (char *)malloc((strlen(nume_st) + 1) * sizeof(char));
			strcpy(*((*cod) + *nr_st - 1), nume_st);
		}
	}

	fclose(in);
}

void get_adj_mat(char *linie, char **cod, int nr_st, graf harta)
{
	FILE *in = open_file(linie);

	int n, i;
	fscanf(in, "%d", &n);

	char nume_st1[MAX_CHAR_NR], nume_st2[MAX_CHAR_NR];
	int dist;

	fscanf(in, "%s", nume_st1);
	for (i = 0; i < n - 1; i++) {
		fscanf(in, "%d%s", &dist, nume_st2);

		int poz1 = caut_cod(cod, nr_st, nume_st1);
		int poz2 = caut_cod(cod, nr_st, nume_st2);

		*(*(harta.mat + poz1) + poz2) = dist;
		*(*(harta.mat + poz2) + poz1) = dist;

		strcpy(nume_st1, nume_st2);
	}

	fclose(in);
}

void citire(graf *harta, char ***cod, int *nr_st)
{
	int i;

	char linie[] = "1";
	for (i = 1; i <= NR_LINII; i++) {
		get_codes(linie, cod, nr_st);
		(*linie)++;
	}

	map_init(harta, *nr_st);

	strcpy(linie, "1");
	for (i = 1; i <= NR_LINII; i++) {
		get_adj_mat(linie, *cod, *nr_st, *harta);
		(*linie)++;
	}
}