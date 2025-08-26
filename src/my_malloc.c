#include "my_malloc.h"

#include <unistd.h>


meta_data *head = NULL;

static meta_data* find_previous_block(meta_data *current_meta) {
    meta_data* prev = NULL;
    meta_data* tail = head;
    while (tail != current_meta)
    {
        prev = tail;
        tail = tail->next; 
    }

    return prev;
}

void *mymalloc(unsigned int size) {
    meta_data *current = head;

    if (head == NULL) {
        void *block = sbrk(sizeof(meta_data) + size);
        if (block == (void *) -1) {
            return NULL;
        }

        meta_data *meta = (meta_data *)block;
        meta->size = size;
        meta->free = 0;
        meta->next = NULL;

        head = meta;

        return (void *)(meta + 1);
    }

    while (current != NULL) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (void *)(current + 1);
        }
        current = current->next;
    }

    void *block = sbrk(sizeof(meta_data) + size);
    if (block == (void *) -1) {
        return NULL;
    }

    meta_data *meta = (meta_data *)block;
    meta->size = size;
    meta->free = 0;
    meta->next = NULL;

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = meta;

    return (void *)(meta + 1);
}


unsigned int myfree(void *ptr) {
    if (ptr == NULL) {
        return 1;
    }

    meta_data *current = ((meta_data *)ptr) - 1;
    current->free = 1;
    
    meta_data *prev = find_previous_block(current);

    if (prev && prev->free) {
        prev->size += current->size + sizeof(meta_data);
        prev->next = current->next;
        current = prev;
    }

    if (current->next && current->next->free) {
        current->size += current->next->size + sizeof(meta_data);
        current->next = current->next->next;
    }
    
    return 0; // Başarılı
}