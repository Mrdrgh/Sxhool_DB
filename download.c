#include "school.h"

/**
 * download_struct_student - downloads the structs of students when adding a student or
 * modifying a student's struct
 * @student_list: the stedents list
*/

void download_struct_student(student **student_list)
{
	FILE *fp = fopen("./users_data/students.dat", "wb");
	student *current;

	if (!*student_list)
	{
		perror("error: download_struct_student: struct may be empty");
		exit(NULL_ERROR);
	}
	if (!fp)
	{
		perror("error: download_struct_student: path not existing");
		exit(FILE_IO_ERROR);
	}
	current = *student_list;
	while (current)
	{
		if (fwrite(current, 1, sizeof(student), fp) <= 0)
		{
			perror("error: download_struct_student: fwrite:");
			exit(FILE_IO_ERROR);
		}
		current = current->next;
	}
	fclose(fp);
	print_sleep_clear("DATA SAVED", 1);
}