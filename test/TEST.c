#include "minishell.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int main(int argc, char **argv, char **envp)
{	
	char	*dir;

	dir = getcwd(NULL, 0);
	
	printf("%s\n", dir);

	return (0);
}