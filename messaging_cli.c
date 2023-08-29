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
again:
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
			goto again;
			break;
		case 2:
			whisper_to_teachers(teacher_list, t);
			goto again;
			break;
	}

	system("clear");
}