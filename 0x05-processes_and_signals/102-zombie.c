#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * infinite_while - a function that runs forever and returns nothing
 * Return: 0 in the end (never actually returns)
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - the entry to a program that creates 5 zombie processes
 * Return: 0 on success
 */
int main(void)
{
	int children = 0;
	pid_t pid;

	while (children < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Zombie process created, PID: %i\n", (int)getpid());
			exit(EXIT_SUCCESS);
		}
		children++;
	}

	if (pid != 0)
		infinite_while();

	return (0);
}
