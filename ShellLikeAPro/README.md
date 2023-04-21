Welcome to the world of UNIX command line interpreters! As you may already know, a command line interpreter is a program that takes in commands from the user and executes them in the underlying operating system. In this project, we will be building our own UNIX command line interpreter from scratch.

Our interpreter, called simple_shell, will display a prompt and wait for the user to enter a command. The prompt will be displayed again each time a command has been executed. Our interpreter will be able to handle errors and will display an error message if an executable cannot be found. Additionally, we will handle the "end of file" condition when the user presses Ctrl+D.

We will be using the execve function, which will be the core part of our simple_shell program. We will make sure to pass the environ variable to execve in order to properly execute the commands.

Let's get started and create our header file containing our own function prototypes. We will not be using standard libraries, so all the functions will be created from scratch. Our command lines will be simple, consisting of only one word without arguments, semicolons, pipes, or any other advanced features.

Are you ready to build your own UNIX command line interpreter? Let's go!

execute_command: This function takes a null-terminated array of strings as input, where the first element is the command to be executed and the remaining elements are its arguments. It uses fork() to create a child process, and then uses execvp() to execute the command in the child process. It also handles errors that may occur during the execution of the command.

get_path: This function takes the name of a command and the envp array as input, and returns the full path of the command if it is found in one of the directories listed in the PATH environment variable.

shell_exit: This function is called when the user enters the exit command. It takes an optional exit status as an argument and calls exit() to terminate the shell process.

print_env: This function prints the current environment variables to the standard output stream.

get_line: This function reads a line of input from the standard input stream and returns a pointer to a null-terminated string that represents the line. It dynamically allocates memory to store the string using malloc().

exit_with_status: This function is called when the user enters the exit command with an exit status argument. It takes the argument as a string, converts it to an integer using atoi(), and then calls exit() with the specified status.

set_env: This function is called when the user enters the setenv command. It takes two arguments: the name and value of the environment variable to be set. It then calls setenv() to set the variable.

unset_env: This function is called when the user enters the unsetenv command. It takes one argument: the name of the environment variable to be unset. It then calls unsetenv() to unset the variable.
