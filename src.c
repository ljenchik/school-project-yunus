#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_number_of_subjects 10

#include "subject.h"
#include "teacher.h"
#include "student.h"

int main()

{
  StudentList *student_head = create_student();
  StudentList *new_student1 = create_student();
  StudentList *new_student2 = create_student();

  // Adding students to StudentList
  add_student(student_head, student_head);
  add_student(student_head, new_student1);
  add_student(student_head, new_student2);

  // Printying all existing students
  print_students(student_head);

  ArrayList *available_subjects = malloc(sizeof(ArrayList));

  Subject *new_subject1 = createSubject();
  Subject *new_subject2 = createSubject();
  Subject *new_subject3 = createSubject();

  add_subject(available_subjects, new_subject1);
  add_subject(available_subjects, new_subject2);
  add_subject(available_subjects, new_subject3);

  print_subjects(available_subjects);

  // Adding subject
  add_subject_to_student(&(student_head->student), new_subject1);
  add_subject_to_student(&(student_head->student), new_subject2);
  add_subject_to_student(&(student_head->student), new_subject3);
  add_subject_to_student(&(new_student1->student), new_subject2);
  add_subject_to_student(&(new_student2->student), new_subject3);
  add_subject_to_student(&(new_student2->student), new_subject2);

  print_students(student_head);

  // Creating teachers
  TeacherList *teacher_head = createTeacher();
  TeacherList *t1 = createTeacher();
  TeacherList *t2 = createTeacher();

  add_teacher(teacher_head, teacher_head);
  add_teacher(teacher_head, t1);
  add_teacher(teacher_head, t2);

  print_teachers(teacher_head);

  add_grade(student_head, 1, 1, 98);
  add_grade(student_head, 1, 2, 86);

  add_grade(student_head, 2, 2, 34);
  add_grade(student_head, 3, 3, 100);

  printf("Subject\t\tGrade\n");
  print_subjects_with_grades(&student_head->student);
  print_subjects_with_grades(&new_student1->student);
  print_subjects_with_grades(&new_student2->student);

  // Prints all students studying a given subject
  printf("Enter a subject id to print all students who study this subject \n");
  int students_by_subject;
  scanf("%d", &students_by_subject);
  findStudentsBySubject(student_head, students_by_subject);

  // Finding a teacher by a specified subject id

  printf("Teacher id\tName\t\tSubject id\n");
  findTeacherForSubject(teacher_head, 3);

  // Finding a grade for a given student and a given subject
  findStudentGradeInSubject(student_head, 1, 2);

  return 0;
}