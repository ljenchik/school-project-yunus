#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "subject.h"
#include "teacher.h"
#include "student.h"

int main()

{

  StudentList *student_head = create_student_head();
  add_student(student_head, student_head);

  // Prompting user to add students
  user_students_inputs(student_head);

  // Printying all existing students
  print_students(student_head);

  // Creatina an array of all available subjects
  ArrayList *available_subjects = malloc(sizeof(ArrayList));

  // Creating and adding a new subject to available_subjects
  Subject *new_subject = createSubject(available_subjects);
  add_subject(available_subjects, new_subject);

  // Prompting user to add subjects
  user_subjects_inputs(available_subjects);

  // Printing all available subjects
  print_subjects(available_subjects);

  // Adding subject to a student
  user_subject_to_student(student_head, available_subjects);
  print_students(student_head);

  // // Creating teachers
  // TeacherList *teacher_head = createTeacher();
  // TeacherList *t1 = createTeacher();
  // TeacherList *t2 = createTeacher();

  // add_teacher(teacher_head, teacher_head);
  // add_teacher(teacher_head, t1);
  // add_teacher(teacher_head, t2);

  // print_teachers(teacher_head);

  // add_grade(student_head, 1, 1, 98);
  // add_grade(student_head, 1, 2, 86);

  // add_grade(student_head, 2, 2, 34);
  // add_grade(student_head, 3, 3, 100);

  // printf("Subject\t\tGrade\n");
  // print_subjects_with_grades(&student_head->student);
  // print_subjects_with_grades(&new_student1->student);
  // print_subjects_with_grades(&new_student2->student);

  // // Prints all students studying a given subject
  // printf("Enter a subject id to print all students who study this subject \n");
  // int students_by_subject;
  // scanf("%d", &students_by_subject);
  // findStudentsBySubject(student_head, students_by_subject);

  // // Finding a teacher by a specified subject id
  // printf("Teacher id\tName\t\tSubject id\n");
  // findTeacherForSubject(teacher_head, 3);

  // // Finding a grade for a given student and a given subject
  // findStudentGradeInSubject(student_head, 1, 2);

  return 0;
}