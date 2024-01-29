#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_number_of_subjects 10

#include "subject.h"

typedef struct student
{
  int id;
  char name[20];
  ArrayList *subjects;
} Student;

typedef struct student_list
{
  Student student;
  struct student_list *next;
} StudentList;

// Creating students using a user's input
StudentList *create_student()
{
  StudentList *new_student = (StudentList *)malloc(sizeof(StudentList));
  new_student->student.subjects = (ArrayList *)malloc(sizeof(ArrayList));
  memset(new_student->student.subjects, 0, sizeof(ArrayList));
  printf("Enter student id: ");
  scanf("%d", &new_student->student.id);
  printf("Enter student name: ");
  scanf("%s", new_student->student.name);
  new_student->next = NULL;
  return new_student;
}

// Printing a given student with all info
void print_student(StudentList *student)
{
  printf("\t%d\t%s\t\t", student->student.id, student->student.name);
  for (int i = 0; i < student->student.subjects->count; i++)
  {
    printf("%s ", student->student.subjects->current_subject_list[i].name);
  }
  printf("\n");
}

// Adding a new student
void add_student(StudentList *head, StudentList *new_student)
{
  if (new_student == NULL)
  {
    printf("Error: invalid pointer, no student to add \n");
  }
  if (head == NULL)
  {
    head = new_student;
  }
  else
  {
    StudentList *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_student;
    new_student->next = NULL;
  }
}

// Printing all students
void print_students(StudentList *head)
{
  if (head == NULL)
  {
    printf("Error: invalid pointer \n");
  }
  else
  {
    StudentList *current = head;
    printf("Student id\tName\t\tSubjects\n");
    printf("\n");
    while (current != NULL)
    {
      print_student(current);
      current = current->next;
    }
    printf("\n");
  }
}

void add_subject_to_student(Student *student, Subject *new_subject)
{
  add_subject(student->subjects, new_subject);
}

// Getting a student by id
StudentList *get_student_by_id(StudentList *head, int student_id)
{
  StudentList *current = head;
  while (current != NULL)
  {
    if (current->student.id == student_id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Add a grade to a given student to a given subject
void add_grade(StudentList *head, int student_id, int subject_id, int grade)
{
  StudentList *found_student = get_student_by_id(head, student_id);
  for (int i = 0; i < 10; i++)
  {
    if (found_student->student.subjects->current_subject_list[i].subjectId == subject_id)
    {
      found_student->student.subjects->current_subject_list[i].grade = grade;
      return;
    }
  }
}

// Prints all subjects with the corresponding grades for a given student
void print_subjects_with_grades(Student *student)
{
  for (int i = 0; i < student->subjects->count; i++)
  {
    if (student->subjects->current_subject_list[i].subjectId != 0)
    {
      printf("%s\t\t%d\n", student->subjects->current_subject_list[i].name, student->subjects->current_subject_list[i].grade);
    }
  }
}

// Prints all students studying a given subject
void findStudentsBySubject(StudentList *head, int subject_id)
{
  StudentList *current = head;
  while (current != NULL)
  {
    for (int i = 0; i < current->student.subjects->count; i++)
    {
      if (current->student.subjects->current_subject_list[i].subjectId == subject_id)
      {
        printf("%s \n", current->student.name);
      }
    }
    current = current->next;
  }
}

#endif // _LIST_MY_PROJECT1_H