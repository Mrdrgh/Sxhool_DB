#include "school.h"

/**
 * student_cli - a command interface for the students
 * @s: the student
*/
void student_cli(student *s)
{
	int out = 1;

	while (out != 2)
	{
		printf("----------- Student : %s %s ----------\n", s->name, s->last_name);
		printf("1-output my informations\n2-disconnect\n---> ");scanf("%d", &out);
		switch (out)
		{
			case 1:
				pause_clear();
				break;
			default:
				break;
		}
	}
}

/**
 * teacher_cli - a command interface for teachers and the principale
 * @t: the teacher struct
*/
void teacher_cli(teacher **t, student **s)
{
	int out = 1;
	char b[100];
	if ((*t)->is_the_manager)
		sprintf(b, "---------- Mr Principal : %s %s -------------\n", (*t)->name, (*t)->last_name);
	else
		sprintf(b, "---------- Teacher : %s %s --------------\n", (*t)->name, (*t)->last_name);
	while (out != 10)
	{
		printf("%s", b);
		printf("1- show the students DB\n2- (principal) show the teachers DB\n3- messaging commands\n5- add a student");
		printf("\n6- delete a student by CNE\n10- disconnect\n---> ");
		scanf("%d", &out);
		switch (out)
		{
			case 1:
				list_student(NULL, *s);
				break;
			case 2:
				list_teacher(NULL, *t);
				break;
			case 5:
				*s = add_struct_student(s);
				break;
			default:
				system("clear");
		}
	}
}