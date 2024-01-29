#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
      break;
    }
    printf("Student with id %d already exists. Enter a different student id \n", st_id);
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

void add_subject_to_student(StudentList *head, ArrayList *subjects, int student_id, int subject_id)
{
  StudentList *found_student = get_student_by_id(head, student_id);
  Subject *found_subject = get_subject_by_id(subjects, subject_id);
  if (found_student == NULL)
  {
    printf("Student with id %d does not exist \n", student_id);
    return;
  }
  else if (found_subject == NULL)
  {
    printf("Subject with id %d does not exist \n", subject_id);
    return;
  }
  else
  {
    add_subject(found_student->student.subjects, found_subject);
  }
}

// Add a grade to a given student to a given subject
void add_grade(StudentList *head, int student_id, int subject_id, int grade)
{
  StudentList *found_student = get_student_by_id(head, student_id);
  Subject *found_subject = get_subject_by_id(head->student.subjects, subject_id);
  if (found_student == NULL)
  {
    printf("Student with id %d does not exist \n", student_id);
    return;
  }
  else if (found_subject == NULL)
  {
    printf("Subject with id %d was not assigned to the student with id %d \n", subject_id, student_id);
    return;
  }
  else
    for (int i = 0; i < found_student->student.subjects->count; i++)
    {
      if (found_student->student.subjects->current_subject_list[i].subjectId == subject_id)
      {
        found_student->student.subjects->current_subject_list[i].grade = grade;
        return;
      }
    }
}

// Prints all subjects with the corresponding grades for a given student
void print_subjects_with_grades(StudentList *head)
{
  StudentList *current = head;
  printf("Student name\t\tSubject name\tGrade\n");
  while (current != NULL)
  {
    for (int i = 0; i < current->student.subjects->count; i++)
    {
      printf("\t%s\t\t%s\t\t%d\n", current->student.name, current->student.subjects->current_subject_list[i].name, current->student.subjects->current_subject_list[i].grade);
    }
    current = current->next;
  }

  printf("\n");
}

// Prints all students studying a given subject
void findStudentsBySubject(StudentList *head, ArrayList *subjects, int subject_id)
{
  StudentList *current = head;
  Subject *found_subject = get_subject_by_id(subjects, subject_id);
  if (found_subject == NULL)
  {
    printf("Subject with id %d was not found \n", subject_id);
    return;
  }
  else
  {
    while (current != NULL)
    {
      for (int i = 0; i < current->student.subjects->count; i++)
      {
        if (current->student.subjects->current_subject_list[i].subjectId == subject_id)
        {
          print_student(current);
        }
      }
      current = current->next;
    }
  }
}

void findStudentGradeInSubject(StudentList *head, ArrayList *subjects, int student_id, int subjectId)
{
  StudentList *found_student = get_student_by_id(head, student_id);
  Subject *found_subject = get_subject_by_id(subjects, student_id);
  for (int i = 0; i < found_student->student.subjects->count; i++)
  {
    if (found_student->student.subjects->current_subject_list[i].subjectId == subjectId)
    {
      printf("Student %s in a subject %s got a grade %d \n",
             found_student->student.name,
             found_subject->name,
             found_student->student.subjects->current_subject_list[i].grade);
      return;
    }
  }
}

// User inputs
void user_students_inputs(StudentList *head)
{
  bool add_more_students = true;
  char user_response = 'y';
  while (add_more_students == true)
  {
    printf("Do you want to add another student? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      StudentList *new_student = create_student(head);
      add_student(head, new_student);
    }
  }
}

// User inputs for assigning a subject to a student
void user_subject_to_student(StudentList *head, ArrayList *subjects)
{
  bool add_more = true;
  char user_response = 'y';

  while (add_more == true)
  {
    printf("Do you want to assign a subject to a student? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      int st_id;
      int sub_id;
      printf("Enter a student id \n");
      scanf("%d", &st_id);
      printf("Enter a subject id \n");
      scanf("%d", &sub_id);
      add_subject_to_student(head, subjects, st_id, sub_id);
    }
  }
}

// User inputs for finding students by subject id
void user_students_by_subject(StudentList *head, ArrayList *subjects)
{
  bool add_more = true;
  char user_response = 'y';
  int sub_id;
  while (add_more == true)
  {
    printf("Do you want to print students who study a specified subject? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      printf("Enter a subject id \n");
      scanf("%d", &sub_id);
      findStudentsBySubject(head, subjects, sub_id);
    }
  }
}

// User inputs for grades
void user_grade_to_student(StudentList *head)
{
  bool add_more = true;
  char user_response = 'y';
  int st_id;
  int sub_id;
  int grade;

  while (add_more == true)
  {
    printf("Do you want to assign a grade for a subject to a student? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      printf("Enter a student id \n");
      scanf("%d", &st_id);
      printf("Enter a subject id \n");
      scanf("%d", &sub_id);
      printf("Enter a grade\n");
      scanf("%d", &grade);
      add_grade(head, st_id, sub_id, grade);
    }
  }
}

// User inputs to get grade for a given subject and a student
void user_find_grade(StudentList *head, ArrayList *subjects)
{
  bool add_more = true;
  int sub_id;
  int st_id;
  char user_response = 'y';
  while (add_more == true)
  {
    printf("Do you want to print a grade for a given subject and a student? y/n \n");
    scanf(" %c", &user_response);
    if (user_response != 'y')
    {
      break;
    }
    else
    {
      printf("Enter a student id \n");
      scanf("%d", &st_id);

      printf("Enter a subject id \n");
      scanf("%d", &sub_id);

      findStudentGradeInSubject(head, subjects, st_id, sub_id);
    }
  }
}

#endif // _LIST_MY_PROJECT1_H