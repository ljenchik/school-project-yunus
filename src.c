#include "student.h"
#include "subject.h"
#include "teacher.h"

int main(void)

{
  // Initial data to start with
  printf("================= Add student ==============\n");
  StudentList *student_head = create_student_head();
  add_student(student_head, student_head);
  // Prompting user to add students as many as they want
  user_students_inputs(student_head);
  print_students(student_head);

  printf("================= Add subjects ==============\n");
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
  print_subjects(available_subjects);

  printf("================= Add teachers ==============\n");
  // Creating teachers
  TeacherList *teacher_head = createTeacherHead(available_subjects);
  add_teacher(teacher_head, teacher_head);
  user_teachers_inputs(teacher_head, available_subjects);
  print_teachers(teacher_head);

  while (1)
  {
    printf("Select one of the options:\n");
    printf("1. Add student\n");
    printf("2. Add subject\n");
    printf("3. Add teacher\n");
    printf("4. Assign subject to student\n");
    printf("5. Assign grade\n");
    printf("6. Find students by subject\n");
    printf("7. Find teacher by subject\n");
    printf("8. Find grades by student and subject\n");
    printf("0. Exit\n");

    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      user_students_inputs(student_head);
      print_students(student_head);
      break;
    case 2:
      user_subjects_inputs(available_subjects);
      print_subjects(available_subjects);
      break;
    case 3:
      user_teachers_inputs(teacher_head, available_subjects);
      print_teachers(teacher_head);
      break;
    case 4:
      user_subject_to_student(student_head, available_subjects);
      print_students(student_head);
      break;
    case 5:
      user_grade_to_student(student_head);
      print_subjects_with_grades(student_head);
      break;
    case 6:
      user_students_by_subject(student_head, available_subjects);
      break;
    case 7:
      user_find_teacher_by_subject(teacher_head, available_subjects);
      break;
    case 8:
      user_find_grade(student_head, available_subjects);
      break;
    case 0:
      printf("Exiting the program.\n");
      return 0;
    default:
      printf("Invalid choice. Try again.\n");
    }
  }
  free(available_subjects);

  return 0;
}
