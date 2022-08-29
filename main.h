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

/* Take input - Split it into arguments - Execute command */
char *read_command(void);
char **read_args(char *);
int execute_command(char **, char **, char *);

/* Functions to handle commands */
char *get_PATH(char **);
char **make_copy(char **);
char *get_command(char *, char *);
char *is_path(char *, char *);
void print_env(char **);

/* Helper functions similar to those of the C Standard Library */
void free_2D(char **);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcpy(char *, char *);

#endif /* H */
