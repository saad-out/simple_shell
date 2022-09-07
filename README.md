# Simple_Shell 
![Alternate image text](https://iili.io/6a7r2j.png)
## What is the shell?
The shell is a program that takes commands from the keyboard via the terminal and gives them to the operating system to perform.
## About this project
This project is a simple version of the linux shell made for [ALX Software Engineering Programme](https://www.alxafrica.com/software-engineering-2022) taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.
It is created using the C programming Language and it can do many functionalities that a real shell does.
## installation:
### git clone https://github.com/saad-out/simple_shell.git
## Compilation:
> ### gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh**


### Project Done by:

[Hamza Annane](https://github.com/annanesec/) and [Saad Out](https://github.com/saad-out/)

:computer: List of allowed functions and system calls :computer:

| Function | Description |
| ----------- | ----------- |
| access|In Linux, access command is used to check whether the calling program has access to a specified file. It can be used to check whether a file exists or not. The check is done using the calling process’s real UID and GID.|
| chdir |The chdir command is a system function (system call) which is used to change the current working directory. On some systems, this command is used as an alias for the shell command cd. chdir changes the current working directory of the calling process to the directory specified in path.| 
| close | The close() function shall deallocate the file descriptor indicated by fildes. To deallocate means to make the file descriptor available for return by subsequent calls to open() or other functions that allocate file descriptors | 
| closedir |The closedir() function shall close the directory stream referred to by the argument dirp. Upon return, the value of dirp may no longer point to an accessible object of the type DIR. If a file descriptor is used to implement type DIR, that file descriptor shall be closed.| 
| execve | Execve() function is used for the execution of the program that is referred to by pathname. The exec family is used mainly in the C programming language and has many functions. These functions execute a system command in a separate process from the main program and print the output. | 
| exit |the exit function calls all functions registered with atexit and terminates the program. File buffers are flushed, streams are closed, and temporary files are deleted.| 
| _exit | The _Exit() function in C/C++ gives normal termination of a program without performing any cleanup tasks | 
| fflush | The fflush function in C is used to immediately flush out the contents of an output stream. This is particularly useful in displaying output, as the operating system may initially put the output data in a temporary buffer before writing it to an output stream or file like stdout. | 
| fork | Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process. | 
| free | The free() function in C library allows you to release or deallocate the memory blocks which are previously allocated by calloc(), malloc() or realloc() functions. It frees up the memory blocks and returns the memory to heap.| 
| getcwd | The getcwd() function shall place an absolute pathname of the current working directory in the array pointed to by buf, and return buf. The pathname copied to the array shall contain no components that are symbolic links. The size argument is the size in bytes of the character array pointed to by the buf argument. | 
| getline |The getline() function is part of the C library. This function accepts a string from the input stream as an input, so getline() is a better option. The concept of pointers is used by getline(). For reading text, the getline method is the ideal way. |




