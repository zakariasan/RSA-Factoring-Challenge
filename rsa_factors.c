
/**
 * main - main Rsa Implementation in the code
 *
 * Return: Always 0.
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	FILE *file;
	char *line;
	size_t size, i = 2, nbr;

	if(ac != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error Opnnig file : %s check permissions\n",
				av[1]);
		return(EXIT_FAILURE);
	}

	while (getline(&line, &size, file) != EOF)
	{
		nbr = atoi(line) / 2;
		i = 2;
		while (i < nbr)
		{
			if (nbr % i == 0)
			{
				printf("%lu=%lu*%lu\n", nbr, nbr/i, i);
				i = nbr;
			}
			i++;
		}
	}

	return (EXIT_SUCCESS);
}
