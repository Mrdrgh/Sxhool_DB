#include "school.h"

/**
 * main - the main entry to our school database program
 * @ac: the nbr of args
 * @av: the args
 * Return: on success 0, everyelse problem will have his own id
*/
int main(int ac, char **av)
{
	student *s = init_struct_students(s);
	student_teacher *s_t = init_union(s_t); // by default in ISNONE//
	teacher *t = init_struct_teachers(t);
	int i = 0;

	while (i = login(s, t, s_t))
	{
		if (i == 1)
			student_cli(s);
		else if (i == 2)
			teacher_cli(&t, &s);
		else
		{
			perror("error: main loop");
			exit(MAIN_ERROR);
		}
	}
	printf("out");
	return (0);
}
