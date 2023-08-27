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
		printf("1-output my informations\n2-out\n---> ");scanf("%d", &out);
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