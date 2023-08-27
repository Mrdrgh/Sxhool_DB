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
	student_teacher *s_t = init_union(s_t);
	teacher manager = {"darghal", "mohammed",
	"24/7/2003", "FC65138", "password", true, NULL, NULL};

	if (login(s, &manager, s_t))
	{
		if (s_t->s)
			student_cli(s_t->s);
		if (s_t->t)
			teacher_cli(s_t->t);
		printf("success");
	}
	else
		printf("n success");
	return (0);
}