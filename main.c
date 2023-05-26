#include "header.h"

int main()
{
	char **cod = NULL;
	int nr_st = 0;
	graf harta;
	int *traseu;
	
	map_init(&harta, nr_st);
	
	citire(&harta, &cod, &nr_st);
	traseu=calloc(nr_st,sizeof(int));
	char st1[30], st2[30];
	int a,b;
	scanf("%s %s",st1,st2);
	a=caut_cod(cod,nr_st,st1);
	b=caut_cod(cod,nr_st,st2);
	dijkstra(harta,a,b,traseu,cod);
	printf("\n");
	return 0;
}