#include "header.h"

int main()
{
	char **cod = NULL;
	int nr_st = 0;
	graf harta;
	map_init(&harta, nr_st);

	citire(&harta, &cod, &nr_st);

	return 0;
}