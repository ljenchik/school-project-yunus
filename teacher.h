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

// Creating teacher head
TeacherList *createTeacherHead(ArrayList *subjects)
{
  int sub_id;
  TeacherList *newTeacher = (TeacherList *)malloc(sizeof(TeacherList));
  printf("Enter teacher id: ");
  scanf("%d", &(newTeacher->teacher.id));

  printf("Enter teacher name: ");
  scanf("%s", newTeacher->teacher.name);

  printf("Enter subject id: ");
  scanf("%d", &sub_id);
  Subject *found_subject = get_subject_by_id(subjects, sub_id);
  if (found_subject == NULL)
  {
    printf("Subject with id %d does not exist \n", sub_id);
  }
  else
  {
    newTeacher->teacher.subjectId = sub_id;
  }

  newTeacher->next = NULL;
  return newTeacher;
}

// Checking if teacher id is unique
bool is_teacher_id_unique(TeacherList *head, int teacher_id)
{
  TeacherList *current = head;
  while (current != NULL)
  {
    if (current->teacher.id == teacher_id)
    {
      return false;
    }
    current = current->next;
  }
  return true;
}

// Checking if teacher teaches only one subjects
bool is_teacher_subject_unique(TeacherList *head, int subject_id)
{
  TeacherList *current = head;
  while (current != NULL)
  {
    if (current->teacher.subjectId == subject_id)
    {
      return false;
    }
    current = current->next;
  }
  return true;
}

// Creating teacher
TeacherList *createTeacher(TeacherList *head, ArrayList *subjects)
{
  int te_id;
  int sub_id;
  bool te_id_unique = false;

  TeacherList *newTeacher = (TeacherList *)malloc(sizeof(TeacherList));

  while (te_id_unique != true)
  {
    printf("Enter teacher id: ");
    scanf("%d", &te_id);
    if (is_teacher_id_unique(head, te_id) == true)
    {
      newTeacher->teacher.id = te_id;
      break;
    }
    printf("Teacher with id %d already exists. Enter a different teacher id \n", te_id);
  }

  printf("Enter teacher name: ");
  scanf("%s", newTeacher->teacher.name);

  printf("Enter subject id: ");
  scanf("%d", &sub_id);
  Subject *found_subject = get_subject_by_id(subjects, sub_id);
  if (found_subject == NULL)
  {
    printf("Subject with id %d does not exist \n", sub_id);
  }
  else if (is_teacher_subject_unique(head, sub_id) == false)
  {
    printf("Subject with id %d is assigned to another teacher \n", sub_id);
  }
  else
  {
    newTeacher->teacher.subjectId = sub_id;
  }
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

// Printing a teacher, printing only unique pairs teacher-subject
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
      if (current->teacher.subjectId != 0)
      {
        print_teacher(current);
      }
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

// User inputs
void user_teachers_inputs(TeacherList *head, ArrayList *subjects)
{
  bool add_more_teachers = true;
  char user_response = 'y';
  while (add_more_teachers == true)
  {
    printf("Do you want to add another teacher? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      TeacherList *new_teacher = createTeacher(head, subjects);
      add_teacher(head, new_teacher);
    }
  }
}

// User inputs to get teacher by subject
void user_find_teacher_by_subject(TeacherList *head, ArrayList *subjects)
{
  bool add_more = true;
  int sub_id;
  char user_response = 'y';
  while (add_more == true)
  {
    printf("Do you want to print a teacher by subject? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      printf("Enter a subject id \n");
      scanf("%d", &sub_id);
      findTeacherForSubject(head, subjects, sub_id);
    }
  }
}

#endif