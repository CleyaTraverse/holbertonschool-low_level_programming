#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * Prints all the arguments received by the program
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
