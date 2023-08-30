#include "school.h"

/**
 * students_inbox - invocs the inbox
 * @s: the struct of the student
*/

void students_inbox(student *s)
{
	FILE *fp;
	int i = 1, j = 0, k = 0;
	char message[10000];

	if (!s)
	{
		perror("error: students_inbox: the struct is empty");
		exit(NULL_ERROR);
	}
	fp = fopen(strcat("./students_inbox/", s->CNE), "r");

	if (!fp)
	{
		perror("error: students_inbox: file path not recognized");
		exit(FILE_IO_ERROR);
	}
	printf("INBOX : \n");
	while (fscanf(fp, "%s\n", message) > 0)
	{
		printf("%d- ", i++);
		while (message[k] != '\0')
		{
			j = 0;
			while (putchar(message[k]) && j < 50)
			{
				k++; j++;
			}
			printf("\n");
		}
	}
	printf("\ntype 1 to continue : ");scanf("%d", &i);
	fclose(fp);
	system("clear");
}

/**
 * teachers_inbox - invocs the inbox
 * @t: the struct of the teacher
*/

void teachers_inbox(teacher *t)
{
	FILE *fp;
	int i = 1, j = 0, k = 0;
	char *message = malloc(sizeof(char ) * 10000), filepath[1024];

	if (!t)
	{
		perror("error: teachers_inbox: the struct is empty");
		exit(NULL_ERROR);
	}
	if (t->is_the_manager)
	{
		sprintf(filepath, "./teachers_inbox/The_principal");
	}
	else
	{
		sprintf(filepath, "./teachers_inbox/%s", t->CNI);
	}
	fp = fopen(filepath, "w+");

	if (!fp)
	{
		perror("error: teachers_inbox: file path not recognized");
		exit(FILE_IO_ERROR);
	}
	printf("INBOX : \n");
	while (fscanf(fp, "%s\n", message) > 0)
	{
		printf("%d- ", i++);
		while (message[k] != '\0')
		{
			j = 0;
			while (putchar(message[k]) && j < 50)
			{
				k++; j++;
			}
			printf("\n");
		}
	}
	printf("\ntype 1 to continue : ");scanf("%d", &i);
	fclose(fp);
	system("clear");
}