#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int pipefd1[2],
		pipefd2[2],
		pid;
	char buf[64];

	/**************************************************
	 * Communicate between parent and child using pipes
	 * ----------					 ------------
	 * |		|  ----pipefd1---->  |			|
	 * | Parent	|                    | Child	|
	 * |		|  <---pipefd2-----  |			|
	 * ----------                    ------------
	 *************************************************/

	pipe(pipefd1);
	pipe(pipefd2);

	if((pid = fork()) == -1) {
		printf("unable to fork, exiting\n");
	}
	else if(pid == 0) { //child
		//close write end of fd1 and read end of fd2
		close(pipefd1[1]);
		close(pipefd2[0]);
		printf("I am a child, waiting for parent to send a message.\n");
		read(pipefd1[0], buf, sizeof(buf));
		printf("Child: received %s, sending confirmation message\n", buf);
		write(pipefd2[1], "r", 2);

		//cleanup
		close(pipefd1[0]);
		close(pipefd2[1]);
	}
	else { //parent
		//close write end of fd2 and read end of fd1
		close(pipefd2[1]);
		close(pipefd1[0]);
		printf("I am a parent, enter a msg to send to child: ");
		gets(buf);
		printf("sending %s...\n", buf);
		write(pipefd1[1], buf, strlen(buf) + 1);
		printf("Waiting for confirmation from child...\n");
		read(pipefd2[0], buf, sizeof(buf));
		printf("Received confirmation, quitting!\n");
		wait(0);

		//cleanup
		close(pipefd2[0]);
		close(pipefd1[1]);
	}



	return 0;
}//end main
