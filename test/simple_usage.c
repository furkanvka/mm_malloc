#include "my_malloc.h"
#include <stdio.h>

int main() {
    int* list = (int*)mymalloc(sizeof(int) * 5);
    
    if (list == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        *(list + i) = i;
    }
    
    printf("Bellekteki degerler:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(list + i)); 
    }
    printf("\n");

    myfree(list);

    return 0;
}