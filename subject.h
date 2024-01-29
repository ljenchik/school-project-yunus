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

// Creating a subject
Subject *createSubject()
{
  Subject *newSubject = (Subject *)malloc(sizeof(Subject));
  printf("Enter Subject id: ");
  scanf("%d", &newSubject->subjectId);
  printf("Enter Subject name: ");
  scanf("%s", newSubject->name);
  return newSubject;
}

// Printing subject
void print_subject(Subject *subject)
{
  printf("Subject id\tSubject name\n");
  printf("\t%d\t\%s\t\t\n", subject->subjectId, subject->name);
  printf("\n");
}

// Printing subject
void print_subjects(ArrayList *subjects)
{
  printf("Subject id\tSubject name\n");
  for (int i = 0; i < subjects->count; i++)
  {
    printf("\t%d\t\%s\t\t\n", subjects->current_subject_list[i].subjectId, subjects->current_subject_list[i].name);
  }
  printf("\n");
}

// Adding subject to array list with adding extra memory if needed
void add_subject(ArrayList *array_list, Subject *subject)
{
  int new_count = array_list->count + 1;
  if (new_count > array_list->allocated_count)
  {
    // allocates and copies, doubles the memory
    int new_allocated_count = array_list->allocated_count * 2;
    if (new_allocated_count == 0)
    {
      new_allocated_count = 1;
    }
    // ptr = (cast-type*) malloc(byte-size)
    Subject *new_array_list = malloc(new_allocated_count * sizeof(Subject));
    if (array_list->current_subject_list != NULL)
    {
      // void *memcpy(void *dest, const void * src, size_t n)
      // n is the nimber of bytes to be copied
      memcpy(new_array_list, array_list->current_subject_list, array_list->count * sizeof(Subject));
      free(array_list->current_subject_list);
    }
    array_list->current_subject_list = new_array_list;
    array_list->allocated_count = new_allocated_count;
  }
  array_list->current_subject_list[array_list->count] = *subject;
  array_list->count = new_count;
}

Subject *get_subject_by_id(ArrayList *subjects, int subject_id)
{
  for (int i = 0; i < subjects->count; i++)
  {
    if (subjects->current_subject_list[i].subjectId == subject_id)
    {
      return &subjects->current_subject_list[i];
    }
  }
  return NULL;
}

#endif