
#include "my_malloc.h"

#include <unistd.h>




meta_data *head = NULL;

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
