# Simple_Shell 
## What is the shell?
The shell is a program that takes commands from the keyboard via the terminal and gives them to the operating system to perform.
## About this project
This project is a simple version of the linux shell made for [ALX Software Engineering Programme](https://www.alxafrica.com/software-engineering-2022) taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.
It is created using the C programming Language and it can do many functionalities that a real shell does.

### Project Done by:

[Hamza Annane](https://github.com/annanesec/) and [Saad Out](https://github.com/saad-out/)

:computer: Functions Used in This Project :computer:

| Function | Description |
| ----------- | ----------- |
| read_command|Function that reads command from user input|
| read_arg |split given buffer into command and it's arguments| 
| execute_command | executes given command if it exists | 
| make_copy |create copy of the environment varibales array of strings| 
| get_PATH | finds the path environment variable | 
| get_command |get full path of a command if it exists| 
| print_env | print the list of environment varibales | 
| is_path | check if a the given path exists or not. | 
| free_2D | frees 2 dimensional array | 
| _strlen | finds length of a string| 
| _strcmp | compares two strings | 
| _strcpy |copies string from source to destination |

# List of allowed functions and system calls for this project
:heavy_check_mark: access (man 2 access)
    :heavy_check_mark: chdir (man 2 chdir)
    :heavy_check_mark:close (man 2 close)
    :heavy_check_mark:closedir (man 3 closedir)
    :heavy_check_mark:execve (man 2 execve)
    :heavy_check_mark:exit (man 3 exit)
    :heavy_check_mark:_exit (man 2 _exit)
    :heavy_check_mark:fflush (man 3 fflush)
    :heavy_check_mark:fork (man 2 fork)
    :heavy_check_mark:free (man 3 free)
    :heavy_check_mark:getcwd (man 3 getcwd)
    :heavy_check_mark:getline (man 3 getline)
    :heavy_check_mark:getpid (man 2 getpid)
    :heavy_check_mark:isatty (man 3 isatty)
    :heavy_check_mark:kill (man 2 kill)
    :heavy_check_mark:malloc (man 3 malloc)
    :heavy_check_mark:open (man 2 open)
    :heavy_check_mark:opendir (man 3 opendir)
    :heavy_check_mark:perror (man 3 perror)
    :heavy_check_mark:read (man 2 read)
    :heavy_check_mark:readdir (man 3 readdir)
    :heavy_check_mark:signal (man 2 signal)
    :heavy_check_mark:stat (__xstat) (man 2 stat)
    :heavy_check_mark:lstat (__lxstat) (man 2 lstat)
    :heavy_check_mark:fstat (__fxstat) (man 2 fstat)
    :heavy_check_mark:strtok (man 3 strtok)
    :heavy_check_mark:wait (man 2 wait)
    :heavy_check_mark:waitpid (man 2 waitpid)
    :heavy_check_mark:wait3 (man 2 wait3)
    :heavy_check_mark:wait4 (man 2 wait4)
    :heavy_check_mark:write (man 2 write)




