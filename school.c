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

	s = add_stuct_student(s);
	if (login(s, NULL, s_t))
	{
		printf("success");
	}
	else
		printf("n success");
	return (0);
}