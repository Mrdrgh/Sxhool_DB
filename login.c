#include "school.h"

/**
 * login - the login main function
 * 
 * Return: true or false
*/

login_return *login(student *s, teacher *t, login_return *s_t)
{
	int i = 0;
	student *place_h_s;
	teacher *place_h_t;
	printf("1- student\n2- teacher\n3- exit the program\n---> ");
	scanf("%d", &i);
	while (i != 1 && i != 2 && i != 3)
	{
		print_sleep_clear("not a type !", 1);
		scanf("%d", &i);
	}
	if (i == 3)
	{
		s_t->student_or_teacher = IS_NONE;
		return (s_t);
	}
	if (i == 1)
	{
		place_h_s = login_student(s);
		if (place_h_s)
		{
			s_t->s = place_h_s;
			s_t->t = NULL;
			s_t->student_or_teacher = IS_STUDENT;
		}
		else
		{
			s_t->s = NULL;
			s_t->t = NULL;
			s_t->student_or_teacher = IS_NONE;
		}
		return (s_t);
	}
	else
	{
		place_h_t = login_teacher(t);
		if (place_h_t)
		{
			s_t->t = place_h_t;
			s_t->s = NULL;
			s_t->student_or_teacher = IS_TEACHER;
		}
		else
		{
			s_t->s = NULL;
			s_t->t = NULL;
			s_t->student_or_teacher = IS_NONE;
		}
		return (s_t);
	}
}

/**
 * login_student - the main login function for students
 * 
 * Return: true or false
*/

student *login_student(student *s)
{
	char temp_cne[11];
	char pass_wd[9];
	int i = 0;
	student *login_struct;

	system("clear");
	printf("CNE : ");
	scanf("%s", temp_cne);
	login_struct = fetch_for_string_student(temp_cne, s);
	while (!login_struct && i < 3)
	{
		i++;
		if (i == 3)
			return (NULL);
		print_sleep_clear("NO MATCH FOUND !, reENTER CNE", 2);
		printf("%d trials left\nCNE : ", 3 - i);scanf("%s", temp_cne);
		login_struct = fetch_for_string_student(temp_cne, s);
	}
	i = 0;
	printf("password : ");
	scanf("%s", pass_wd);
	while (strcmp(pass_wd, login_struct->password) && i < 3)
	{
		i++;
		if (i == 3)
			return (NULL);
		print_sleep_clear("WRONG PASSWORD..", 1);
		printf("%d trials left\npassword : ", 3 - i);
		scanf("%s", pass_wd);
	}
	print_sleep_clear("            CONNECTED          ", 1);
	return (login_struct);
}

/**
 * login_teacher - login for the teachers
 * @t: the teacher struct
 * @s_t: the union of student or teacher
 * Return: the found teacher struct , or null if none was found and the user had too many trials
*/

teacher *login_teacher(teacher *t)
{
	char temp_cne[11];
	char pass_wd[9];
	int i = 0;
	teacher *login_struct;

	system("clear");
	printf("CNE : ");
	scanf("%s", temp_cne);
	login_struct = fetch_for_string_teacher(temp_cne, t);
	while (!login_struct && i < 3)
	{
		i++;
		if (i == 3)
			return (NULL);
		print_sleep_clear("NO MATCH FOUND !, REENTER CNE", 2);
		printf("%d trials left\nCNE : ", 3 - i);scanf("%s", temp_cne);
		login_struct = fetch_for_string_teacher(temp_cne, t);
	}
	i = 0;
	printf("password : ");
	scanf("%s", pass_wd);
	while (strcmp(pass_wd, login_struct->password) && i < 3)
	{
		i++;
		if (i == 3)
			return (NULL);
		print_sleep_clear("WRONG PASSWORD..", 1);
		printf("%d trials left\npassword : ", 3 - i);
		scanf("%s", pass_wd);
	}

	if (login_struct->is_the_manager)
		print_sleep_clear("CONNECTED , WELCOME BOSS", 1);
	else
		print_sleep_clear("            CONNECTED          ", 1);
	return (login_struct);
}