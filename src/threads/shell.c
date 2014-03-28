/* thread/shell.c
 * This file is created by Yuqi Liu <yuqiliu@udel.edu>
 * for the purpose of making a shell inside Pintos.
 */

#include "shell.h"
#define MAX_CHAR_USER 32
#define MAX_CHAR_INPUT 255

char user[MAX_CHAR_USER];
char cmd_input[MAX_CHAR_INPUT];

/* The shell's entry function */
int
shell(void)
{
    shell_init();
    printf("Pintos Shell started running!\n");

	/* This is the iteration of shell execution */
    while (1) {
	    printf("[%s@Pintos]# ", user);
        getline(cmd_input);
        check_char_memory_bound(cmd_input, MAX_CHAR_INPUT);
        find_cmd();
        prepare_for_next_cycle();
    }

    return 0;
}

/* This function returns 0 if the input is within bound,
 *   and the actual length of the string. */
int
check_char_memory_bound(char* to_check, int size)
{
	int length = strlen(to_check);
	if (length >= size) {
		printf("sh: error: memory corrupted!\n");
		printf("sh: accepted input was %d, actual input is %d!\n", size-1, length);
		exit(0); /* I just exit to prevent harm to the system */
	}
	else return 0;
}

/* clean up the routinely used variables, creating a clean 
 * environment for the next iteration of shell execution.
 * This is EXTREMELY IMPORTANT in C programs, if you don't
 * want to get into NASTY and WEIRD problems!
 */
void
prepare_for_next_cycle(void)
{
	memset(cmd_input, 0, sizeof(cmd_input));
}

/* The initialization function of the shell */
void
shell_init(void)
{
	strlcpy(user, "root", 5);
}

/* Find the internal command (and probably out-source cmds later)
 * to execute */
void
find_cmd(void)
{
	/* input was an empty command, doing nothing */
	if (strcmp(cmd_input, "") == 0) 
		return; 
		
	printf("You just entered %s\n", cmd_input);
	/* start searching for known commands */
	if (strcmp(cmd_input, "exit") == 0)
	    exit(0);
	else {
		printf("Command %s not found!\n", cmd_input);
	}
}
