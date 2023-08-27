#include "school.h"

/**
 * init_union - initializes the union
 * @u: the union
*/
void init_union(student_teacher *s_t)
{
	s_t = malloc(sizeof(student_teacher));
}

/**
 * init_struct_students - initializes the struct of students
 * @s: the struct
*/
void init_struct_students(student *s)
{
	s = malloc(sizeof(student));
	s->next = NULL;
}

/**
 * init_struct_teachers - initalizes the struct of teachers
 * @t: the teachers struct
*/
void init_struct_teachers(teacher *t)
{
	t = malloc(sizeof(teacher));
	t->next = NULL;
}
/**
 * ask_student_info - a procedure to ask for the student infos
 * @s: the student
*/
void ask_student_info(student *s)
{
	int i = 0;

	if (!s)
	{
		perror("error: ask_student_info (null) is found");
		exit(ASK_STUDENT_INFO_ERROR);
	}
	printf("NAME : ");scanf("%s", s->name);
	printf("\nLAST NAME : ");scanf("%s", s->last_name);
	printf("\nBIRTH DATE (dd/mm/yyyy) : ");scanf("%s", s->birthdate);
	printf("\nCNE: ");scanf("%s", s->CNE);
	while (i < 4)
	{
		printf("\nNOTE %d: ", i);scanf("%0.2f", &s->notes[i++]);
	}
	print_sleep_clear("ALL DONE..", 1);
}
/**
 * add_struct_student - adds a struct into the heap of structs
 * @s: the heap
 * Return: in case if return , we return the newly allcated list of structs
*/
student *add_stuct_student(student *s)
{
	student *new_student = malloc(sizeof(student));

	if (!new_student)
	{
		perror("error: malloc");
		exit(MALLOC_ERROR_FOR_STRUCT_STUDENT);
	}
	ask_student_info(new_student);
	new_student->next = s;
	s = new_student;
	return (s);
}
