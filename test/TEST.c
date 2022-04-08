#include "minishell.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

char *nani;

int main(int argc, char **argv, char **envp)
{	
	nani = ft_strdup("Hello ");

	printf("%s\n", nani);
	return (0);
}