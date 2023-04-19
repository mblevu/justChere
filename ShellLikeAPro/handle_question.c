#include "shell.h"

/**
 * handle_question_mark - handle ? character
 * @status: exit status of child process
 * Return: void type
 */
void handle_question_mark(int status)
{
	if (WIFEXITED(status))
	{
		printf("Exit status: %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		printf("Terminated by signal %d\n", WTERMSIG(status));
	}
}
