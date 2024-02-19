#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct subject
{
  int subjectId;
  char name[20];
  int totalStudents;
  int grade;
} Subject;

typedef struct arrayList
{
  int count;           // current length of the current_subject_list
  int allocated_count; // max length of the current_subject_list
  Subject *current_subject_list;
} ArrayList;

// Checking if subject id is unique
bool is_subject_id_unique(ArrayList *subjects, int subject_id);

// Creating a subject
Subject *create_subject(ArrayList *subjects);

// Printing subject
void print_subject(Subject *subject);

// Printing subject
void print_subjects(ArrayList *subjects);

// Adding subject to array list with adding extra memory if needed
void add_subject(ArrayList *array_list, Subject *subject);

Subject *get_subject_by_id(ArrayList *subjects, int subject_id);

// User inputs
void user_subjects_inputs(ArrayList *subjects);

#endif
