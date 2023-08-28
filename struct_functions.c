#include "school.h"

/**
 * init_union - initializes the union
 * @u: the union
*/
student_teacher *init_union(student_teacher *s_t)
{
	s_t = IS_NONE;
	return (s_t);
}

/**
 * init_struct_students - initializes the struct of students
 * @s: the struct
*/
student *init_struct_students(student *s)
{
	s = malloc(sizeof(student));
	s = NULL;
	return (s);
}

/**
 * init_struct_teachers - initalizes the struct of teachers
 * @t: the teachers struct
*/
teacher *init_struct_teachers(teacher *t)
{
	t = malloc(sizeof(teacher));
	t = NULL;
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
	print_sleep_clear("\nALL DONE..", 1);
}

/**
 * add_struct_student - adds a struct into the heap of structs
 * @s: the heap
 * Return: in case if return , we return the newly allcated list of structs
*/
student *add_struct_student(student **s)
{
	student *new_student = malloc(sizeof(student));

	if (!new_student)
	{
		perror("error: add_struct_student");
		exit(MALLOC_ERROR);
	}
	ask_student_info(new_student);
	new_student->next = *s;
	*s = new_student;
	return (*s);
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
teacher *add_struct_teacher(teacher **t)
{
	teacher *new_teacher = malloc(sizeof(teacher));

	if (!new_teacher)
	{
		perror("error: add_struct_teacher");
		exit(MALLOC_ERROR);
	}
	ask_teacher_info(new_teacher);
	new_teacher->next = *t;
	*t = new_teacher;
	return (*t);
}

/**
 * list_all_students - lists all the students by name and CNE
 * @s: the students struct
 * Return: waits for the user to type a CNE or a name to list the full details for this
 * student with the convenable cne , if its not found , output that the student doesn't exist
 * if the user doesn't want to out_put anything the function returns NULL
*/
char *list_all_students(student *s)
{
	student *current;
	char temp_cne_or_name[11];

	if (!s)
	{
		perror("error: list_all_students: struct may be empty");
		exit(NULL_ERROR);
	}
	current = s;
	while (current)
	{
		printf("_______________________________________\n");
		printf("NAME : %s\nLAST NAME : %s\nCNE : %s\n", current->name, current->last_name, current->CNE);
		current = current->next;
	}
	printf("_______________________________________\n");
	printf("type the CNE of the student to show more details of, or type \"no\" or 'n' : ");
	scanf("%s", temp_cne_or_name);
	return ((!strcmp(temp_cne_or_name, "no") || *temp_cne_or_name == 'n') ? NULL : temp_cne_or_name);
}

/**
 * list_student - this function takes a string as CNE or (name in the future) and lists the whole details of the
 * wanted student ,  or output an error if no student was found, if NULL exists, the function returns
 * @str: the string as CNE to look for, if its NULL in the args the function will call list_students all
 * @s: the students struct
*/
void list_student(char *str, student *s)
{
	student *current;

	if (!str)
		str = list_all_students(s);
	if (!str)
	{
		print_sleep_clear("OUT ..", 1);
		return;
	}
	if (!s)
	{
		perror("error: list_student: the list is null or empty");
		exit(NULL_ERROR);
	}
	cne:
	if (!strcmp(str, "no") || *str == 'n')
	{
		print_sleep_clear("OUT ..", 1);
		return;
	}
	current = s;
	while (current)
	{
		if (!strcmp(current->CNE, str))
		{
			printf("\n---------------------------------\nNAME: %s\nLAST NAME: %s\nBIRTHDAY: %s\n", current->name, current->last_name, current->birthdate);
			printf("NOTES : %0.1f\t%0.1f\t%0.1f\t%0.1f\n", current->notes[0], current->notes[1], current->notes[2], current->notes[3]);
			pause_clear();
			return;
		}
		current = current->next;
	}
	print_sleep_clear("CNE DOESNT EXIST", 1);
	str = list_all_students(s);
	goto cne;
}