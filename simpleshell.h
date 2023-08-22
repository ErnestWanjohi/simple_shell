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

#define CHANGE_SMALL 1
#define CHANGE_UNSYMBOL 2
#define STUDY_BUFFER_LEN 1024
#define OUTPUT_BUFFER_LEN 1024
#define EMPTY_BUFFER -1
#define CUSTOM_LINE 0
#define TRUE_CHAIN 0
#define COMAND_TWO 1
#define COMAND_BOTH 2
#define COMAND_BOND 3
#define OLD_F "the history of shell"
#define FINAL_HIST 4096
typedef struct stringlist
{
	int numberA;
	char *ptrstr;
	struct stringlist *next;
} linked_x;


typedef struct info
{
	int outputfd;
	int wrong_number;
	char **argvector;
	int state;
	linked_x *environment;
	int argcount;
	linked_x *aka;
	int swapenv;
	char **env1;
	unsigned int band_length;
	char *fileidentity;
	char *argument;
	int lengthhist;
	int buf_identity;
	int flaglength;
	linked_x *thepast;
	char *way;
	char **prompt_buffer;





} information_x;

//getline

ssize_t read_process(information_x *ptrstruct);
void signal_int(__attribute__((unused))int signalnumber);
ssize_t chain_buffers(information_x *ptrstruct, char **bufer, size_t *n);
int custom_getline(information_x *ptrstruct, char **input_ptr, size_t *length);
ssize_t takes_the_buffer(information_x *ptrstruct, char *buf, size_t *s);
/* string.c*/
int length_string(char *sl);
int comparison(char *sl1, char *sl2);
char *begin(const char *hay_stack, const char *nidle);
char *concatenation(char *destination, char *source);

//getenviron

char **discover_env(information_x *ptrstruct);
int setenv_(information_x *ptrstruct, char *add_variable, char *equal);
int unsetenv_(information_x *ptrstruct, char *rem_var);
//exits
char *find_char(char *string, char ch);
char *strncat_(char *dest, char *src, int x);
char *stringcopy_(char *dest, char *src, int x);

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
void output_error(information_x *ptrstruct, char *stringerror);
int str_to_int(char *str);
int output_d(int value, int FD);
char *change_num(long int digit, int foundation, int flagz);
void eliminate_comments(char *bufA);
//HISTORY
int linked_hist(information_x *ptrstruct, char *bufferA, int counter);
int output_hist(information_x *ptrstruct);
char *wayback_file(information_x *ptrstruct);
int study_hist(information_x *ptrstruct);
//ENVIRON.C
int new_environment(information_x *ptrstruct);
char *value_env(information_x *ptrstruct, char *identity);
int now_environment(information_x *ptrstruct);
int delete_environment(information_x *ptrstruct);
int linked_environ(information_x *ptrstruct);
/*lists1.c*/
size_t listextent(const linked_x *he);
char **linkedstring(linked_x *hd);
size_t outputlinked(const linked_x *hd);
linked_x *beginnode(linked_x *our_node, char *before, char ch);
ssize_t findnode(linked_x *hd, linked_x *our_node);
/*list.c*/
linked_x *addupnode(linked_x **hd, const char *strn, int numA);
linked_x *finalisenode(linked_x **hd, const char *string, int numB);
size_t outputlinkedstr(const linked_x *k);
int eliminatenode(linked_x **hd, unsigned int index1);
void escapelist(linked_x **hdptr);

/*memory.c*/
int escapepointer(void **ptrA);
/*parser.c*/
int execcmd(information_x *ptrstruct, char *way);
char *copychars(char *waystring, int begin, int end);
char *locateway(information_x *ptrstruct, char *waystr, char *comand);
/* realloc.c*/
char *fillmemory(char *sm, char bsm, unsigned int q);
void escape(char **pstr);
void *memorychanger(void *omb, unsigned int os, unsigned int ns);
/*shell_loop*/
int big_loop(information_x *ptrstruct, char **vector);
int locatemadeup(information_x *ptrstruct);
void locatecomand(information_x *ptrstruct);
void newcomand(information_x *ptrstruct);
/*string1.c*/
char *stringduplicate(char *station, char *source);
char *string_duplicator(const char *string);
void _puts(char *stringA);
int _putchar(char ch);
/*tokenizer.c*/
char **stringsplitter(char *string, char *dlm);
char **stringtoword(char *string, char w);
/*vars.c*/
int chaincharchecker(information_x *ptrstruct, char *buffn, size_t *address);
void bond_checker(information_x *ptrstruct, char *buffz, size_t *address, size_t z, size_t extent);
int changefake(information_x *ptrstruct);
int variablechanger(information_x *ptrstruct);
int stringchanger(char **oaddress, char *naddress);
#endif
