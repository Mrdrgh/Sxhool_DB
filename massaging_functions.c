#include "school.h"

/**
 * scream_to_school - a function for the principal to send a message to the whole school inbox, (students and teachers)
 * @student_list: the students list
 * @teacher_list: the teachers list
*/

void scream_to_school(teacher **teacher_list, student **student_list)
{
	student *s_current;
	teacher *t_current;
	char message[100], c;
	size_t i = 0;

	if (!teacher_list && !student_list)
	{
		perror("error: scream_to_school: structs may be empty");
		exit(NULL_ERROR);
	}
	printf("Write the message to send to all the school : ");
	scanf("%s", message);
	s_current = *student_list;
	if (s_current)
	{
		while (s_current)
		{
			s_current->inbox[s_current->inbox_sz - 1] = message;
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
				t_current->inbox[t_current->inbox_sz - 1] = message;
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
	fflush(stdin);
	print_sleep_clear("MESSAGE SENT", 2);
}