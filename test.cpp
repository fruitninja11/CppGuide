#include <stdio.h>
#include <stdlib.h>
int *func(int a) {
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int i;
    for (i=0; i<10; i++) {
        array[i] = a;
    }
    return array;
}
int main() {
    int *array = func(3);
    printf("%d\n", array[7]);
}