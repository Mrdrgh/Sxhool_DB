#include "school.h"

/**
 * principal_messaging_cli - a messaging sub-gui for the principal, it has many functionallites
 * @t: the struct of the principal
 * @teacher_list: the list of all the teachers
 * @student_list: the list of all the students
*/

void principal_messaging_cli(teacher **t, teacher **teacher_list, student **student_list)
{
	int i = 0;

	if (!t)
	{
		perror("error: principal_messaging_cli: (null) in principal struct");
		exit(NULL_ERROR);
	}
	system("clear");
agai:
	printf("1- Scream to the school\n2- Whisper to the teachers\n3- Send message to specific student\n4- Send message to specific teacher\n5- Exit the messaging cli\n---> ");
	scanf("%d", &i);
	fflush(stdin);
	while (i != 1 && i!= 2 && i != 3 && i != 4 && i != 5)
	{
		print_sleep_clear("NOT A COMMAND", 1);
		printf("1- Scream to the school\n2- Whisper to the teachers\n3- Send message to specific student\n4- Send message to specific teacher\n5- Exit the messaging cli\n---> ");
		scanf("%d", &i);
		fflush(stdin);
	}
	switch (i)
	{
		case 1:
			scream_to_school(teacher_list, t, student_list, NULL);
			download_struct_student(student_list);
			goto agai;
			break;
		case 2:
			whisper_to_teachers(teacher_list, t);
			goto agai;
			break;
		case 3:
			send_msg_to_student(student_list, t);
			download_struct_student(student_list);
			goto agai;
			break;
		case 4:
			send_msg_to_teacher(teacher_list, t);
			goto agai;
			break;
	}

	system("clear");
}

/**
 * teacher_messaging_cli - a messaging sub-gui for the principal, it has many functionallites
 * @t: the struct of the teacher
 * @teacher_list: the list of all the teachers
 * @student_list: the list of all the students
*/

void teacher_messaging_cli(teacher **t, teacher **teacher_list, student **student_list)
{
	int i = 0;

	if (!*t)
	{
		perror("error: teacher_messaging_cli: (null) in teacher struct");
		exit(NULL_ERROR);
	}
	system("clear");
againnnn:
	printf("1- send message to specific student\n2- send message to specific teacher\n3- send message to principal\n4- exit the messaging cli\n---> ");
	scanf("%d", &i);
	while (i != 1 && i!= 2 && i != 3 && i != 4)
	{
		print_sleep_clear("NOT A COMMAND", 1);
		printf("1- send message to specific student\n2- send message to specific teacher\n3- send message to principal\n4- exit the messaging cli\n---> ");
		scanf("%d", &i);
		fflush(stdin);
	}
	switch (i)
	{
		case 1:
			send_msg_to_student(student_list, t);
			download_struct_student(student_list);
			goto againnnn;
			break;
		case 2:
			send_msg_to_teacher(teacher_list, t);
			goto againnnn;
			break;
		case 3:
			send_msg_to_principal(teacher_list, t);
			goto againnnn;
			break;
	}

	system("clear");
}