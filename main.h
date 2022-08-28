#ifndef H
#define H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

char *read_command(void);
char **read_args(char *);
int execute_command(char **, char **);

#endif /* H */
