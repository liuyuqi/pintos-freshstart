pintos-freshstart
=================
(NOTICE: Please read this file in Github for better reading.)
----------------------

Project description: a fresh start of pintos project

About my naive shell implementation
-------------
I implemented a really really simplified minimum functioning shell in Pintos (not trying to be modest). The whole idea was inspired by Bohu Huang and his research group in Xidian University. 

The reason I said my shell was "naive" is:
* This shell contains only ONE built-in command: <code>exit</code>. By typing exit in the terminal, it just makes Pintos halt (sounds like terrorist attack~~). No other commands were implemented.
* This shell runs inside the kernel, which is not bound to the convention. Traditionally a shell is a user-level program which is able to invoke system calls (and of course C library function calls) to perform some task. I did this in the kernel because I'm not really familiar with the userprog environment in Pintos yet. Perhaps trying the correct way after spring break (I hope).

My implementation
----------------
* In <code>Makefile.build</code> I added

  <pre><code>CPPFLAGS += DSHELL
  ...
  threads_SRC += threads/shell.c		# Our Shell
  threads_SRC += lib/user/syscall.c	# syscalls
  </code></pre>
  
  This is to make the shell code compile. In order not to spoil the original code written for pintos tests, I did this in a conditional compilation way, which is...

* In <code>threads/init.c</code>, I added
  <pre><code> #include "threads/shell.h"
 ...
 printf ("Boot complete.\n"); /*this is not in my addition, just to show you the position*/
 #ifdef SHELL
   shell();
 #endif 
  </code></pre>

* Created <code>shell.h</code> and <code>shell.c</code> , as in the repository.
* Added the following to <code>lib/stdio.h</code> :

<code>#include \<devices/input.h\> </code>

<code>void getline (char\*); /\*This is my newly-implemented getline function*/ </code>

* Added the following to <code>lib/stdio.c</code>:
 <pre><code>void getline(char* in)
 {
 	char cmd[255];
 	int i = 0;
 	while ((cmd[i] = input_getc()) != '\r') {
 	    printf("%c", cmd[i]);
 	    i++;
 	}
 	
 	cmd[i+1] = '\0';
 	strlcpy(in, cmd, strlen(cmd));
 	printf("\n");
 }
 </code></pre>

* And since we're using syscall.c in our kernel program, we change the following line in <code>lib/user/syscall.c</code> :

   original: <code>#include \<syscall.h\></code>
   
   modified: <code>#include "lib/user/syscall.h"</code>

Done.

What to do next?
----------------
Writing a shell is like reinventing the wheel. Therefore, whenever a working skeleton is successfully created, we should resume our work:
* A basic working file system (or else why do you need the shell?)
* Once a file system is done, we can try to modify the shell into a user program (instead of inside the kernel), and thus a user process when executed.
* Implement other system calls which are needed by built-in shell commands: 
  1. fork and exec: to be able to run a program and make it a new process.
  2. signals: makes the shell able to handle background execution.
  3. and perhaps many more...

I do have a working shell on Linux/Unix which can be a good reference. I'm working on it as OS homework in Spring 2014:

    https://github.com/liuyuqi/Operating-System-Homework-UD-CISC-663

Have fun hacking the kernel (and the shell)!
