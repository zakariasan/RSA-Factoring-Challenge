#include "rsa_factors.h"
/**
* _atoi - Convert a string to an integer.
* @s: String input.
*
* Description: function that convert a string to an integer.
* Return: int value from String.
*/
int _atoi(char *s)
{
	int i;
	size_t nbr;
	int n;

	nbr = 0;
	i = 0;
	n = 1;
	while ((s[i] < '0' || s[i] > '9') && s[i])
	{
		if (s[i] == '-')
			n *= -1;
		i++;
	}
	if (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		while (s[i] >= '0' && s[i] <= '9' && s[i])
		{
			nbr = nbr * 10 + s[i] - '0';
			i++;
		}
	}
	return (n * nbr);
}
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
	size_t  nbr, i;

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
		nbr = atoi(line);
		i = 2;
		while (i <= (nbr / 2))
		{
			if (nbr % i == 0)
			{
				printf("%ld=%ld*%ld\n", nbr, nbr / i, i);
				i = nbr;
			}
			i++;
		}
	}

	return (EXIT_SUCCESS);
}
