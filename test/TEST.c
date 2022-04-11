#include "minishell.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int main(int argc, char **argv, char **envp)
{	
	char *array;

	array = ft_strdup("Hello");
	int i = 0;
	while (array[i++])
	{
		printf("Hello\n");
	}

	return (0);
}