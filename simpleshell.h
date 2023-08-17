#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H


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
	int outputfd;
	int wrong_number;
	char **argvector;
	int state;
	linked_x *environment;
	int argcount;





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
ssize_t takes_the_buffer(information_x ptrstruct, char *buf, size_t *s);

//getenviron

char **find_enviroment(information_x *ptrstruct);
int setenv(information_x *ptrstruct, char *add_var, char *equal);
int unsetenv(information_x *ptrstruct, char *rem_var);
//exits
char *find_char(char *string, char ch);
char *strncat_(char *dest, char *src, int x);
char *strcpy_(char *dest, char *src, int x);

//get info

void release_info(information_x *ptrstruct, int whole);
void begin_struct(information_x *ptrstruct, char **avector);
void start_information(information_x *ptrstruct);
//builtin
int change_directory(information_x *ptrstruct);
int gate_way(information_x *ptrstruct);
int now_cd(information_x *ptrstruct);

//builtin1
int alias_output(linked_x *our_node);
int way_back(information_x *ptrstruct);
int fake_alias(information_x *ptrstruct);
int remove_alias(information_x *ptrstruct, char *str);
int give_alias(information_x *ptrstruct, char *string);

//atoi
int joining(information_x *ptrstruct);
int alphabet(int ch);
int separator(char ch, char *delimeter);
int ascii_integer(char *string);
//errors.c
int putchar_error(char ch);
void string_input(char *string);
int write_str_fd(char *string, int FD);
int write_fd(char ch, int FD);
//errors1.c
void output_error(information_x ptrstruct, char *stringerror);
int str_to_int(char *str);
int output_d(int value, int FD);
char *change_num(long int digit, int foundation, int flagz);
void eliminate_comments(char *bufA);
//HISTORY
int linked_hist(information_x ptrstruct, char *bufferA, int counter);
int output_hist(information_x *ptrstruct);
char *wayback_file(information_x *ptrstruct);
int study_hist(information_x *ptrstruct);
//ENVIRON.C
int new_environment(information_x *ptrstruct);
char *value_env(information_x *ptrstruct, char *identity);
int now_environment(information_x *ptrstruct);
int delete_environment(information_x *ptrstruct);
int linked_environ(information_x *ptrstruct);
#endif