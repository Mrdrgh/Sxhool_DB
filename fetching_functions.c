#include "school.h"

/**
 * fetch_for_string - the main fetching function for string
 * @str: the str to fetch for
 * @s: the students struct , if NULL we look into other types of structs
 * @t: the teachers struct  , same for it
*/
teacher *fetch_for_string_teacher(char *str, teacher *t)
{
	size_t i = 0;
	teacher *current;

	if (!t)
	{
		perror("error: fetch_for_string_teacher");
		exit(NULL_ERROR);
	}
	current = t;
	while (current)
	{
		if (strcmp(current->CNI, str) == 0)	
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

/**
 * fetch_for_string_student - fetches for string in student struct
 * @str: the str to look for
 * @s: the struct
*/
student *fetch_for_string_student(char *str, student *s)
{
	size_t i = 0;
	student *current;

	if (!s)
	{
		perror("error: fetch_for_string_student");
		exit(NULL_ERROR);
	}
	current = s;
	while (current)
	{
		if (strcmp(current->CNE, str) == 0)	
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}