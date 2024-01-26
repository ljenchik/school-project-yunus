#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max_number_of_subjects 10

#include "subject.h"
#include "teacher.h"
#include "student.h"

int main() 

 {
  // StudentList *student_head = create_student();
  // StudentList *new_student1 = create_student();
  // StudentList *new_student2 = create_student();
  
  // // Adding students to StudentList
  // add_student(student_head, student_head);
  // add_student(student_head, new_student1);
  // add_student(student_head, new_student2);

  ArrayList *available_subjects = malloc(sizeof(ArrayList));
  
  //Creating subjects
  // Subject *new_subject1 = createSubject();
  Subject new_subject2 = {1, "s1", 1, 1};

  add_subject(available_subjects, &new_subject2);

  // print_subject(new_subject1);
  // print_subject(new_subject2);

  print_subjects(available_subjects);

  // // Adding subject
  // add_subject_to_student(&(student_head->student), new_subject1);
  // add_subject_to_student(&(student_head->student), new_subject2);

  // // Creating teachers
  // Teacher *t1 = createTeacher();
  // Teacher *t2 = createTeacher();

  printf("=======================================\n");
  printf("=======================================\n");
  
  // print_students(student_head);

  printf("=======================================\n");
  printf("=======================================\n");

  // printf("Teacher id\tTeacher name\tSubject id\n");
  // print_teacher(t1);
  // print_teacher(t2);

  // printf("=======================================\n");
  // printf("=======================================\n");


  // add_grade(student_head, 1, 1, 98);

  // printf("Subject\t\tGrade\n");
  // print_subjects_with_grades(&student_head->student);


  // // Subject s = {1, "Math", 20, 5};
  // // ArrayList subjects = {sizeof(Subject), 0, 0, NULL};

  // // Subject s1 = {1, "English", 20, 5};

  // // add_subject(&subjects, &s);
  // // add_subject(&subjects, &s1);

  // // for(int i = 0; i < subjects.count; i++) {
  // //   Subject *s1 = get_subject_by_id(&subjects, i);
  // //   print_subject(s1);
  // // }
  


   return 0;
}