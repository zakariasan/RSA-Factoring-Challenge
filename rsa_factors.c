#include "rsa_factors.h"
#include <stddef.h>
#include <stdio.h>

/**
 * main - main Rsa Implementation in the code
 * @ac: arg nbrs
 * @av: details args
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line;
	size_t size;
	size_t nbr, i;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error  file : %s check permisions\n", av[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &size, file) != EOF)
	{
		nbr = atoll(line);
		i = 2;
		while (i <= (nbr / 2))
		{
			if (nbr % i == 0)
			{
				printf("%ld=%ld*%ld\n", nbr, nbr / i, i);
				i = nbr + 2;
			}
			i++;
		}
	}
	if(line)
		free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
