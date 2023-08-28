#include "school.h"

/**
 * init_union - initializes the union
 * @u: the union
*/
login_return *init_union(login_return *s_t)
{
	s_t = malloc(sizeof(login_return));
	if (!s_t)
	{
		perror("error: init_union");
		exit(MALLOC_ERROR);
	}
	s_t->s = NULL;
	s_t->t = NULL;
	s_t->student_or_teacher = IS_NONE;
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
	teacher *new_teacher = malloc(sizeof(teacher));

	if (!new_teacher)
	{
		perror("error: init_struct_teachers");
		exit(MALLOC_ERROR);
	}
	strcpy(new_teacher->birthdate, "24/7/2003");
	strcpy(new_teacher->CNI, "FC65138");
	strcpy(new_teacher->password, "password");
	strcpy(new_teacher->name, "Darghal");
	strcpy(new_teacher->last_name, "Mohammed");
	new_teacher->is_the_manager = true;
	new_teacher->next = NULL;
	return (new_teacher);
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
	fflush(stdin);
	printf("\nBIRTH DATE (dd/mm/yyyy) : ");scanf("%s", s->birthdate);
	printf("\nCNE: ");scanf("%s", s->CNE);
	printf("\nPASSWORD : ");scanf("%s", s->password);
	while (i < 4)
	{
		printf("\nNOTE %d: ", i);scanf("%f", &s->notes[i]);
		i++;
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

	if (!new_student || !new_student->birthdate)
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
while (str)
{
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
			printf("CNE : %s\nPASSWORD : %s\n", current->CNE, current->password);
			printf("NOTES : %0.1f\t%0.1f\t%0.1f\t%0.1f\n", current->notes[0], current->notes[1], current->notes[2], current->notes[3]);
			modify_struct_student(current);
			system("clear");
			return;
		}
		current = current->next;
	}
	print_sleep_clear("CNE DOESNT EXIST", 1);
	str = list_all_students(s);
}
}

/**
 * modify_struct_student - modifies a student struct , usually to modify its notes
 * @s: the struct to modify
*/
void modify_struct_student(student *s)
{
	int i = 0, j = 0;
	if (!s)
	{
		perror("error: modify_struct_student");
		exit(NULL_ERROR);
	}
	printf("\n--> press 1 to modify the infos or 0 to skip : ");scanf("%d", &i);
	while (i != 1 && i != 0)
	{
		printf("NOT A COMMAND");
		printf("\n--> press 1 to modify the infos or 0 to skip : ");scanf("%d", &i);
	}
	if (i)
	{
		system("clear");
again:
		printf("1- modify all infos\n2- modify notes\n3- modify name and last name\n3-modify CNE\n--->");scanf("%d", &j);
		switch (j)
		{
			case 1:
				ask_student_info(s);
				break;
			case 2:
				printf("note 1 : ");scanf("%f", &s->notes[0]);
				printf("note 2 : ");scanf("%f", &s->notes[1]);
				printf("note 3 : ");scanf("%f", &s->notes[2]);
				printf("note 4 : ");scanf("%f", &s->notes[3]);
				break;
			case 3:
				printf("name : ");scanf("%s", s->name);
				printf("last name : ");scanf("%s", s->last_name);
				break;
			case 4:
				printf("CNE : ");scanf("%s", s->CNE);
				break;
			default:
				print_sleep_clear("NOT A COMMAND", 1);
				goto again;
		}
		print_sleep_clear("ALL DONE ..", 1);
	}
	return;
}

/**
 * list_all_teachers - lists all the teachers by name and CNE
 * @t: the teachers struct
 * Return: waits for the user to type a CNI or a name to list the full details for this
 * student with the convenable cne , if its not found , output that the student doesn't exist
 * if the user doesn't want to out_put anything the function returns NULL
 * !! REQUIRES MANAGER PREVILIGE !!
*/
char *list_all_teachers(teacher *t)
{
	teacher *current;
	char temp_cni_or_name[11];

	if (!t)
	{
		perror("error: list_all_teachers: struct may be empty");
		exit(NULL_ERROR);
	}
	current = t;
	while (current)
	{
		printf("_______________________________________\n");
		if (current->is_the_manager)
			printf("(PRINCIPAL)\n");
		printf("NAME : %s\nLAST NAME : %s\nCNI : %s\n", current->name, current->last_name, current->CNI);
		current = current->next;
	}
	printf("_______________________________________\n");
	printf("type the CNE of the teacher to show more details of, or type \"no\" or 'n' : ");
	scanf("%s", temp_cni_or_name);
	return ((!strcmp(temp_cni_or_name, "no") || *temp_cni_or_name == 'n') ? NULL : temp_cni_or_name);
}

/**
 * list_teacher - this function takes a string as CNE or (name in the future) and lists the whole details of the
 * wanted teacher ,  or output an error if no teacher was found, if NULL exists, the function returns
 * @str: the string as CNE to look for, if its NULL in the args the function will call list_teachers all
 * @t: the teachers struct
*/
void list_teacher(char *str, teacher *t)
{
	teacher *current;

	if (!str)
		str = list_all_teachers(t);
	if (!str)
	{
		print_sleep_clear("OUT ..", 1);
		return;
	}
	if (!t)
	{
		perror("error: list_teacher: the list is null or empty");
		exit(NULL_ERROR);
	}
cni:
	if (!strcmp(str, "no") || *str == 'n')
	{
		print_sleep_clear("OUT ..", 1);
		return;
	}
	current = t;
	while (current)
	{
		if (!strcmp(current->CNI, str))
		{
			printf("\n---------------------------------\nNAME: %s\nLAST NAME: %s\nBIRTHDAY: %s\n", current->name, current->last_name, current->birthdate);
			printf("CNI : %s\nPASSWORD : %s", current->CNI, current->password);
			modify_struct_teacher(current);
			system("clear");
			return;
		}
		current = current->next;
	}
	print_sleep_clear("CNE DOESNT EXIST", 1);
	str = list_all_teachers(t);
	goto cni;
}

/**
 * modify_struct_student - modifies a student struct , usually to modify its notes
 * @t: the struct to modify
*/
void modify_struct_teacher(teacher *t)
{
	int i = 0, j = 0;

	if (!t)
	{
		perror("error: modify_struct_student");
		exit(NULL_ERROR);
	}
	printf("\n--> press 1 to modify the infos or 0 to skip : ");scanf("%d", &i);
	while (i != 1 && i != 0)
	{
		printf("NOT A COMMAND");
		printf("\n--> press 1 to modify the infos or 0 to skip : ");scanf("%d", &i);
	}
	if (i)
	{
		system("clear");
againn:
		printf("1- modify all infos\n2- modify name and last name\n3-modify CNI\n--->");scanf("%d", &j);
		switch (j)
		{
			case 1:
				ask_teacher_info(t);
				break;
			case 2:
				printf("name : ");scanf("%s", t->name);
				printf("last name : ");scanf("%s", t->last_name);
				break;
			case 3:
				printf("CNI : ");scanf("%s", t->CNI);
				break;
			default:
				print_sleep_clear("NOT A COMMAND", 1);
				goto againn;
		}
		print_sleep_clear("ALL DONE ..", 1);
	}
	return;
}


/**
 * delete_student_struct - deletes a student struct
 * @s: the student struct
*/

void delete_student_struct(student **s)
{
    char temp_cne[11];
    student *current, *prev;

    if (!s)
    {
        perror("error: delete_student_struct: struct may be empty");
        exit(NULL_ERROR);
    }
againnn:
    printf("input the student CNE to delete from the platform, or type \"no\" or 'n' to return : ");
    scanf("%s", temp_cne);
    if (!strcmp(temp_cne, "no") || *temp_cne == 'n')
        return;

    // If head node itself holds the key to be deleted
    if (*s != NULL && strcmp((*s)->CNE, temp_cne) == 0)
    {
        printf("found, are you sure to delete this student from the platform ? [Y, n] : ");
        scanf("%s", temp_cne);
        if (!strcmp(temp_cne, "no") || *temp_cne == 'n')
        {
            print_sleep_clear("CANCELLED ..", 1);
            return;
        }
        current = *s; // Changed head
        *s = (*s)->next; // Changed head
        free(current); // free old head
        print_sleep_clear("DELETED ! ", 1);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    prev = NULL;
    current = *s;
    while (current != NULL && strcmp(current->CNE, temp_cne) != 0)
    {
        prev = current;
        current = current->next;
    }

    // If key was not present in linked list
    if (current == NULL) goto againnn;

    printf("found, are you sure to delete this student from the platform ? [Y, n] : ");
    scanf("%s", temp_cne);
    if (!strcmp(temp_cne, "no") || *temp_cne == 'n')
    {
        print_sleep_clear("CANCELLED ..", 1);
        return;
    }

    // Unlink the node from linked list
    prev->next = current->next;

    free(current); // Free memory
    print_sleep_clear("DELETED ! ", 1);
}
