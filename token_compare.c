#include "monty.h"

/* Funcion strcmp */
/**
 * _strcmp - compares two strings.
 * @s1: string
 * @s2: string
 *
 * Return: valor.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/* Funcion para encontar un caracter en la cadena */
int find_c(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			break;
		}
		i++;
	}
	if (s[i] == c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* funcion especial para tokenizar */
char *_strtok(char *s, char *d)
{
	static char *last;
	int i = 0, j = 0;

	if (!s)
	{
		s = last;
	}
	while (s[i] != '\0')
	{
		if (find_c(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last = s + i + 1;
			*last = '\0';
			s = s + j;
			return (s);
		}
		else if (find_c(d, s[i]) == 0 && find_c(d, s[i + 1]) == 0)
		{
			i++;
		}
		else if (find_c(d, s[i]) == 0 && find_c(d, s[i + 1]) == 1)
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return (s);
		}
		else if (find_c(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
