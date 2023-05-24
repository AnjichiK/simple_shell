#include "shell.h"

/**
 * _strlen - RETURNS size of string
 * @s: STRING to check size
 *
 * Return: INT len of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - DOES lexicogarphic COMPARISON of two strangs.
 * @s1: FIRST strang
 * @s2: SECOND strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, else zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - CHECKS if needle begins with HAYSTACK
 * @haystack: STRING to CHECK
 * @needle: SUBSTRING to CHECK
 *
 * Return: ADDRESS of next CHAR of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - CONCATENATES strings
 * @dest: DESTINATION buf
 * @src: SOURCE buf
 *
 * Return: POINTER to destination buf
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

