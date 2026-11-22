#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * Prints the number of args passed to the program
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	(void)argv;
	printf("%d\n", (argc - 1));
	return (0);
}
