#include "student.h"
#include "subject.h"
#include "teacher.h"

int main(void)

{
  StudentList *student_head = create_student_head();
  add_student(student_head, student_head);

  // Prompting user to add students as many as they want
  user_students_inputs(student_head);

  // Printying all existing students
  print_students(student_head);

  // Creating an array of subjects
  ArrayList *available_subjects = malloc(sizeof(ArrayList));
  if (available_subjects == NULL)
  {
    printf("Memory allocation for available subjects failed\n");
    exit(EXIT_FAILURE);
  }

  // Creating and adding a new subject to available_subjects
  Subject *new_subject = create_subject(available_subjects);
  add_subject(available_subjects, new_subject);

  // Prompting user to add subjects
  user_subjects_inputs(available_subjects);

  // Printing all available subjects
  print_subjects(available_subjects);

  // Adding subject to a student
  user_subject_to_student(student_head, available_subjects);
  print_students(student_head);

  // Creating teachers
  TeacherList *teacher_head = createTeacherHead(available_subjects);
  add_teacher(teacher_head, teacher_head);
  user_teachers_inputs(teacher_head, available_subjects);
  print_teachers(teacher_head);

  printf("===============================================================\n");
  printf("===============================================================\n");

  print_students(student_head);
  print_subjects(available_subjects);
  print_teachers(teacher_head);

  // Adding grades
  user_grade_to_student(student_head);
  // Printing all students with the corresponding subjects and grades
  print_subjects_with_grades(student_head);

  // Prints all students studying a given subject
  user_students_by_subject(student_head, available_subjects);

  // Finding a teacher by a specified subject id
  user_find_teacher_by_subject(teacher_head, available_subjects);

  // Finding a grade for a given student and a given subject
  user_find_grade(student_head, available_subjects);

  free(available_subjects);

  return 0;
}
