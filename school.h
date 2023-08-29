#ifndef SCHOOL_H
#define SCHOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define FETCH_FOR_STRING_ERROR 10
#define MALLOC_ERROR 11
#define ASK_STUDENT_INFO_ERROR 12
#define ASK_TEACHER_INFO_ERROR 13
#define NULL_ERROR 14
#define MAIN_ERROR 15
#define INIT_STRUCT_STUDENT {NULL, NULL, 0, NULL, NULL, false, NULL, 0, NULL, NULL}
typedef struct student
{
	char name[10];
	char last_name[10];
	char CNE[11];
	char password[9];
	char birthdate[15];
	bool haspaid;
	float notes[4];
	float balance;
	char **inbox;
	int inbox_sz;
	struct student *next;
} student;

typedef struct teacher
{
	char name[10];
	char last_name[10];
	char birthdate[15];
	char CNI[8];
	char password[9];
	bool is_the_manager;
	char **inbox;
	int inbox_sz;
	struct teacher *next;
} teacher;

typedef enum student_teacher
{
IS_NONE,
IS_STUDENT,
IS_TEACHER
} student_teacher;

typedef struct login_return
{
	student_teacher student_or_teacher;
	student *s;
	teacher *t;
} login_return;

void sleep_clear(int sleep_duration);
void print_sleep_clear(const char *prompt, int sleep_duration);
void pause_clear();
void _pause();
login_return *login(student *, teacher *, login_return *);
student *login_student(student *);
teacher *login_teacher(teacher *);
student *fetch_for_string_student(char *str, student *s);
teacher *fetch_for_string_teacher(char *str, teacher *t);
login_return *init_union(login_return *);
student *init_struct_students(student *);
teacher *init_struct_teachers(teacher *);
void ask_student_info(student *);
void ask_teacher_info(teacher *);
student *add_struct_student(student **);
teacher *add_struct_teacher(teacher **);
void student_cli(student *);
void teacher_cli(teacher **, student **, student **);
void principal_cli(teacher **, teacher **, student **, student **);
char *list_all_students(student *);
char *list_all_teachers(teacher *);
void list_student(char *, student *);
void list_teacher(char *, teacher *);
void modify_struct_student(student *);
void modify_struct_teacher(teacher *);
void delete_student_struct(student **);
void scream_to_school(teacher **, student **);
void principal_messaging_cli(teacher **, teacher **, student **);
void students_inbox(student *);




#endif