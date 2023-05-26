#include "header.h"

int main()
{
	char **cod = NULL;
	int nr_st = 0;
	graf harta;

	citire(&harta, &cod, &nr_st);

	char st1[MAX_CHAR_NR], st2[MAX_CHAR_NR];
	int cod_st1, cod_st2;

	printf("Introduceti statia de plecare: ");
	scanf("%s", st1);
	printf("\nIntroduceti destinatia finala: ");
	scanf("%s", st2);

	cod_st1 = caut_cod(cod, nr_st, st1);
	cod_st2 = caut_cod(cod, nr_st, st2);

	if (cod_st1 == -1 || cod_st2 == -1)
		printf("Introduceti statii existente!\n");
	else
		dijkstra(harta, cod_st1, cod_st2, cod);

	nr_st--;
	harta.n--;
	FREE_MAT((void **)cod, nr_st);
	FREE_MAT((void **)harta.mat, harta.n);
	return 0;
}