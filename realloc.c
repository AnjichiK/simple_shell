#include "shell.h"

/**
 * _memset - FILLS up memory with constant byte
 * @s: POINTER to memory AREA
 * @b: BYTE to fill *s with
 * @n: TOTAL bytes to fill
 * Return: (s) POINTER to MEMORY AREA s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - FREES up nested string
 * @pp: nested string
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - REALLOCATES memory block
 * @ptr: POINTER to previous malloc'ated BLOCK
 * @old_size: FORMER block SIZE
 * @new_size: NEW block SIZE
 *
 * Return: POINTER to former block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

