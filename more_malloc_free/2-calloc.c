#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size in bytes of each element
 *
 * Return: pointer to the memory, or NULL on failure or if nmemb or size is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int total;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
