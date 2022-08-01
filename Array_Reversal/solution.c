# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main() {
    int num, *arr, i, temp;
    scanf("%d", &num);

    // init array
    arr = (int*) malloc(num * sizeof(int));

    // input
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    for(i = 0; i < num/2; i++){
        temp = *(arr + i);
        *(arr + i) = *(arr + num-1 - i);
        *(arr + num-1 - i) = temp;
    }

    // output
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}