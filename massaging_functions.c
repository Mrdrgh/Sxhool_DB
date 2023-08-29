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
				t_current->inbox[t_current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));;
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

/**
 * whisper_to_teachers - a function for the principal to send a message to only the teachers
 * @teacher_list: the teachers list
 * @t: the principal struct
*/

void whisper_to_teachers(teacher **teacher_list, teacher **t)
{
	teacher *current;
	char sender[200], c, *message = NULL;
	size_t i = 0;

	system("clear");	
	if (!(*teacher_list)->next)
	{
		print_sleep_clear("NO TEACHER ON THE PLATFORM", 1);
		return;
	}
	sprintf(sender, "(Principal) %s %s: ", (*t)->name, (*t)->last_name);
	printf("Write the message to send to all the teachers : ");
	while ((c = getchar()) != '\n' && c != EOF) { }
	getline(&message, &i, stdin);
	current = *teacher_list;
	while (current)
	{
		while (current)
		{
			if (!current->is_the_manager)
			{
				current->inbox[current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));;
				current->inbox = realloc(current->inbox, ((current->inbox_sz) + 1) * sizeof(char *));
				current->inbox_sz++;
			}
			current = current->next;
		}
	}
	print_sleep_clear("MESSAGE SENT", 1);
}

/**
 * send_msg_to_student - sends a message to a specific student
 * @student_list: the students list
 * @t: the teacher's struct (or manager)
*/

void send_msg_to_student(student **student_list, teacher **t)
{
	char sender[200], c, *message = NULL, temp_cne[11];
	student *current;
	size_t i = 0;

	if (!*student_list)
	{
		perror("error: send_msg_to_student: struct may be empty");
		exit(NULL_ERROR);
	}
	system("clear");

	if ((*t)->is_the_manager)
		sprintf(sender, "(Principal) %s %s: ", (*t)->name, (*t)->last_name);
	else
		sprintf(sender, "(Teacher) %s %s: ", (*t)->name, (*t)->last_name);

againn:

	printf("Input the student CNE to send a message to (or type 'no' or 'n' to cancel): ");scanf("%s", temp_cne);
	if (!strcmp(temp_cne, "no") || *temp_cne == 'n')
	{
		print_sleep_clear("CANCELLED", 1);
		return;
	}
	printf("The message : ");
	while ((c = getchar()) != '\n' && c != EOF) { }
	getline(&message, &i, stdin);

	current = *student_list;
	while (current)
	{
		if (!strcmp(current->CNE, temp_cne))
		{
			current->inbox[current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));
			current->inbox = realloc(current->inbox, ((current->inbox_sz) + 1) * sizeof(char *));
			current->inbox_sz++;
			print_sleep_clear("MESSAGE SENT", 1);
			return;
		}
		current = current->next;
	}
	print_sleep_clear("CNE NOT EXISTING", 1);
	goto againn;
}

/**
 * send_msg_to_teacher - sends a message to a specific teacher
 * @teacher_list: the students list
 * @t: the pricipal struct
*/

void send_msg_to_teacher(teacher **teacher_list, teacher **t)
{
	char sender[200], c, *message = NULL, temp_cni[11];
	teacher *current;
	size_t i = 0;

	if (!(*teacher_list)->next)
	{
		perror("error: send_msg_to_teacher: struct may be empty");
		exit(NULL_ERROR);
	}
	system("clear");

	if ((*t)->is_the_manager)
		sprintf(sender, "(Principal) %s %s: ", (*t)->name, (*t)->last_name);
	else
		sprintf(sender, "(Teacher) %s %s: ", (*t)->name, (*t)->last_name);

againn:

	printf("Input the teacher CNI to send a message to (or type 'no' or 'n' to cancel): ");scanf("%s", temp_cni);
	if (!strcmp(temp_cni, "no") || *temp_cni == 'n')
	{
		print_sleep_clear("CANCELLED", 1);
		return;
	}
	if (!strcmp(temp_cni, "FC65138"))
	{
		print_sleep_clear("NOT ON THIS COMMAND, TRY COMMAND 3", 2);
		return;
	}
	printf("The message : ");
	while ((c = getchar()) != '\n' && c != EOF) { }
	getline(&message, &i, stdin);

	current = *teacher_list;
	while (current)
	{
		if (!strcmp(current->CNI, temp_cni))
		{
			current->inbox[current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));
			current->inbox = realloc(current->inbox, ((current->inbox_sz) + 1) * sizeof(char *));
			current->inbox_sz++;
			print_sleep_clear("MESSAGE SENT", 1);
			return;
		}
		current = current->next;
	}
	print_sleep_clear("CNE NOT EXISTING", 1);
	goto againn;
}

/**
 * send_msg_to_principal - sends a message to the principal, only for teachers
 * @t: the teacher struct
 * @teacher_list: the teachrs list
*/

void send_msg_to_principal(teacher **teacher_list, teacher **t)
{
	char sender[200], c, *message = NULL;
	size_t i = 0;
	teacher *current;

	if (!(*teacher_list)->next || !*t)
	{
		perror("error: send_msg_to_principal: teacher struct is null");
		exit(NULL_ERROR);
	}
	system("clear");
	current = *teacher_list;
	sprintf(sender, "(Teacher) %s %s: ", (*t)->name, (*t)->last_name);
	printf("input the message to send to the principal : ");
	while ((c = getchar()) != '\n' && c != EOF) { }
	getline(&message, &i, stdin);
	while (current)
	{
		if (current->is_the_manager)
		{
			current->inbox[current->inbox_sz - 1] = strcat(strdup(sender),strdup(message));
			current->inbox = realloc(current->inbox, ((current->inbox_sz) + 1) * sizeof(char *));
			current->inbox_sz++;
			print_sleep_clear("MESSAGE SENT", 1);
			return;
		}
		current = current->next;
	}
	perror("error: send_msg_principal : principal not found");
	exit(NOT_FOUND_ERROR);
}