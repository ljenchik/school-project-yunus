#ifndef ARRAY_OF_SUBJECTS_H
#define ARRAY_OF_SUBJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max_number_of_subjects 10


typedef struct arrayList {
  int item_bytes;
  int count; // real length of the array
  int allocated_count; // max length of the array
  void *current_array_list; // a typeless reference
} ArrayList;

// Adding subject to array list with adding extra memory if needed
void add(ArrayList *array_list, void *subject) {
  int new_count = array_list->count + 1;
  if (new_count > array_list->allocated_count) {
    // allocates and copies, doubles the memory
    int new_allocated_count = array_list->allocated_count * 2;
    if (new_allocated_count == 0) {
      new_allocated_count = 1;
    }
    // ptr = (cast-type*) malloc(byte-size)
    void *new_array_list = malloc(new_allocated_count * array_list->item_bytes);
    if (array_list->current_array_list != NULL) {
      // void *memcpy(void *dest, const void * src, size_t n)
      // n is the nimber of bytes to be copied
      memcpy(new_array_list, array_list->current_array_list, array_list->count * array_list->item_bytes);
      free(array_list->current_array_list);
    }
    array_list->current_array_list = new_array_list;
    array_list->allocated_count = new_allocated_count;
  }
  memcpy(array_list->current_array_list + array_list->item_bytes * array_list->count, subject, array_list->item_bytes);
  array_list->count = array_list->count + 1;
}

// Getting a subject from the array_list
void *get(ArrayList *list, int index) {
  return (list->current_array_list + index * list->item_bytes);
}

#endif 