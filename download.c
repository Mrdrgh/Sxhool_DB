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

/**
 * download_student_inbox - a function to save the student inbox, the inbox's file name is the cne of the student
 * @str: the string to save in the inbox of the student
 * @dest_cne: the desination cne, required for naming the file
 * @time: if 0 we skip the timed promped msg, useful for when using this funct in loops
*/

void download_student_inbox(char *str, char *dest_cne, int time)
{
	FILE *fp;
	char file_name[20], filename[1024];

	if (!dest_cne)
	{
		perror("error: download_student_struct: dest_cne is null");
		exit(NULL_ERROR);
	}
	sprintf(file_name, "./students_inbox/%s", dest_cne);
	fp = fopen(file_name, "a+");
	if (!fp)
	{
		perror("error: download_student_inbox: path not existing");
		exit(FILE_IO_ERROR);
	}
	str[strcspn(str, "\n")] = '\0';
	if (fprintf(fp, "%s\n", str) == -1)
	{
		perror("error: download_student_inbox: write");
		exit(FILE_IO_ERROR);
	}
	if (time)
	{
		print_sleep_clear("DATA SAVED", time);
	}

}

/**
 * download_struct_teacher - downloads the structs of teacher when adding a teacher or
 * modifying a teacher's struct
 * @teacher_list: the teachers list
*/

void download_struct_teacher(teacher **teacher_list)
{
	FILE *fp = fopen("./users_data/teachers.dat", "wb");
	student *current;

	if (!*teacher_list)
	{
		perror("error: download_struct_student: struct may be empty");
		exit(NULL_ERROR);
	}
	if (!fp)
	{
		perror("error: download_struct_student: path not existing");
		exit(FILE_IO_ERROR);
	}
	current = *teacher_list;
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

/**
 * download_teacher_inbox - a function to save the teacher inbox, the teacher's file name is the cni of the teacher
 * @str: the string to save in the inbox of the teacher
 * @t: the struct of the teacher , we will need it for naming the inbox file
*/

void download_teacher_inbox(char *str, char *dest_cni, int time)
{
	FILE *fp;
	char *full_msg = NULL, filename[1024];

	if (!dest_cni)
	{
		perror("error: download_teacher_inbox: dest cne is null");
		exit(NULL_ERROR);
	}
	sprintf(filename, "./teachers_inbox/%s", dest_cni);
	fp = fopen(filename, "a+");
	if (!fp)
	{
		perror("error: download_student_inbox: path not existing");
		exit(FILE_IO_ERROR);
	}
	str[strcspn(str, "\n")] = '\0';

	if (fprintf(fp, "%s\n", str) == -1)
	{
		perror("error: download_student_inbox: write");
		exit(FILE_IO_ERROR);
	}
	if (time)
	{
		print_sleep_clear("DATA SAVED", time);
	}

}