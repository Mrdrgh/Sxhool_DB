#include "school.h"

/**
 * init_union - initializes the union
 * @u: the union
*/
student_teacher *init_union(student_teacher *s_t)
{
	s_t = malloc(sizeof(student_teacher));
	s_t->t = NULL;
	s_t->s = NULL;
	return (s_t);
}

/**
 * init_struct_students - initializes the struct of students
 * @s: the struct
*/
student *init_struct_students(student *s)
{
	s = malloc(sizeof(student));
	s->next = NULL;
	return (s);
}

/**
 * init_struct_teachers - initalizes the struct of teachers
 * @t: the teachers struct
*/
teacher *init_struct_teachers(teacher *t)
{
	t = malloc(sizeof(teacher));
	t->next = NULL;
	return (t);
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
	printf("\nPASSWORD : ");scanf("%s", s->password);
	while (i < 4)
	{
		printf("\nNOTE %d: ", i);scanf("%f", &s->notes[i++]);
	}
	print_sleep_clear("\nALL DONE..", 2);
}

/**
 * add_struct_student - adds a struct into the heap of structs
 * @s: the heap
 * Return: in case if return , we return the newly allcated list of structs
*/
student *add_struct_student(student *s)
{
	student *new_student = malloc(sizeof(student));

	if (!new_student)
	{
		perror("error: add_struct_student");
		exit(MALLOC_ERROR);
	}
	ask_student_info(new_student);
	new_student->next = s;
	s = new_student;
	return (s);
}

/**
 * ask_teacher_info - a procedure to ask for the teacher's infos
 * @t: the teacher
*/
void ask_teacher_info(teacher *t)
{
	if (!t)
	{
		perror("error: ask_teacher_info");
		exit(ASK_TEACHER_INFO_ERROR);
	}
	printf("NAME : ");scanf("%s", t->name);
	printf("\nLAST NAME : ");scanf("%s", t->last_name);
	printf("\nBIRTHDAY (dd/mm/yyyy): ");scanf("%s", t->birthdate);
	printf("\nCNI : ");scanf("%s", t->CNI);
	printf("\nPASSWORD : ");scanf("%s", t->password);
	t->is_the_manager = false;
	print_sleep_clear("ALL DONE ..", 1);
}

/**
 * add_struct_teacher - adds a struct of teacher
 * @t: the newly created struct will be the head of the heap
 * Return: the newly created struct that is the list
*/
teacher *add_struct_teacher(teacher *t)
{
	teacher *new_teacher = malloc(sizeof(teacher));

	if (!new_teacher)
	{
		perror("error: add_struct_teacher");
		exit(MALLOC_ERROR);
	}
	ask_teacher_info(new_teacher);
	new_teacher->next = t;
	t = new_teacher;
	return (t);
}