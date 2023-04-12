#include "main.h"


int main(void)
{
    char *input;
    size_t input_size = 0;
    pid_t pid;
    int status;

    while(1)
    {
        printf("$ ");
        getline(&input, &input_size, stdin);

        if (feof(stdin))
        {
            printf("\n");
            break;
        }

        input[strlen(input) - 1] = '\0';

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid ==0)
        {
            execlp("sh", "sh", "-c", input, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        else
        {
            waitpid(pid, &status, 0);
            if (WEXITSTATUS(status) != 0)
            {
                printf("\n");
            }
        }

    }

    free(input);
    return (0);
    
}