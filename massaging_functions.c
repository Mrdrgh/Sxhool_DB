#include "school.h"

/**
 * scream_to_school - a function for the principal to send a message to the whole school inbox, (students and teachers)
 * @student_list: the students list
 * @teacher_list: the teachers list
 * @t: the principal's struct
 * @s: the student struct
*/

void scream_to_school(teacher **teacher_list, teacher **t,student **student_list, student **s)
{
	student *s_current;
	teacher *t_current;
	char *message = NULL, c, sender[200];
	size_t i = 0;

	if (!teacher_list && !student_list)
	{
		perror("error: scream_to_school: structs may be empty");
		exit(NULL_ERROR);
	}
	sprintf(sender, "(Principal) %s %s: ", (*t)->name, (*t)->last_name);
	printf("Write the message to send to all the school : ");
	while ((c = getchar()) != '\n' && c != EOF) { }
	getline(&message, &i, stdin);
	s_current = *student_list;
	if (s_current)
	{
		while (s_current)
		{
			s_current->inbox[s_current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));
			s_current->inbox = realloc(s_current->inbox, ((s_current->inbox_sz) + 1) * sizeof(char *));
			s_current->inbox_sz++;
			s_current = s_current->next;
		}
	}
	else
	{
		printf("!! students struct may be empty !!\n");
	}
	t_current = *teacher_list;
	if (t_current)
	{
		while (t_current)
		{
			if (!t_current->is_the_manager)
			{
				t_current->inbox[t_current->inbox_sz - 1] = strdup(message);
				t_current->inbox = realloc(t_current->inbox, ((t_current->inbox_sz) + 1) * sizeof(char *));
				t_current->inbox_sz++;
			}
			t_current = t_current->next;
		}
	}
	else
	{
		printf("!! error: teachers struct may be empty !!\n");
	}
	print_sleep_clear("MESSAGE SENT", 2);
}