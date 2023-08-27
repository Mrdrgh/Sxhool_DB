#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
void sleep_clear(int sleep_duration)
{
	sleep(sleep_duration);
	system("clear");
}
void print_sleep_clear(const char *prompt, int sleep_duration)
{
	printf("%s", prompt);
	sleep_clear(sleep_duration);
}
int main(void)
{
	char *args[] = {NULL};
	printf("Your text here");
fflush(stdout);  // Flush the output buffer
sleep(1);
system("clear");
	// print_sleep_clear("hello", 1);
	// print_sleep_clear("world", 1);
	// pid_t son;
	// son = fork();
	// if (son == 0)
	// {
	// 	sleep(1);
	// 	execvp("clear", args);
	// 	perror("error");
	// }
	// else
	// {
	// 	printf("hello world");
	// 	wait(NULL);
	// }
	// return (0);
}