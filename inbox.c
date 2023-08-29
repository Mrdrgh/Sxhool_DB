#include "school.h"

/**
 * students_inbox - invocs the inbox
 * @s: the struct of the student
*/

void students_inbox(student *s)
{
	int i = 0, j = 0;
	student *current;
	if (!s)
	{
		perror("error: students_inbox:");
		exit(NULL_ERROR);
	}
	current = s;
	system("clear");
	if (*current->inbox)
	{
		printf("INBOX :\n");
		while (current->inbox[i])
		{
			printf("------------------------------------\n");
			printf("%d- %s\n", i++, current->inbox[i]);
		}
		printf("---> 1 to conitinue : ");scanf("%d", &i);
		system("clear");
	}
	else
	{
		print_sleep_clear("EMPTY INBOX", 1);
	}
}

/**
 * teachers_inbox - invocs the inbox
 * @t: the struct of the teacher
*/

void teachers_inbox(teacher *t)
{
	int i = 0, j = 0;
	teacher *current;
	if (!t)
	{
		perror("error: teachers_inbox:");
		exit(NULL_ERROR);
	}
	current = t;
	system("clear");
	if (!t->is_the_manager)
	{
		if (current->inbox[i])
		{
			printf("INBOX :\n");
			while (current->inbox[i])
			{
				printf("-----------------------------------\n");
				printf("%d- %s\n", i++, current->inbox[i]);
			}
			printf("\n---> 1 to conitinue : ");scanf("%d", &i);
			system("clear");
		}
		else
		{
			print_sleep_clear("EMPTY INBOX", 1);
		}
	}
	else
	{
		if (current->inbox[0])
		{
			printf("INBOX :\n");
			while (current->inbox[i])
			{
				printf("---------------------------------\n");
				printf("%d- %s\n", i++, current->inbox[i]);
			}
			printf("---> 1 to conitinue : ");scanf("%d", &i);
			system("clear");
		}
		else
		{
			print_sleep_clear("EMPTY INBOX", 1);
		}
	}
}