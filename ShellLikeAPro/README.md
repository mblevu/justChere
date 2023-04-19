Welcome to the world of UNIX command line interpreters! As you may already know, a command line interpreter is a program that takes in commands from the user and executes them in the underlying operating system. In this project, we will be building our own UNIX command line interpreter from scratch.

Our interpreter, called simple_shell, will display a prompt and wait for the user to enter a command. The prompt will be displayed again each time a command has been executed. Our interpreter will be able to handle errors and will display an error message if an executable cannot be found. Additionally, we will handle the "end of file" condition when the user presses Ctrl+D.

We will be using the execve function, which will be the core part of our simple_shell program. We will make sure to pass the environ variable to execve in order to properly execute the commands.

Let's get started and create our header file containing our own function prototypes. We will not be using standard libraries, so all the functions will be created from scratch. Our command lines will be simple, consisting of only one word without arguments, semicolons, pipes, or any other advanced features.

Are you ready to build your own UNIX command line interpreter? Let's go!
