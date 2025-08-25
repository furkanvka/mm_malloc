#pragma once

#include <unistd.h> 
#include <stddef.h>
#include <stdint.h> 


typedef struct meta_data{
  size_t size;
  int free;
  struct meta_data *next;
}meta_data;

void *mymalloc(unsigned int _size);

unsigned int myfree(void *ptr);