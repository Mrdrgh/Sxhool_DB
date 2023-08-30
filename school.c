#include "school.h"

/**
 * main - the main entry to our school database program
 * @ac: the nbr of args
 * @av: the args
 * Return: on success 0, everyelse problem will have his own id
*/
int main(int ac, char **av)
{
	(void) ac, (void) av;
	student *s;
	login_return *s_t = init_union(s_t); // by default in ISNONE//
	teacher *t = init_struct_teachers(t);

	s = load_struct_student();
	while ((s_t = login(s, t, s_t))->student_or_teacher)
	{
		if (s_t->student_or_teacher == 1)
			student_cli(s_t->s);
		else if (s_t->student_or_teacher == 2)
		{
			if (s_t->t->is_the_manager)
				principal_cli(&(s_t)->t, &t, &(s_t)->s, &s);
			else
				teacher_cli(&(s_t)->t, &t, &(s_t)->s, &s);
		}
		else
		{
			perror("error: main loop");
			exit(MAIN_ERROR);
		}
	}
	printf("out");
	return (0);
}
