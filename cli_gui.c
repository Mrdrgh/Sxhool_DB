#include "school.h"

/**
 * student_cli - a command interface for the students
 * @s: the student
*/
void student_cli(student *s)
{
	int out = 1;
	students_inbox(s);
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
				system("clear");
				break;
		}
	}
}

/**
 * teacher_cli - a command interface for teachers and the principale
 * @t: the teacher struct
*/
void teacher_cli(teacher **t, student **s, student **student_list)
{
	int out = 1;

	teachers_inbox(*t);
	(void) s;
	while (out != 10)
	{
		printf("---------- Teacher : %s %s --------------\n", (*t)->name, (*t)->last_name);
		printf("1- show the students DB\n2- messaging commands\n5- add a student");
		printf("\n6- delete a student by CNE\n10- disconnect\n---> ");
		scanf("%d", &out);
		switch (out)
		{
			case 1:
				list_student(NULL, *student_list);
				break;
			case 5:
				*student_list = add_struct_student(student_list);
				break;
			default:
				system("clear");
		}
	}
}

/**
 * principal_cli - a command interface for teachers and the principale
 * @t: the teacher struct
*/
void principal_cli(teacher **t, teacher **teacher_list, student **s, student **student_list)
{
	int out = 1;

	teachers_inbox(*t);
	(void) s;
	while (out != 10)
	{
		printf("---------- Mr Principal : %s %s --------------\n", (*t)->name, (*t)->last_name);
		printf("1- show the students DB\n2- (principal) show the teachers DB\n3- messaging commands\n4- add a student");
		printf("\n5- add a teacher\n6- delete a student by CNE\n10- disconnect\n---> ");
		scanf("%d", &out);
		switch (out)
		{
			case 1:
				list_student(NULL, *student_list);
				break;
			case 2:
				list_teacher(NULL, *teacher_list);
				break;
			case 3:
				principal_messaging_cli(t, teacher_list, student_list);
				break;
			case 4:
				*student_list = add_struct_student(student_list);
				break;
			case 5:
				*teacher_list = add_struct_teacher(teacher_list);
				break;
			case 6:
				delete_student_struct(student_list);	
				break;
			default:
				system("clear");
		}
	}
}