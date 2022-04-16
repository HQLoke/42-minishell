#include "minishell.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int main(int argc, char **argv, char **envp)
{	
	if (argc == 2)
	{
		if (argv[1] == "~")
			printf("AHA!\n");
	}

	return (0);
}