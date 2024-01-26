#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max_number_of_subjects 10

typedef struct teacher 
{
  char name[20];
  int id;
  int subjectId;
} Teacher;


// Creating teacher
Teacher* createTeacher() 
{
  Teacher* newTeacher = (Teacher*)malloc(sizeof(Teacher));
  printf("Enter Teacher's name: ");
  scanf("%s", newTeacher->name);
  getchar();
  printf("Enter subject ID: ");
  scanf("%d", &(newTeacher->subjectId));
  getchar();
  printf("Enter Teacher's ID: ");
  scanf("%d", &(newTeacher->id));
  getchar();
  return newTeacher;
}

// Printing teacher
void print_teacher(Teacher *teacher) {
  printf("\t%d\t\%s\t\t%d\n", teacher->id, teacher->name, teacher->subjectId);
  printf("\n");
}

#endif