/* thread/shell.h 
 * This header file is created by Yuqi Liu <yuqiliu@udel.edu>.
 */
 
#ifndef H_SHELL
#define H_SHELL
#include <stdio.h>
#include "user/syscall.h"

/* The shell's entry function */
int
shell(void);

/* The initialization function of the shell */
void
shell_init(void);

/* Find the internal command to execute */
void
find_cmd(void);

/* clean up the routinely used variables,
 * creating a clean environment for the next
 * iteration of shell execution.
 */
void
prepare_for_next_cycle(void);

/* This checks whether input is within bound limit of a string or
 * an array of chars. The C library of pintos didn't check memory
 * corruption, therefore as Yuqi's observation we can freely 
 * modify lots of memory after the blocks allocated for the 
 * string. The function is to prevent this, which can be a 
 * disaster, from happening.
 * 
 * Also, if anyone want to perform this check, it's always fun to
 * implement this functionality in the Pintos C library, which I 
 * believe is a great practise!!! */
int
check_char_memory_bound(char* to_check, int size);
#endif
