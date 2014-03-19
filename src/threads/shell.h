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

#endif
