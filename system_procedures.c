#include "school.h"

/**
 * sleep_clear - sleeps and clears
 * @sleep_duration: the sleeping duration
*/
void sleep_clear(int sleep_duration)
{
	sleep(sleep_duration);
	system("clear");
}

/**
 * print_sleep_clear - prints a prompt, sleeps and then clears the stdout buffer
 * @prompt: the message to output
 * @sleepduration: the sleeping duration
*/
void print_sleep_clear(const char *prompt, int sleep_duration)
{
	printf("%s", prompt);
	fflush(stdout);
	sleep_clear(sleep_duration);
}

/**
 * pause_clear - pause and clear
*/
void pause_clear(void)
{
	pause();
	system("clear");
}

/**
 * pause _ this function acts as a pause procedure to wait the user's interaction
*/
void pause(void)
{
	printf("tap on any key to continue :");
	getchar();
}