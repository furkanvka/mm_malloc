#include "my_malloc.h"
#include <stdio.h>


int main() {


    int* list = (int*)mymalloc(sizeof(int) * 5);

    for (int i = 0; i < 5; i++)
    {
        *(list+i) = i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(list+i));
    }

    printf("\n");

    
    
}