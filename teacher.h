#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "subject.h"

typedef struct teacher
{
  char *name;
  int id;
  int subjectId;
} Teacher;

typedef struct teacher_list
{
  Teacher teacher;
  struct teacher_list *next;
} TeacherList;

// Creating teacher head
TeacherList *create_teacher_head(ArrayList *subjects);

// Checking if teacher id is unique
bool is_teacher_id_unique(TeacherList *head, int teacher_id);

// Checking if teacher teaches only one subjects
bool is_teacher_subject_unique(TeacherList *head, int subject_id);

// Creating teacher
TeacherList *createTeacher(TeacherList *head, ArrayList *subjects);

void add_teacher(TeacherList *head, TeacherList *new_teacher);

// Printing a teacher, printing only unique pairs teacher-subject
void print_teacher(TeacherList *teacher);

void print_teachers(TeacherList *head);

// Finding a teacher by a given subject
void find_teacher_by_subject(TeacherList *head, ArrayList *subjects, int subject_id);

// User inputs
void user_teachers_inputs(TeacherList *head, ArrayList *subjects);

// User inputs to get teacher by subject
void user_find_teacher_by_subject(TeacherList *head, ArrayList *subjects);

#endif
