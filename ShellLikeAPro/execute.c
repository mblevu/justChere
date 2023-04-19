#include "shell.h"

/**
 * execute_command - executecommand typed
 * @args: pointer to the arguments
 * Return: void function
 */

void execute_command(char **args)
{
	int status;
	/*create child process */
	pid_t pid = fork();

	/*if fork failed */
	if (pid < 0)
	{
		fprintf(stderr, "fork failed\n");
		return;
	}
	/* if in chiled process */
	if (pid == 0)
	{
		execvp(args[0], args); /* execute command*/
		fprintf(stderr, "execvp failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	/* if in parent process wait for child to finish*/
	waitpid(pid, &status, 0);
}
