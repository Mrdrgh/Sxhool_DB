#include "school.h"

/**
 * login - the login main function
 * 
 * Return: true or false
*/

bool login(student *s, teacher *t, student_teacher *s_t)
{
	int i = 0;
	printf("1- student\n2- teacher\n--->");
	scanf("%d", &i);
	while (i != 1 || i != 2)
	{
		print_sleep_clear("not a type !", 1);
	}
	if (i == 1)
	{
		s_t->s = login_student(s, s_t);
		if (!s_t->s)
			return (false);
	}
	else
	{
		s_t->t = login_teacher(t, s_t);
		if (!s_t->t)
			return (false);
	}
	return (true);
}

/**
 * login_student - the main login function for students
 * 
 * Return: true or false
*/

student *login_student(student *s, student_teacher *s_t)
{
	char temp_cne[11];
	char *pass_wd[9];
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
	while (strcmp(pass_wd, login_struct) && i < 3)
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