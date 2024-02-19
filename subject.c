#include "subject.h"

// Checking if subject id is unique
bool is_subject_id_unique(ArrayList *subjects, int subject_id)
{
  for (int i = 0; i < subjects->count; i++)
  {
    if (subjects->current_subject_list[i].subjectId == subject_id)
    {
      return false;
    }
  }
  return true;
}

// Creating a subject
Subject *create_subject(ArrayList *subjects)
{
  int sub_id;
  bool sub_id_unique = false;

  Subject *new_subject = (Subject *)malloc(sizeof(Subject));
  if (new_subject == NULL)
  {
    printf("Memory allocation for subject failed\n");
    exit(EXIT_FAILURE);
  }

  while (sub_id_unique != true)
  {
    printf("Enter Subject id: ");
    scanf("%d", &sub_id);
    if (is_subject_id_unique(subjects, sub_id) == true)
    {
      sub_id_unique = true;
      new_subject->subjectId = sub_id;
    }
    else
    {
      sub_id_unique = false;
      printf("Subject with id %d already exists. Enter a different subject id \n", sub_id);
    }
  }

  printf("Enter subject name: ");
  scanf("%s", new_subject->name);

  return new_subject;
}

// Printing subject
void print_subject(Subject *subject)
{
  printf("Subject id\tSubject name\n");
  printf("\t%d\t%s\t\t\n", subject->subjectId, subject->name);
  printf("\n");
}

// Printing subject
void print_subjects(ArrayList *subjects)
{
  printf("Subject id\tSubject name\n");
  for (int i = 0; i < subjects->count; i++)
  {
    printf("\t%d\t%s\t\t\n", subjects->current_subject_list[i].subjectId, subjects->current_subject_list[i].name);
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

// User inputs
void user_subjects_inputs(ArrayList *subjects)
{
  bool add_more_subjects = true;
  char user_response;
  while (add_more_subjects == true)
  {
    printf("Do you want to add another subject? y/n \n");
    scanf(" %c", &user_response);
    if (user_response == 'n')
    {
      add_more_subjects = false;
    }
    else if (user_response == 'y')
    {
      Subject *new_subject = create_subject(subjects);
      add_subject(subjects, new_subject);
    }
    else
    {
      printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
  }
}
