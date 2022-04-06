#include "minishell.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

// extern char **environ;

int	average(int num, ...)
{
	va_list list;

	va_start(list, num);
	
	int sum = 0;
	for (int i = 0; i < num; i += 1)
	{
		printf("%i\n", va_arg(list, int));
	}
	return (sum);
}

int main(int argv, char **argc, char **envp)
{	
	int num = average(4, 1, 2, 3, 4, 5, 6, 7);
	
	printf("%i\n", num);
	return (0);
}