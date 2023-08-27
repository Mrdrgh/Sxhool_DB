#ifndef SCHOOL_H
#define SCHOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FETCH_FOR_STRING_ERROR -10
#define MALLOC_ERROR_FOR_STRUCT_STUDENT -11
#define ASK_STUDENT_INFO_ERROR -12
#define INIT_STRUCT_STUDENT {NULL, NULL, 0, NULL, NULL, false, NULL, 0, NULL, NULL}
typedef struct student
{
	char *name;
	char *last_name;
	char CNE[11];
	char password[9];
	char birthdate[11];
	bool haspaid;
	float notes[4];
	float balance;
	char **inbox;
	struct student *next;
} student;

typedef struct teacher
{
	char *name;
	char *last_name;
	char birthdate[11];
	char *CNI;
	char password[9];
	char **inbox;
	struct teacher *next;
} teacher;

typedef union student_teacher
{
	student *s;
	teacher *t;
} student_teacher;

void sleep_clear(int sleep_duration);
void print_sleep_clear(const char *prompt, int sleep_duration);
void pause_clear();
void pause();
bool login(student *, teacher *, student_teacher *);
student *login_student(student *, student_teacher *);
teacher *login_teacher(teacher *, student_teacher *);
student *fetch_for_string_student(char *str, student *s);





#endif