#include "school.h"

/**
 * load_struct_students - load the struct of the students, this function will be called once and for all
 * in the beginning of the program
 * 
 * Return: the newly created linked list
*/

student *load_struct_student()
{
    FILE *fp = NULL;
    student *new_list = NULL;
    student *current = NULL;
    student *temp = NULL;

    new_list = init_struct_students(new_list);
    fp = fopen("./users_data/students.dat", "rb");
    if (fp == NULL) {
        perror("error: load_struct_student: could not open file");
        exit(2);
    }
    while ((temp = malloc(sizeof(student))) && fread(temp, sizeof(student), 1, fp) > 0)
    {
        if (new_list == NULL) {
            new_list = temp;
            current = new_list;
        } else {
            current->next = temp;
            current = current->next;
        }
        temp = NULL;
    }
    fclose(fp);
    return (new_list);
}

/**
 * load_struct_teacher - load the struct of the teachers, this function will be called once and for all
 * in the beginning of the program
 * 
 * Return: the newly created linked list
*/

teacher *load_struct_teacher()
{
    FILE *fp = NULL;
    teacher *new_list = NULL;
    teacher *current = NULL;
    teacher *temp = NULL;

    new_list = init_struct_teachers(new_list);
    fp = fopen("./users_data/teachers.dat", "rb");
    if (fp == NULL) {
        perror("error: load_struct_teacher: could not open file");
        exit(2);
    }
    while ((temp = malloc(sizeof(teacher))) && fread(temp, sizeof(teacher), 1, fp) > 0)
    {
        if (new_list == NULL) {
            new_list = temp;
            current = new_list;
        } else {
            current->next = temp;
            current = current->next;
        }
        temp = NULL;
    }
    fclose(fp);
    return (new_list);
}