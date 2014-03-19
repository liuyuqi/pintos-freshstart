/* thread/shell.c
 * This file is created by Yuqi Liu <yuqiliu@udel.edu>
 * for the purpose of making a shell inside Pintos.
 */

#include "shell.h"

char user[32];
char input[255];

/* The shell's entry function */
int
shell(void)
{
    shell_init();
    printf("Pintos Shell started running!\n");

    while (1) {
	    printf("[%s@Pintos]# ", user);
        getline(input);
        printf("You just entered %s\n", input);
        find_cmd();
    }

    return 0;
}

/* The initialization function of the shell */
void
shell_init(void)
{
	strlcpy(user, "root", 5);
}

/* Find the internal command to execute */
void
find_cmd(void)
{
	if (strcmp(input, "exit") == 0)
	    exit(0);
}
