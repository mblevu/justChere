#ifndef SHELL_H
#define SHELL_H

/* libraries used */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>


/* macros used */

#define DELIMITER " \t\r\n\a"
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_ARGS 128




/* function prototypes */

void print_prompt(void);
void execute_command(char **args);
char *get_path(char *command, char **envp);
void shell_exit(char **args);
void print_env(char **envp);
char *get_line(void);
void exit_status(char **args);
void set_env(char **args);
void unset_env(char **args);
void change_directory(char **args);
void execute_sequential(char **commands);
int execute_logical_op(char **args, int background);
void set_alias(char **args);
char **expand_variables(char **args, int *n);
void handle_question_mark(int status);
void handle_double_dollar(char **args);
void remove_comments(char *input);
char *my_strtok(char *str, const char *delim);
char *my_strpbrk(const char *s, const char *accept);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
int my_atoi(const char *str);







#endif
