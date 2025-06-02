#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int fd1[2];
    int fd2[2];
    pid_t p;

	if (pipe(fd1) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	if (pipe(fd2) == -1) {
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	p = fork();
	if (p < 0) {
		fprintf(stderr, "fork Failed");
		return 1;
	}
	else if (p > 0) {
		char input_str[100] = "hello from parent";
		char parent_str[100];
		close(fd1[0]);
		// Write input string and close writing end of first pipe
		write(fd1[1], input_str, strlen(input_str) + 1);
		close(fd1[1]);
		// Wait for child to send a string
		wait(NULL);
		close(fd2[1]); // Close writing end of second pipe
		read(fd2[0], parent_str, 100);
		printf("parent str: %s\n", parent_str);
		close(fd2[0]);
	}
	// child process
	else {
		close(fd1[1]);
		char parent_str[100];
		char child_str[100] = "hello from child";
		read(fd1[0], parent_str, 100);
		printf("child str: %s\n", parent_str);
		// Close both reading ends
		close(fd1[0]);
		close(fd2[0]);
		write(fd2[1], child_str, 100);
		close(fd2[1]);
		exit(0);
	}
}
