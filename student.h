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
  char *name;
  ArrayList *subjects;
} Student;

typedef struct student_list
{
  Student student;
  struct student_list *next;
} StudentList;

// Creating the first student in a list
StudentList *create_student_head(void);

// Checking if student id is unique
bool is_id_unique(StudentList *head, int student_id);

StudentList *create_student(StudentList *head);

// Printing a given student with all info
void print_student(StudentList *student);

// Adding a new student
void add_student(StudentList *head, StudentList *new_student);

// Printing all students
void print_students(StudentList *head);

// Getting a student by id
StudentList *get_student_by_id(StudentList *head, int student_id);

int add_subject_to_student(StudentList *head, ArrayList *subjects, int student_id, int subject_id);

// Add a grade to a given student to a given subject
int add_grade(StudentList *head, int student_id, int subject_id, int grade);

// Prints all subjects with the corresponding grades for a given student
void print_subjects_with_grades(StudentList *head);

// Prints all students studying a given subject
void find_students_by_subject(StudentList *head, ArrayList *subjects, int subject_id);

int find_student_grade_by_subject(StudentList *head, ArrayList *subjects, int student_id, int subjectId);

// User inputs
void user_students_inputs(StudentList *head);

// User inputs for assigning a subject to a student
void user_subject_to_student(StudentList *head, ArrayList *subjects);

// User inputs for finding students by subject id
void user_students_by_subject(StudentList *head, ArrayList *subjects);

// User inputs for grades
void user_grade_to_student(StudentList *head);

// User inputs to get grade for a given subject and a student
void user_find_grade(StudentList *head, ArrayList *subjects);

#endif
