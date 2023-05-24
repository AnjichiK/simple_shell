#include "shell.h"

/**
 * _eputs - OUTPUTS input string
 * @str: string to OUTPUT
 *
 * Return: NOTHING
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - PRINTS CHAR c to stderr
 * @c: CHAR to PRINT
 *
 * Return: 1 IF success.
 * On error, -1 is Returned, then errno set.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - PRINTS CHAR c to given fd
 * @c: CHAR for PRINTING
 * @fd: filedescriptor for PRINTING to
 *
 * Return: 1 if SUCCESS,.
 * On error, -1 RETURNED, then errno set.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - OUTPUTS the given string
 * @str: String for printing
 * @fd: filedescriptor for printing to
 *
 * Return: TOTAL CHARS put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

