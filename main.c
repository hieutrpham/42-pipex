#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

/*Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?*/

int main()
{
	unlink("test.txt");
	int fd = open("test.txt", O_RDWR | O_CREAT);
	int f = fork();
	if (!f)
	{
		close(STDOUT_FILENO);
		printf("test\n");
		fprintf(stderr, "DEBUGPRINT[47]: main.c:21: fd=%d\n", fd);
	}
	else
	{
		printf("main test\n");
		fprintf(stderr, "DEBUGPRINT[48]: main.c:23: fd=%d\n", fd);
	}
}
