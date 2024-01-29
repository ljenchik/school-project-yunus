#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "subject.h"

typedef struct teacher
{
  char name[20];
  int id;
  int subjectId;
} Teacher;

typedef struct teacher_list
{
  Teacher teacher;
  struct teacher_list *next;
} TeacherList;

// Creating teacher
TeacherList *createTeacher()
{
  TeacherList *newTeacher = (TeacherList *)malloc(sizeof(TeacherList));
  printf("Enter Teacher's name: ");
  scanf("%s", newTeacher->teacher.name);
  printf("Enter subject ID: ");

  scanf("%d", &(newTeacher->teacher.subjectId));
  printf("Enter Teacher's ID: ");

    scanf("%d", &(newTeacher->teacher.id));
  newTeacher->next = NULL;
  return newTeacher;
}

void add_teacher(TeacherList *head, TeacherList *new_teacher)
{
  if (new_teacher == NULL)
  {
    printf("Error: invalid pointer, no teacher to add \n");
  }
  if (head == NULL)
  {
    head = new_teacher;
  }
  else
  {
    TeacherList *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_teacher;
    new_teacher->next = NULL;
  }
}

// Printing a teacher
void print_teacher(TeacherList *teacher)
{
  printf("\t%d\t%s\t\t%d\n", teacher->teacher.id, teacher->teacher.name, teacher->teacher.subjectId);
  printf("\n");
}

// Printing all teachers
void print_teachers(TeacherList *head)
{
  if (head == NULL)
  {
    printf("Error: invalid pointer \n");
  }
  else
  {
    TeacherList *current = head;
    printf("Teacher id\tName\t\tSubject id\n");
    printf("\n");
    while (current != NULL)
    {
      print_teacher(current);
      current = current->next;
    }
    printf("\n");
  }
}

// Finding a teacher by a given subject
void findTeacherForSubject(TeacherList *head, ArrayList *subjects, int subject_id)
{
  Subject *found_subject = get_subject_by_id(subjects, subject_id);
  if (found_subject == NULL)
  {
    printf("There is no subject with id %d \n", subject_id);
    return;
  }
  else
  {
    TeacherList *current = head;
    while (current != NULL)
    {
      if (current->teacher.subjectId == subject_id)
      {
        print_teacher(current);
        return;
      }
      current = current->next;
    }
  }
}

#endif