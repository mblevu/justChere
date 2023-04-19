#include "shell.h"

/**
 * get_path - get path of executable
 * @command: pointer to the command
 * @envp: double pointer to the envitonment path
 * Return: return full  path if found and NULL if not
 */

char *get_path(char *command, char **envp)
{
	char *path = NULL;
	char *pathenv = NULL;
	char *dir = NULL;
	char *fullpath = NULL;

	/* get path environment variable*/
	while (*envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
		{
			pathenv = *envp;
			break;
		}
		envp++;
	}
	if (!pathenv)
	{
		return (NULL);
	}
	/* copy the PATH environment vriable to a separate buffer */
	path = (char *) malloc(strlen(pathenv) - 4);
	strncpy(path, pathenv + 5, strlen(pathenv) - 5);

	/* search for command in each directory */
	dir = strtok(path, ":");
	while (dir)
	{
		fullpath = (char *) malloc(strlen(dir) + strlen(command) + 2);
		sprintf(fullpath, "%s/%s", dir, command);

		if (access(fullpath, X_OK) == 0)
		{
			free(path);
			return (fullpath);
		}
		free(fullpath);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
