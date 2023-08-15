#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


typedef struct info
{



} information_x;

typedef struct liststring
{
	int numberA;
	char *ptrstr;
	struct liststring *next;
} linked_x;

//getline

ssize_t read_process(information_x *ptrstruct);
void signal_int(__attribute__((unused))int signalnumber);
ssize_t chain_buffers(information_x ptrstruct, char **bufer, size_t n);
int custom_getline(information_x *ptrstruct, char **input_ptr, size_t length);
ssize_t takes_the_buffer(info_t ptrstruct, char *buf, size_t *s);

//getenviron

char **find_enviroment(information_x *ptrstruct);
int setenv(information_x *ptrstruct, char *add_var, char *equal);
int unsetenv(information_x *ptrstruct, char *rem_var);
//exits
char *find_char(char *string, char ch);
char *strncat_(char *dest, char *src, int x);
char *strcpy_(char *dest, char *src, int x);


#endif
