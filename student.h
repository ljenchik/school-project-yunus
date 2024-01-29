#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "subject.h"
#define true 1
#define false 0

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
// Creating the first student in a list
StudentList *create_student_head()
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

// Checking if student id is unique
bool is_id_unique(StudentList *head, int student_id)
{
  StudentList *current = head;
  while (current != NULL)
  {
    if (current->student.id == student_id)
    {
      return false;
    }
    current = current->next;
  }
  return true;
}

StudentList *create_student(StudentList *head)
{
  int st_id;
  bool st_id_unique = false;

  StudentList *new_student = (StudentList *)malloc(sizeof(StudentList));
  new_student->student.subjects = (ArrayList *)malloc(sizeof(ArrayList));
  memset(new_student->student.subjects, 0, sizeof(ArrayList));

  while (st_id_unique != true)
  {
    printf("Enter student id: ");
    scanf("%d", &st_id);
    if (is_id_unique(head, st_id) == true)
    {
      new_student->student.id = st_id;
      st_id_unique = true;
    }
    printf("Student with id %d already exists. Enter different student id \n", st_id);
  }
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
      printf("%s\t\t%s\t\t%d\n", student->name, student->subjects->current_subject_list[i].name, student->subjects->current_subject_list[i].grade);
    }
  }
  printf("\n");
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

void findStudentGradeInSubject(StudentList *head, int student_id, int subjectId)
{
  StudentList *found_student = get_student_by_id(head, student_id);
  for (int i = 0; i < found_student->student.subjects->count; i++)
  {
    if (found_student->student.subjects->current_subject_list[i].subjectId == subjectId)
    {
      printf("%d \n", found_student->student.subjects->current_subject_list[i].grade);
      return;
    }
  }
}

// User inputs
void user_inputs()
{
}

#endif // _LIST_MY_PROJECT1_H